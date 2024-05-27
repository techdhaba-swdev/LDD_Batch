#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "char_device"
#define SIZE 1024

static int major_number;
static char buffer[SIZE] = {0};
static int size = 0;

// device is opened
static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "device opened\n");
    return 0;
}

// device is closed
static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "device closed\n");
    return 0;
}

// to read from user space
static ssize_t device_read(struct file *file, char __user *user_buffer, size_t len, loff_t *offset) {
    int read;

    if (*offset >= size) {
        return 0;  // End of buffer
    }

    read = len;
    if (read > size - *offset) {
        read = size - *offset;
    }

    if (copy_to_user(user_buffer, buffer + *offset, read)) {
        printk(KERN_ERR "failed to read\n");
        return -EFAULT;
    }
    *offset += read;
    printk(KERN_INFO "sent %d bytes to user\n", read);
    return read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t len, loff_t *offset) {
    int write;

    if (*offset >= SIZE) {
        return -ENOSPC;  // No space left on device
    }

    write = len;
    if (write > SIZE - *offset) {
        write = SIZE - *offset;
    }

    if (copy_from_user(buffer + *offset, user_buffer, write)) {
        printk(KERN_ERR "failed to write\n");
        return -EFAULT;
    }

    *offset += write;
    size = *offset;  // Update size to reflect new end of data
    printk(KERN_INFO "received %d bytes from the user\n", write);
    return write;
}

// file operations
static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
};

// called when module loads
static int __init char_device_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);  // for registering the device

    if (major_number < 0) {
        printk(KERN_ALERT "failed to register\n");
        return major_number;
    }

    printk(KERN_INFO "registered with major number %d\n", major_number);
    return 0;
}

static void __exit char_device_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "unregistered the device\n");
}

module_init(char_device_init);
module_exit(char_device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CHANDANA");
MODULE_DESCRIPTION("SIMPLE CHARACTER DEVICE PROGRAM");
MODULE_VERSION("1.0");
