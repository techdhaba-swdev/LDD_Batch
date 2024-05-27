
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "char_buf"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Subithra");
MODULE_DESCRIPTION("Linux char driver");
MODULE_VERSION("0.1");

static int major_number;
static char message[256] = {0};
static short message_size;

static int dev_open(struct inode *, struct file *);
static int dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fops = {
    .open = dev_open,
    .read = dev_read,
    .write = dev_write,
    .release = dev_release,
};

static int __init simple_char_init(void) {
printk(KERN_INFO "Initializing the SimpleChar device\n");

major_number = register_chrdev(0, DEVICE_NAME, &fops);
if (major_number < 0) {
printk(KERN_ALERT "SimpleChar failed to register a major number\n");
return major_number;
}
printk(KERN_INFO "registered correctly with major number %d\n", major_number);

return 0;
}

static void __exit simple_char_exit(void) {
unregister_chrdev(major_number, DEVICE_NAME);
printk(KERN_INFO "exiting from kernel!\n");
}

static int dev_open(struct inode *inodep, struct file *filep) {
printk(KERN_INFO "Device has been opened\n");
return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
int error_count = 0;

if (*offset >= message_size) {
return 0;
}

if (len > message_size - *offset) {
len = message_size - *offset;
}

error_count = copy_to_user(buffer, message + *offset, len);

if (error_count == 0) {
*offset += len;
printk(KERN_INFO "Sent %zu characters to the user\n", len);
return len;
} else {
printk(KERN_INFO "SimpleChar: Failed to send %d characters to the user\n", error_count);
return -EFAULT;
}
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
if (len > sizeof(message) - 1) {
len = sizeof(message) - 1;
}

if (copy_from_user(message, buffer, len)) {
return -EFAULT;
}

message[len] = '\0';
message_size = len;
printk(KERN_INFO "Received %zu characters from the user\n", len);
return len;
}

static int dev_release(struct inode *inodep, struct file *filep) {
printk(KERN_INFO "Device successfully closed\n");
return 0;
}

module_init(simple_char_init);
module_exit(simple_char_exit);
