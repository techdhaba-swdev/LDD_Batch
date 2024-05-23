#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "operation_device"

// Define a structure to hold the operation data
struct operation {
    int num1;
    int num2;
    char operator;
    int result;
};

static int major_num;

static struct operation op;

static int device_open(struct inode *inode, struct file *file) {
    try_module_get(THIS_MODULE);
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    module_put(THIS_MODULE);
    return 0;
}

static ssize_t device_write(struct file *file, const char *buffer, size_t length, loff_t *offset) {
    if (copy_from_user(&op, buffer, sizeof(struct operation))) {
        return -EFAULT;
    }

    switch (op.operator) {
        case '+':
            op.result = op.num1 + op.num2;
            break;
        case '-':
            op.result = op.num1 - op.num2;
            break;
        default:
            printk(KERN_ALERT "Unsupported operation: %c\n", op.operator);
            return -EINVAL;
    }

    return length;
}

static ssize_t device_read(struct file *file, char *buffer, size_t length, loff_t *offset) {
    if (copy_to_user(buffer, &op, sizeof(struct operation))) {
        return -EFAULT;
    }

    return sizeof(struct operation);
}

static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
    .write = device_write,
    .read = device_read,
};

static int __init operation_init(void) {
    major_num = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_num < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_num;
    }
    printk(KERN_INFO "Registered correctly with major number %d\n", major_num);
    return 0;
}

static void __exit operation_exit(void) {
    unregister_chrdev(major_num, DEVICE_NAME);
    printk(KERN_INFO "Unregistered\n");
}

module_init(operation_init);
module_exit(operation_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple operation module with struct");
