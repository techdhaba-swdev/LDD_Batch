#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "/dev/calculator"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");

static int major;
static int value1, value2;
static char operation;

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    int result = 0;

    switch (operation) {
        case '+':
            result = value1 + value2;
            break;
        case '-':
            result = value1 - value2;
            break;
        case '*':
            result = value1 * value2;
            break;
        case '/':
            if (value2 == 0) {
                printk(KERN_ALERT "Calculator: Division by zero\n");
                return -EINVAL;
            }
            result = value1 / value2;
            break;
        default:
            printk(KERN_ALERT "Calculator: Invalid operation\n");
            return -EINVAL;
    }

    copy_to_user(buffer, &result, sizeof(int));
    printk(KERN_INFO "Result sent to user space: %d\n", result);
    return sizeof(int);
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    if (*offset == 0) {
        copy_from_user(&value1, buffer, sizeof(int));
        printk(KERN_INFO "First value received from user space: %d\n", value1);
        *offset += sizeof(int);
    } else if (*offset == sizeof(int)) {
        copy_from_user(&value2, buffer, sizeof(int));
        printk(KERN_INFO "Second value received from user space: %d\n", value2);
        *offset += sizeof(int);
    } else if (*offset == 2 * sizeof(int)) {
        copy_from_user(&operation, buffer, sizeof(char));
        printk(KERN_INFO "Operation received from user space: %c\n", operation);
        *offset += sizeof(char);
    }

    return length;
}

static struct file_operations fops = {
    .open = device_open,
    .write = device_write, 
    .read = device_read,
    .release = device_release,
};

static int __init calculator_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Calculator: Device registered with major number %d\n", major);
    return 0;
}

static void __exit calculator_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Calculator: Device unregistered\n");
}

module_init(calculator_init);
module_exit(calculator_exit);




