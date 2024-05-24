// chardev.c
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "chardev"
#define BUF_LEN 80

static int major;
static char msg[BUF_LEN];
static int device_open = 0;

static int dev_open(struct inode *inode, struct file *file) {
    if (device_open)
        return -EBUSY;
    device_open++;
    try_module_get(THIS_MODULE);
    return 0;
}

static int dev_release(struct inode *inode, struct file *file) {
    device_open--;
    module_put(THIS_MODULE);
    return 0;
}

static ssize_t dev_read(struct file *filp, char *buffer, size_t length, loff_t * offset) {
    int bytes_read = 0;
    char *msg_ptr = msg; // Use a pointer to traverse the msg buffer

    if (*msg_ptr == 0)
        return 0;

    while (length && *msg_ptr) {
        put_user(*msg_ptr, buffer);
        msg_ptr++;
        buffer++;
        length--;
        bytes_read++;
    }
    return bytes_read;
}

static ssize_t dev_write(struct file *filp, const char *buffer, size_t length, loff_t * off) {
    int i;
    for (i = 0; i < length && i < BUF_LEN - 1; i++) {
        get_user(msg[i], buffer + i);
    }
    msg[i] = '\0';
    return i;
}

static struct file_operations fops = {
    .read = dev_read,
    .write = dev_write,
    .open = dev_open,
    .release = dev_release
};

static int __init chardev_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "I was assigned major number %d. To talk to\n", major);
    printk(KERN_INFO "the driver, create a dev file with\n");
    printk(KERN_INFO "'mknod /dev/%s c %d 0'.\n", DEVICE_NAME, major);
    return 0;
}

static void __exit chardev_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Char device unregistered.\n");
}

module_init(chardev_init);
module_exit(chardev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple character device driver");
