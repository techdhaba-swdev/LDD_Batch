#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define DEVICE_NAME "buffer_structure_add"
#define NUMBERS_COUNT 10

typedef struct {
    int numbers[NUMBERS_COUNT];
    char operation;
} CalculationRequest;

static char *device_memory;
static int major_number;

static int my_device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "my_device: open\n");
    return 0;
}

static int my_device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "my_device: release\n");
    return 0;
}

static ssize_t my_device_write(struct file *file, const char __user *buffer, size_t len, loff_t *ppos) {
    CalculationRequest req;

    if (len != sizeof(CalculationRequest)) {
        return -EINVAL;
    }

    if (copy_from_user(&req, buffer, len)) {
        return -EFAULT;
    }

    printk(KERN_INFO "Received operation: %c\n", req.operation);
   
    int result = 0;
    for (int i = 0; i < NUMBERS_COUNT; ++i) {
        if (req.operation == '+') {
            result += req.numbers[i];
        } else if (req.operation == '-') {
            result -= req.numbers[i];
        } else {
            return -EINVAL;
        }
    }

    memcpy(device_memory, &result, sizeof(int));
    printk(KERN_INFO "Processed result: %d\n", result);

    return len;
}

static ssize_t my_device_read(struct file *file, char __user *buffer, size_t len, loff_t *ppos) {
    if (copy_to_user(buffer, device_memory, sizeof(int))) {
        return -EFAULT;
    }
    return sizeof(int);
}

static const struct file_operations my_device_fops = {
    .owner = THIS_MODULE,
    .open = my_device_open,
    .release = my_device_release,
    .write = my_device_write,
    .read = my_device_read,
};

static int __init my_device_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &my_device_fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number);
        return major_number;
    }

    device_memory = kmalloc(sizeof(int), GFP_KERNEL);
    if (!device_memory) {
        unregister_chrdev(major_number, DEVICE_NAME);
        return -ENOMEM;
    }
    printk(KERN_INFO "my_device: registered with major number %d\n", major_number);
    printk(KERN_INFO "my_device: memory allocated at %p\n", device_memory);
    return 0;
}

static void __exit my_device_exit(void) {
    kfree(device_memory);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "my_device: unregistered\n");
}

module_init(my_device_init);
module_exit(my_device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Example Device Driver with structure buffer for addition/subtraction");



