#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define DEVICE_NAME "reversedev"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple device driver that reverses a string");

static int Major;

static int device_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset)
{
    char *reversed = kmalloc(length, GFP_KERNEL);
    int i;

    if (!reversed)
        return -ENOMEM; // Error while allocating memory

    for (i = 0; i < length; ++i) {
        reversed[i] = buffer[length - i - 1];
    }

    if (copy_to_user(buffer, (void *)reversed, length) != 0) {
        kfree(reversed);
        return -EFAULT; // Error while copying data to user space
    }

    kfree(reversed);
    return length;
}

static struct file_operations fops = {
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

static int __init reversedev_init(void)
{
    Major = register_chrdev(0, DEVICE_NAME, &fops);
    if (Major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", Major);
        return Major;
    }
    printk(KERN_INFO "Registered char device with major number %d\n", Major);
    return 0;
}

static void __exit reversedev_exit(void)
{
    unregister_chrdev(Major, DEVICE_NAME);
    printk(KERN_INFO "Unregistered char device\n");
}

module_init(reversedev_init);
module_exit(reversedev_exit);
