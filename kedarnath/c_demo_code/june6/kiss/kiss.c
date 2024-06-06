#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "simplechardev"
#define BUFFER_SIZE 1024

static char device_buffer[BUFFER_SIZE];
static int device_open_count = 0;

// Open device
static int device_open(struct inode *inode, struct file *file) {
    device_open_count++;
    printk(KERN_INFO "simplechardev: Device opened %d times\n", device_open_count);
    return 0;
}

// Read from device
static ssize_t device_read(struct file *file, char __user *user_buffer, size_t length, loff_t *offset) {
    if (length > BUFFER_SIZE) {
        length = BUFFER_SIZE;
    }
    if (copy_to_user(user_buffer, device_buffer, length)) {
        return -EFAULT;
    }
    return length;
}

// Write to device
static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t length, loff_t *offset) {
    if (length > BUFFER_SIZE) {
        length = BUFFER_SIZE;
    }
    if (copy_from_user(device_buffer, user_buffer, length)) {
        return -EFAULT;
    }
    return length;
}

// Release device
static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "simplechardev: Device closed\n");
    return 0;
}

static struct file_operations fops = {
    .open = device_open,
    .read = device_read,
    .write = device_write,
    .release = device_release,
};

static int __init simplechardev_init(void) {
    int result = register_chrdev(0, DEVICE_NAME, &fops);
    if (result < 0) {
        printk(KERN_ALERT "simplechardev: Failed to register the device\n");
        return result;
    }
    printk(KERN_INFO "simplechardev: Device registered with major number %d\n", result);
    return 0;
}

static void __exit simplechardev_exit(void) {
    unregister_chrdev(0, DEVICE_NAME);
    printk(KERN_INFO "simplechardev: Device unregistered\n");
}

module_init(simplechardev_init);
module_exit(simplechardev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple character device driver following KISS");




