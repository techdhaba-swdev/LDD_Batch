#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "addition"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");

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
    int sum = value1 + value2;
    copy_to_user(buffer, &sum, sizeof(int));
    printk(KERN_INFO "Sum sent to user space: %d\n", sum);
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
    }
    return length;
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

static int __init addition_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Addition: Device registered with major number %d\n", major);
    return 0;
}

static void __exit addition_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Addition: Device unregistered\n");
}

module_init(addition_init);
module_exit(addition_exit);




