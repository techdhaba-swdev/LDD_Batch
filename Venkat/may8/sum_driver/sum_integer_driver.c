#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "sum_integer_driver"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");

static int major;
static int value1, value2, sum;

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
    bytes_not_copied = copy_to_user(buffer, &sum, sizeof(int));
    if (bytes_not_copied == 0) {
        printk(KERN_INFO "Sum sent to user space: %d\n", sum);
    } else {
        printk(KERN_WARNING "Failed to send sum to user space\n");
    }
    return sizeof(int) - bytes_not_copied;
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    ssize_t bytes_not_copied;
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

    printk(KERN_INFO "Values received from user space: %d, %d\n", value1, value2);
    sum = value1 + value2; // Sum the values
    return 2 * sizeof(int) - bytes_not_copied; // Return the size of two integers minus any bytes not copied
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

static int __init sum_integer_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Sum Integer: Device registered with major number %d\n", major);
    return 0;
}

static void __exit sum_integer_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Sum Integer: Device unregistered\n");
}

module_init(sum_integer_init);
module_exit(sum_integer_exit);
