#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "mychardev"
#define BUFFER_SIZE 1024

static char device_buffer[BUFFER_SIZE];
static int device_open_count = 0;

// Helper function for logging
static void log_message(const char *message) {
    printk(KERN_INFO "%s\n", message);
}

// Helper function for copying data to user space
static ssize_t copy_to_user_space(char __user *user_buffer, const char *kernel_buffer, size_t length) {
    if (copy_to_user(user_buffer, kernel_buffer, length)) {
        return -EFAULT;
    }
    return length;
}

// Helper function for copying data from user space
static ssize_t copy_from_user_space(char *kernel_buffer, const char __user *user_buffer, size_t length) {
    if (copy_from_user(kernel_buffer, user_buffer, length)) {
        return -EFAULT;
    }
    return length;
}

static int device_open(struct inode *inode, struct file *file) {
    device_open_count++;
    log_message("Device opened");
    return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t length, loff_t *offset) {
    return copy_to_user_space(user_buffer, device_buffer, length);
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t length, loff_t *offset) {
    return copy_from_user_space(device_buffer, user_buffer, length);
}

static int device_close(struct inode *inode, struct file *file) {
    log_message("Device closed");
    return 0;
}

static struct file_operations fops = {
    .open = device_open,
    .read = device_read,
    .write = device_write,
    .release = device_close,
};

static int __init mychardev_init(void) {
    int result = register_chrdev(0, DEVICE_NAME, &fops);
    if (result < 0) {
        printk(KERN_ALERT "Failed to register the device\n");
        return result;
    }
    printk(KERN_INFO "Device registered with major number %d\n", result);
    return 0;
}

static void __exit mychardev_exit(void) {
    unregister_chrdev(0, DEVICE_NAME);
    log_message("Device unregistered");
}

module_init(mychardev_init);
module_exit(mychardev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple character device driver with DRY");




