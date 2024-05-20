#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "add_two_numbers"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kiruthiga");

static int major;
static int num1, num2, result;

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    copy_to_user(buffer, &result, sizeof(int));
    printk(KERN_INFO "Result sent to user space: %d\n", result);
    return sizeof(int);
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    // Copy the two numbers from the user space buffer
    copy_from_user(&num1, buffer, sizeof(int));
    copy_from_user(&num2, buffer + sizeof(int), sizeof(int));

    // Add the two numbers together and store the result
    result = num1 + num2;
    printk(KERN_INFO "Received numbers from user space: %d and %d, Result: %d\n", num1, num2, result);
    return sizeof(int);
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

static int __init add_two_numbers_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Add Two Numbers: Device registered with major number %d\n", major);
    return 0;
}

static void __exit add_two_numbers_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Add Two Numbers: Device unregistered\n");
}

module_init(add_two_numbers_init);
module_exit(add_two_numbers_exit);


