#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "sum"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");

static int major;
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
    copy_to_user(buffer, &result, sizeof(int));
    printk(KERN_INFO "Result sent to user space: %d\n", result);
    return sizeof(int);
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    int num1, num2;
    copy_from_user(&num1, buffer, sizeof(int));
    copy_from_user(&num2, buffer + sizeof(int), sizeof(int));
    result = num1 + num2;
    printk(KERN_INFO "Numbers received from user space: %d and %d\n", num1, num2);
    return sizeof(int);
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

static int __init add_numbers_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Add Numbers: Device registered with major number %d\n", major);
    return 0;
}

static void __exit add_numbers_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Add Numbers: Device unregistered\n");
}

module_init(add_numbers_init);
module_exit(add_numbers_exit);
