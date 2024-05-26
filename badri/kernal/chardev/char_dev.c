#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "BUFFER"
#define BUFF_LEN 300


static int major;
static char *msg_ptr[BUFF_LEN];
static int buff_index = 0;

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char *user_buf, size_t count, loff_t *offset) {
    if (*offset >= buff_index)
        return 0;

    if (count > BUFF_LEN)
        count = BUFF_LEN;

    if (copy_to_user(user_buf, msg_ptr, count) != 0)
        return -EFAULT;

    *offset += count;
    return count;
}

static ssize_t device_write(struct file *filp, const char *user_buf, size_t count, loff_t *offset) {
    if (buff_index + count >= BUFF_LEN)
        return -ENOSPC;

    if (copy_from_user(msg_ptr + buff_index, user_buf, count) != 0)
        return -EFAULT;

    buff_index += count;
    return count;
}

static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
};

static int __init chardev_start(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);

    if (major < 0) {
        printk(KERN_ALERT "Registering major number for chardev failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Registered major number successfully: %d\n", major);
    return 0;
}

static void __exit chardev_stop(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Unregistered chardev successfully\n");
}

module_init(chardev_start);
module_exit(chardev_stop);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BADRINATH");
MODULE_DESCRIPTION("Print MSG");
