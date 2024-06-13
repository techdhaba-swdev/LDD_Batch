#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "reverse_string"
#define BUF_LEN 256


static int major_number;
static char msg[BUF_LEN];
static short read_pos;
static int is_device_open = 0;

static int device_open(struct inode *inode, struct file *file) {
    if (is_device_open)
        return -EBUSY;
    is_device_open++;
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    is_device_open--;
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    short bytes_read = 0;
    while (length && (msg[read_pos] != '\0')) {
        put_user(msg[read_pos], buffer++);
        bytes_read++;
        length--;
        read_pos++;
    }
    return bytes_read;
}

static ssize_t device_write(struct file *filp, const char *buff, size_t len, loff_t *off) {
    short index = len - 1;
    short bytes_written = 0;
    memset(msg, 0, BUF_LEN);
    read_pos = 0;
    while (len > 0) {
        msg[index] = buff[bytes_written];
        bytes_written++;
        index--;
        len--;
    }
    return bytes_written;
}

static struct file_operations fops = {
    .open = device_open,
    .read = device_read,
    .write = device_write,
    .release = device_release
};

static int __init reverse_string_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Registered correctly with major number %d\n", major_number);
    return 0;
}

static void __exit reverse_string_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Unregistered the device driver\n");
}

module_init(reverse_string_init);
module_exit(reverse_string_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SUSMITHA");
MODULE_DESCRIPTION(" reverse string");


