#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "string_device"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Linux driver that receives a string from user space and prints it in kernel space");

static int major_number;
static char message[256] = {0};
static short size_of_message;
static int numberOpens = 0;

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fops =
{
    .open = device_open,
    .read = device_read,
    .write = device_write,
    .release = device_release,
};

static int __init string_device_init(void)
{
    printk(KERN_INFO "String Device: Initializing the String Device\n");
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "String Device failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "String Device: registered correctly with major number %d\n", major_number);
    return 0;
}

static void __exit string_device_exit(void)
{
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "String Device: Goodbye from the String Device!\n");
}

static int device_open(struct inode *inodep, struct file *filep)
{
    numberOpens++;
    printk(KERN_INFO "String Device: Device has been opened %d time(s)\n", numberOpens);
    return 0;
}

static int device_release(struct inode *inodep, struct file *filep)
{
    printk(KERN_INFO "String Device: Device successfully closed\n");
    return 0;
}

static ssize_t device_read(struct file *filep, char *buffer, size_t len, loff_t *offset)
{
    int error_count = 0;
    error_count = copy_to_user(buffer, message, size_of_message);
    if (error_count == 0) {
        printk(KERN_INFO "String Device: Sent %d characters to the user\n", size_of_message);
        return (size_of_message=0);
    } else {
        printk(KERN_INFO "String Device: Failed to send %d characters to the user\n", error_count);
        return -EFAULT;
    }
}

static ssize_t device_write(struct file *filep, const char *buffer, size_t len, loff_t *offset)
{
    sprintf(message, "%s", buffer);
    size_of_message = strlen(message);
    printk(KERN_INFO "String Device: Received %zu characters from the user\n", len);
    return len;
}

module_init(string_device_init);
module_exit(string_device_exit);
