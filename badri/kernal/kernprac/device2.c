#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/kernel.h>

#define DEVICE_NAME "double_val"

static int major;
static int value;

static int device_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "device opened successfully\n");
    return 0;
}

static int device_close(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "device closed successfully\n");
    return 0;
}

static ssize_t device_write(struct file *file, const char *buffer, size_t length, loff_t *offset)
{
    copy_from_user(&value, buffer, sizeof(int));
    printk(KERN_INFO "kern msg: value from user space %d\n", value);
    value = value * 2;
    printk(KERN_INFO "kern msg: doubled value from kernel space %d\n", value);
    return sizeof(int);
}

static ssize_t device_read(struct file *file, char *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO "i am storing doubled value in temp \n");
    int temp = value;
    copy_to_user(buffer, &temp, sizeof(int));
    printk(KERN_INFO "kern msg: value sent to user space %d\n", temp);
    return sizeof(int);
}

static struct file_operations fops = {
    .open = device_open,
    .write = device_write,
    .read = device_read,
    .release = device_close,
};

static int __init device_start(void)
{
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0)
    {
        printk(KERN_INFO "major number for chardev is failed \n");
        return -1;
    }
    printk(KERN_INFO "major number for chrdev created successfully %d \n", major);
    return 0;
}

static void __exit device_stop(void)
{
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "device closed with major number %d closed successfully \n", major);
}

module_init(device_start);
module_exit(device_stop);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BADRINATH");
MODULE_DESCRIPTION("DOUBLE VALUE");
