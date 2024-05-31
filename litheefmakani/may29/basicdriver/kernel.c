#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "mydevice"
#define BUF_LEN 1024

static char msg[BUF_LEN];
static int msg_len = 0;
static int major;

static int device_open(struct inode *inode, struct file *file) {
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    int bytes_read = 0;
    if (*offset >= msg_len)
        return 0;
    while (length && *offset < msg_len) {
        put_user(msg[(*offset)++], buffer++);
        length--;
        bytes_read++;
    }
    return bytes_read;
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    int bytes_written = 0;
    while (length && *offset < BUF_LEN - 1) {
        get_user(msg[*offset], buffer++);
        (*offset)++;
        length--;
        bytes_written++;
    }
    msg_len = *offset;
    msg[msg_len] = '\0'; // Null terminate the string
    return bytes_written;
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release
};

static int __init simple_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Char device registered with major number %d\n", major);
    return 0;
}

static void __exit simple_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Unregistered char device\n");
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple character device driver");
MODULE_VERSION("0.1");
	

