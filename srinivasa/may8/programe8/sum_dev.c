#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "sum_device"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("srinivas");

static int major;
static int value, value1, value2;

static int device_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO " device opened \n");
	return 0;
}
static int device_release(struct inode *inode, struct file *file) {
       	printk(KERN_INFO "Device closed\n");
        return 0;
}
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
       	copy_to_user(buffer, &value, sizeof(int));
        printk(KERN_INFO "Value sent to user space: %d\n", value);
        return sizeof(int);
}
static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    copy_from_user(&value1, buffer, sizeof(int));
    printk(KERN_INFO "Value1 received from user space: %d\n", value1);
    copy_from_user(&value2, buffer, sizeof(int));
    printk(KERN_INFO "Value2 received from user space: %d\n", value2);
    value = value1 + value2; // adding two values 
    return sizeof(int);
}

static struct file_operations fops = {
	.read = device_read,
        .write = device_write,
        .open = device_open,
        .release = device_release,
};

static int __init double_integer_init(void) {
       	major = register_chrdev(0, DEVICE_NAME, &fops);
        if (major < 0) {
		printk(KERN_ALERT "Registering char device failed with %d\n", major);
                return major;
         }
	printk(KERN_INFO "sum of Integers: Device registered with major number %d\n", major);
        return 0;
}

static void __exit double_integer_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "sum of Integers: Device unregistered\n");
}

module_init(double_integer_init);
module_exit(double_integer_exit);
