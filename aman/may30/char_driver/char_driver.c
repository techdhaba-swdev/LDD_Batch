#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "char_device"
#define BUFFER_SIZE 1024

static int major_number;
static char message[BUFFER_SIZE] = {0};
static short size_of_message;
static int number_of_opens = 0;

static int dev_open(struct inode *inodep, struct file *filep) {
    number_of_opens++;
    printk(KERN_INFO "SimpleChar: Device has been opened %d time(s)\n", number_of_opens);
    return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
    int error_count = 0;
    error_count = copy_to_user(buffer, message, size_of_message);

    if (error_count == 0) {
        printk(KERN_INFO "SimpleChar: Sent %d characters to the user\n", size_of_message);
        return (size_of_message = 0);
    } else {
        printk(KERN_INFO "SimpleChar: Failed to send %d characters to the user\n", error_count);
        return -EFAULT;
    }
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
    snprintf(message, BUFFER_SIZE, "%s(%zu letters)", buffer, len);
    size_of_message = strlen(message);
    printk(KERN_INFO "SimpleChar: Received %zu characters from the user\n", len);
    return len;
}

static int dev_release(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "SimpleChar: Device successfully closed\n");
    return 0;
}

static struct file_operations fops = {
    .open = dev_open,
    .read = dev_read,
    .write = dev_write,
    .release = dev_release,
};

static int __init simple_char_init(void) {
    printk(KERN_INFO "SimpleChar: Initializing the SimpleChar\n");

    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "SimpleChar failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "SimpleChar: registered correctly with major number %d\n", major_number);

    return 0;
}

static void __exit simple_char_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "SimpleChar: Goodbye\n");
}

module_init(simple_char_init);
module_exit(simple_char_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("aman");
MODULE_DESCRIPTION("A simple Linux char driver");
MODULE_VERSION("0.1");
