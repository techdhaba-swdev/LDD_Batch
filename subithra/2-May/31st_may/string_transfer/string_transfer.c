#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "my_device"
#define BUF_LEN 256

static int major_num;
static char msg[BUF_LEN];
static short msg_len;
static int device_open_count = 0;

static int device_open(struct inode *inode, struct file *file) {
    if (device_open_count)
        return -EBUSY;

    device_open_count++;
    try_module_get(THIS_MODULE);
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    device_open_count--;
    module_put(THIS_MODULE);
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t len, loff_t *offset) {
    int bytes_read = 0;

    if (*msg == 0)
        return 0;

    while (len && msg_len) {
        put_user(msg[bytes_read], buffer++);
        msg_len--;
        len--;
        bytes_read++;
    }

    return bytes_read;
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t len, loff_t *offset) {
    int i;

    for (i = 0; i < len && i < BUF_LEN; i++)
        get_user(msg[i], buffer + i);

    msg_len = i;
    printk(KERN_INFO "RECEIVED STRING FROM USER: %s\n",msg);
    return i;
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

static int __init my_device_init(void) {
    major_num = register_chrdev(0, DEVICE_NAME, &fops);

    if (major_num < 0) {
        printk(KERN_ALERT "Could not register device: %d\n", major_num);
        return major_num;
    } else {
        printk(KERN_INFO "my_device module loaded with device major number %d\n", major_num);
        return 0;
    }
}

static void __exit my_device_exit(void) {
    unregister_chrdev(major_num, DEVICE_NAME);
    printk(KERN_INFO "my_device module unloaded\n");
}

module_init(my_device_init);
module_exit(my_device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Linux char driver");


