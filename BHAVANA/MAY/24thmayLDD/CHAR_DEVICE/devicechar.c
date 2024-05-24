#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define DEVICE_NAME "char_device"
#define BUF_LEN 1024

static int major;
static char *device_buffer;
static int device_open(struct inode *inode, struct file *file);
static int device_release(struct inode *inode, struct file *file);
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t * offset);
static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t * offset);

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release
};

static int __init char_device_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    device_buffer = kmalloc(BUF_LEN, GFP_KERNEL);
    if (!device_buffer) {
        unregister_chrdev(major, DEVICE_NAME);
        printk(KERN_ALERT "Failed to allocate device buffer\n");
        return -ENOMEM;
    }
    memset(device_buffer, 0, BUF_LEN);
    printk(KERN_INFO "I was assigned major number %d. To talk to\n", major);
    printk(KERN_INFO "the driver, create a dev file with\n");
    printk(KERN_INFO "'mknod /dev/%s c %d 0'.\n", DEVICE_NAME, major);
    return 0;
}

static void __exit char_device_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    if (device_buffer)
        kfree(device_buffer);
    printk(KERN_INFO "Char device driver unregistered\n");
}

static int device_open(struct inode *inode, struct file *file) {
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t * offset) {
    int bytes_read = length < BUF_LEN ? length : BUF_LEN;
    if (copy_to_user(buffer, device_buffer, bytes_read)) {
        return -EFAULT;
    }
    return bytes_read;
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t * offset) {
    int bytes_to_write = length < BUF_LEN ? length : BUF_LEN;
    if (copy_from_user(device_buffer, buffer, bytes_to_write)) {
        return -EFAULT;
    }
    return bytes_to_write;
}

module_init(char_device_init);
module_exit(char_device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BHAVANA");
MODULE_DESCRIPTION("A simple character device driver");
