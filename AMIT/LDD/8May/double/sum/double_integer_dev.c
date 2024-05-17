#include<linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "sum_integer"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AMIT");

static int major;
static int result;

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    copy_to_user(buffer, &result, sizeof(int));
    printk(KERN_INFO "result sent to user space: %d\n",result);
    return sizeof(int);
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    int num1, num2;
     sscanf(buffer, "%d%d", &num1, &num2);
      /*  printk(KERN_WARNING "Invalid input format. Please provide two integers separated by a space.\n");
        return -EINVAL;
    }*/
    result = num1 + num2; // Compute the sum
    printk(KERN_INFO "Sum of %d and %d: %d\n", num1, num2, result);
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
    printk(KERN_INFO "Sum of Integer: Device registered with major number %d\n", major);
    return 0;
}

static void __exit double_integer_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Sum of  Integer: Device unregistered\n");
}

module_init(double_integer_init);
module_exit(double_integer_exit);
