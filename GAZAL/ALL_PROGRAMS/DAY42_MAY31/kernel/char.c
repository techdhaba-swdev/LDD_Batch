#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "simple_char_dev"
#define MAX_SIZE 256

static int major_number;
static char message[MAX_SIZE] = {0};
static short message_size;

static int dev_open(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "simple_char_dev: Device opened\n");
    return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
    int error_count = copy_to_user(buffer, message, message_size);

    if (error_count == 0) {
        printk(KERN_INFO "simple_char_dev: Sent %d characters to the user\n", message_size);
        return (message_size = 0); // Clear the message
    } else {
        printk(KERN_ERR "simple_char_dev: Failed to send %d characters to the user\n", error_count);
        return -EFAULT;
    }
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
    if (len > MAX_SIZE) {
        len = MAX_SIZE;
    }
    if (copy_from_user(message, buffer, len) != 0) {
        printk(KERN_ERR "simple_char_dev: Failed to receive %zu characters from the user\n", len);
        return -EFAULT;
    }
    message_size = len;
    printk(KERN_INFO "simple_char_dev: Received %zu characters from the user\n", len);
    printk(KERN_INFO "simple_char_dev: Message from user - %s\n", message);
    return len;
}

static int dev_release(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "simple_char_dev: Device closed\n");
    return 0;
}

static struct file_operations fops = {
    .open = dev_open,
    .read = dev_read,
    .write = dev_write,
    .release = dev_release,
};

static int __init simple_char_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ERR "simple_char_dev: Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "simple_char_dev: Registered with major number %d\n", major_number);
    return 0;
}

static void __exit simple_char_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "simple_char_dev: Unregistered device\n");
}

module_init(simple_char_init);
module_exit(simple_char_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Linux char driver");
MODULE_VERSION("0.1");