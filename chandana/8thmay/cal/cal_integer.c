#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "cal_integer"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Chandana");

static int major;
static int value1, value2;

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    // Concatenate value1 and value2 into a single integer
    int result = (value1 << 16) | (value2 & 0xFFFF);
    copy_to_user(buffer, &result, sizeof(int));
    printk(KERN_INFO "Values sent to user space: %d, %d\n", value1, value2);
    return sizeof(int);
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    // Separate the two integers from the input
    int input_values;
    copy_from_user(&input_values, buffer, sizeof(int));

    // Extract value1 and value2
    value1 = input_values >> 16;
    value2 = input_values & 0xFFFF;
    printk(KERN_INFO "Values received from user space: %d, %d\n", value1, value2);
    return sizeof(int);
}

static ssize_t device_read_result(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    // Perform the operation based on the user's choice
    int operation;
    copy_from_user(&operation, buffer, sizeof(int));

    int result;
    switch (operation) {
        case 0: // Addition
            result = value1 + value2;
            break;
        case 1: // Subtraction
            result = value1 - value2;
            break;
        case 2: // Multiplication
            result = value1 * value2;
            break;
        case 3: // Division
            result = value1 / value2;
            break;
        default:
            printk(KERN_ALERT "Invalid operation\n");
            return -EINVAL;
    }

    copy_to_user(buffer, &result, sizeof(int));
    printk(KERN_INFO "Result sent to user space: %d\n", result);
    return sizeof(int);
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

static int __init cal_integer_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Double Integer: Device registered with major number %d\n", major);
    return 0;
}

static void __exit cal_integer_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Double Integer: Device unregistered\n");
}

module_init(cal_integer_init);
module_exit(cal_integer_exit);
