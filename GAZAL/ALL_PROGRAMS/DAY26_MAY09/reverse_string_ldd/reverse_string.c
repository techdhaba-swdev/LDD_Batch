#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "reverse_string"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");

static int major;
static char value[100] = {0}; // Assuming a maximum string length of 100 characters

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    size_t bytes_to_copy = min(length, strlen(value)); // Calculate the number of bytes to copy
    if (copy_to_user(buffer, value, bytes_to_copy)) {
        return -EFAULT;
    }
    printk(KERN_INFO "String sent to user space: %s\n", value);
    return bytes_to_copy;
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    size_t bytes_to_copy = min(length, sizeof(value) - 1); // Ensure string length doesn't exceed buffer size
    if (copy_from_user(value, buffer, bytes_to_copy)) {
        return -EFAULT;
    }
    value[bytes_to_copy] = '\0'; // Null-terminate the string
    printk(KERN_INFO "String received from user space: %s\n", value);
    // Reverse the string
    size_t i, j;
    char temp;
    for (i = 0, j = bytes_to_copy - 1; i < j; ++i, --j) {
        temp = value[i];
        value[i] = value[j];
        value[j] = temp;
    }
    return bytes_to_copy;
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

static int __init reverse_string_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Reverse String: Device registered with major number %d\n", major);
    return 0;
}

static void __exit reverse_string_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Reverse String: Device unregistered\n");
}

module_init(reverse_string_init);
module_exit(reverse_string_exit);