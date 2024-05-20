#include <linux/module.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define DEVICE_NAME "char_device"
#define BUF_LEN 80

static int major;
static char *device_buffer;
static int buffer_pointer = 0;
static wait_queue_head_t queue;
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

static ssize_t device_read(struct file *file, char __user *buffer, size_t length, loff_t *offset) {
    int num1, num2;
    if (copy_from_user(&num1, buffer, sizeof(int)) || copy_from_user(&num2, buffer + sizeof(int), sizeof(int)))
        return -EFAULT;
    int sum = num1 + num2;
    int diff = num1 - num2;

    // Store the result in device_buffer
    snprintf(device_buffer, BUF_LEN, "Sum: %d, Difference: %d", sum, diff);

    return strlen(device_buffer);
}

static ssize_t device_write(struct file *file, const char __user *buffer, size_t length, loff_t *offset) {
    

    return length;
}

static unsigned int device_poll(struct file *file, poll_table *wait) {
    unsigned int mask = 0;

    poll_wait(file, &queue, wait);

    if (buffer_pointer > 0) mask |= POLLIN | POLLRDNORM;
    if (buffer_pointer < BUF_LEN) mask |= POLLOUT | POLLWRNORM;

    return mask;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
    .poll = device_poll,
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

    init_waitqueue_head(&queue);

    printk(KERN_INFO "I was assigned major number %d. To talk to\n", major);
    printk(KERN_INFO "the driver, create a dev file with\n");
    printk(KERN_INFO "'mknod /dev/%s c %d 0'.\n", DEVICE_NAME, major);
    return 0;
}

static void __exit device_exit(void) {
    kfree(device_buffer);
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Device unregistered\n");
}

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("techdhaba");
MODULE_DESCRIPTION("A simple example character device driver");
