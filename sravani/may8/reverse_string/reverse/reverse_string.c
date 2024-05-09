#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "reverse_string"
#define BUFFER_SIZE 100

static char message[BUFFER_SIZE] = {0};

static int reverse_dev_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static ssize_t reverse_dev_read(struct file *file, char __user *buffer, size_t length, loff_t *offset) {
    int bytes_to_copy = min(length, (size_t)strlen(message));

    if (bytes_to_copy == 0) {
        return 0; // End of file
    }

    if (copy_to_user(buffer, message, bytes_to_copy)) {
        return -EFAULT;
    }

    return bytes_to_copy;
}

static ssize_t reverse_dev_write(struct file *file, const char __user *buffer, size_t length, loff_t *offset) {
    if (length >= BUFFER_SIZE) {
        printk(KERN_WARNING "String too long\n");
        return -EINVAL;
    }

    if (copy_from_user(message, buffer, length)) {
        return -EFAULT;
    }

    // Reverse the string
    int i, j;
    char temp;
    for (i = 0, j = length - 1; i < j; ++i, --j) {
        temp = message[i];
        message[i] = message[j];
        message[j] = temp;
    }

    message[length] = '\0'; // Null terminate the reversed string

    printk(KERN_INFO "Received string: %s\n", message);

    return length;
}

static int reverse_dev_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static struct file_operations fops = {
    .open = reverse_dev_open,
    .read = reverse_dev_read,
    .write = reverse_dev_write,
    .release = reverse_dev_release,
};

static int __init reverse_string_init(void) {
    int ret = register_chrdev(0, DEVICE_NAME, &fops);
    if (ret < 0) {
        printk(KERN_ALERT "Failed to register device: %s\n", DEVICE_NAME);
        return ret;
    }
    printk(KERN_INFO "Reverse string device registered\n");
    return 0;
}

static void __exit reverse_string_exit(void) {
    unregister_chrdev(0, DEVICE_NAME);
    printk(KERN_INFO "Reverse string device unregistered\n");
}

module_init(reverse_string_init);
module_exit(reverse_string_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple character driver for reversing strings");

