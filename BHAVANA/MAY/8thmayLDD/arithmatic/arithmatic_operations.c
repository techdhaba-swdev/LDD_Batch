#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "arithmetic_operations"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");

static int major;
static int operand1, operand2;
static int result;

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    printk(KERN_INFO "Result sent to user space: %d\n", result);
    return scnprintf(buffer, length, "%d\n", result);
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    sscanf(buffer, "%d %d", &operand1, &operand2);
    printk(KERN_INFO "Values received from user space: %d %d\n", operand1, operand2);
    return length;
}

static long do_sum(void) {
    result = operand1 + operand2;
    return result;
}

static long do_subtraction(void) {
    result = operand1 - operand2;
    return result;
}

static long do_multiplication(void) {
    result = operand1 * operand2;
    return result;
}

static long do_division(void) {
    if (operand2 != 0)
        result = operand1 / operand2;
    else
        result = 0;  // Division by zero
    return result;
}

static long perform_operation(int operation) {
    switch (operation) {
        case 0: return do_sum();
        case 1: return do_subtraction();
        case 2: return do_multiplication();
        case 3: return do_division();
        default: return -1; // Invalid operation
    }
}

static ssize_t device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    long res = perform_operation(cmd);
    return res;
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
    .unlocked_ioctl = device_ioctl,
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
