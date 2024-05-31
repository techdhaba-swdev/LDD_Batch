#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "simple_char_device"
#define BUF_LEN 80

static int major;
static char msg[BUF_LEN];
static char *msg_ptr;

static int device_open(struct inode *inode, struct file *file) {
    msg_ptr = msg;
    try_module_get(THIS_MODULE);
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    module_put(THIS_MODULE);
    return 0;
}

static ssize_t device_read(struct file *file, char __user *buffer, size_t length, loff_t *offset) {
    int bytes_read = 0;

    if (*msg_ptr == 0) {
        return 0;
    }

    while (length && *msg_ptr) {
        put_user(*(msg_ptr++), buffer++);
        length--;
        bytes_read++;
    }

    return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *buffer, size_t length, loff_t *offset) {
    ssize_t i;

    if (length > BUF_LEN) {
        length = BUF_LEN;
    }

    for (i = 0; i < length; i++) {
        get_user(msg[i], buffer + i);
    }

    msg[i] = '\0';  // Null terminate the string
    printk(KERN_INFO "Kernel: %s\n", msg);  // Print to kernel log

    return i;
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release
};

static int __init simple_char_device_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);

    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }

    printk(KERN_INFO "Simple char device registered with major number %d\n", major);
    return 0;
}

static void __exit simple_char_device_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Simple char device unregistered\n");
}

module_init(simple_char_device_init);
module_exit(simple_char_device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BHAVANA");
MODULE_DESCRIPTION("A simple character device driver");
