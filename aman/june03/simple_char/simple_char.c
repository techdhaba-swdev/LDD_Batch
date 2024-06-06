#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "simple_char_device"
#define BUFFER_SIZE 1024

static int major_number;
static char message[BUFFER_SIZE] = {0};
static short message_length;

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fops = {
    .open = device_open,
    .read = device_read,
    .write = device_write,
    .release = device_release,
};

static int __init simple_char_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "SimpleCharDevice failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "SimpleCharDevice: registered correctly with major number %d\n", major_number);
    return 0;
}

static void __exit simple_char_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "SimpleCharDevice: unregistered correctly\n");
}

static int device_open(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "SimpleCharDevice: device opened\n");
    return 0;
}

static int device_release(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "SimpleCharDevice: device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
    int error_count = 0;
    error_count = copy_to_user(buffer, message, message_length);

    if (error_count == 0) {
        printk(KERN_INFO "SimpleCharDevice: sent %d characters to the user\n", message_length);
        return (message_length = 0);
    } else {
        printk(KERN_INFO "SimpleCharDevice: failed to send %d characters to the user\n", error_count);
        return -EFAULT;
    }
}

static ssize_t device_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
    snprintf(message, BUFFER_SIZE, "%s(%zu letters)", buffer, len);
    message_length = strlen(message);
    printk(KERN_INFO "SimpleCharDevice: received %zu characters from the user\n", len);
    return len;
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Linux char driver");
MODULE_VERSION("0.1");

module_init(simple_char_init);
module_exit(simple_char_exit);
