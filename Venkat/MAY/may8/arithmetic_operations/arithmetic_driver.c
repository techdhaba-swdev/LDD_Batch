#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "arithmetic"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");

static int major;
static int value1, value2, result;
static char operation; // To store the operation (+, -, *, /)

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    ssize_t bytes_not_copied;
    bytes_not_copied = copy_to_user(buffer, &result, sizeof(int));
    if (bytes_not_copied == 0) {
        printk(KERN_INFO "Result sent to user space: %d\n", result);
    } else {
        printk(KERN_WARNING "Failed to send result to user space\n");
    }
    return sizeof(int) - bytes_not_copied;
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    ssize_t bytes_not_copied;

    // Read the two input values from user space
    bytes_not_copied = copy_from_user(&value1, buffer, sizeof(int));
    if (bytes_not_copied != 0) {
        printk(KERN_WARNING "Failed to receive first value from user space\n");
        return -EFAULT;
    }

    bytes_not_copied = copy_from_user(&value2, buffer + sizeof(int), sizeof(int));
    if (bytes_not_copied != 0) {
        printk(KERN_WARNING "Failed to receive second value from user space\n");
        return -EFAULT;
    }

    // Read the operation (+, -, *, /) from user space
    // Ensure the offset is correct: 2 * sizeof(int)
    bytes_not_copied = copy_from_user(&operation, buffer + 2 * sizeof(int), sizeof(char));
    if (bytes_not_copied != 0) {
        printk(KERN_WARNING "Failed to receive operation from user space\n");
        return -EFAULT;
    }

    // Perform the requested arithmetic operation
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
            if (value2 != 0) {
                result = value1 / value2;
            } else {
                printk(KERN_WARNING "Division by zero\n");
                return -EINVAL;
            }
            break;
        default:
            printk(KERN_WARNING "Invalid operation: %c\n", operation);
            return -EINVAL;
    }

    printk(KERN_INFO "Result calculated: %d\n", result);
    return length; // Return the number of bytes written
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

static int __init arithmetic_operations_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Arithmetic Operations: Device registered with major number %d\n", major);
    return 0;
}

static void __exit arithmetic_operations_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Arithmetic Operations: Device unregistered\n");
}

module_init(arithmetic_operations_init);
module_exit(arithmetic_operations_exit);
