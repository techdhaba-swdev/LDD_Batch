#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/wait.h>
#include <linux/sched.h>

#define DEVICE_NAME "calcul_device"
#define BUF_LEN 80

static int major;
static char *device_buffer;
static char *calc_buffer;
static struct task_struct *calc_thread;
static wait_queue_head_t queue;
static int data_ready = 0;
static int result;
static int is_open = 0;

static int device_open(struct inode *inode, struct file *file) {
    if (is_open) return -EBUSY;
    is_open++;
    try_module_get(THIS_MODULE);
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    is_open--;
    module_put(THIS_MODULE);
    return 0;
}

static int parse_and_calculate(const char *expression, int *result) {
    int a, b;
    char op;

    if (sscanf(expression, "%d %c %d", &a, &op, &b) != 3) {
        return -EINVAL;
    }

    switch (op) {
        case '+':
            *result = a + b;
            break;
        case '-':
            *result = a - b;
            break;
        case '*':
            *result = a * b;
            break;
        case '/':
            if (b == 0) return -EINVAL;
            *result = a / b;
            break;
        default:
            return -EINVAL;
    }

    return 0;
}

static ssize_t device_read(struct file *file, char __user *buffer, size_t length, loff_t *offset) {
    int bytes_read = 0;

    if (*offset >= BUF_LEN) return 0;
    if (*offset + length > BUF_LEN) length = BUF_LEN - *offset;

    if (copy_to_user(buffer, device_buffer + *offset, length)) return -EFAULT;

    *offset += length;
    bytes_read = length;

    return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *buffer, size_t length, loff_t *offset) {
    if (length >= BUF_LEN) return -EINVAL;

    if (copy_from_user(calc_buffer, buffer, length)) return -EFAULT;
    calc_buffer[length] = '\0';

    data_ready = 1;
    wake_up_interruptible(&queue);

    return length;
}

static int calc_thread_fn(void *data) {
    while (!kthread_should_stop()) {
        wait_event_interruptible(queue, data_ready);

        if (data_ready) {
            if (parse_and_calculate(calc_buffer, &result) == 0) {
                snprintf(device_buffer, BUF_LEN, "%d\n", result);
            } else {
                snprintf(device_buffer, BUF_LEN, "Error\n");
            }
            data_ready = 0;
        }
    }
    return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
};

static int __init device_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }

    device_buffer = kmalloc(BUF_LEN, GFP_KERNEL);
    if (!device_buffer) {
        unregister_chrdev(major, DEVICE_NAME);
        return -ENOMEM;
    }

    calc_buffer = kmalloc(BUF_LEN, GFP_KERNEL);
    if (!calc_buffer) {
        kfree(device_buffer);
        unregister_chrdev(major, DEVICE_NAME);
        return -ENOMEM;
    }

    init_waitqueue_head(&queue);
    data_ready = 0;

    calc_thread = kthread_run(calc_thread_fn, NULL, "calc_thread");
    if (IS_ERR(calc_thread)) {
        kfree(device_buffer);
        kfree(calc_buffer);
        unregister_chrdev(major, DEVICE_NAME);
        return PTR_ERR(calc_thread);
    }

    printk(KERN_INFO "I was assigned major number %d. To talk to\n", major);
    printk(KERN_INFO "the driver, create a dev file with\n");
    printk(KERN_INFO "'mknod /dev/%s c %d 0'.\n", DEVICE_NAME, major);
    return 0;
}

static void __exit device_exit(void) {
    kthread_stop(calc_thread);
    kfree(device_buffer);
    kfree(calc_buffer);
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Device unregistered\n");
}

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RPS");
MODULE_DESCRIPTION("A simple calculator character device driver with kernel thread");
