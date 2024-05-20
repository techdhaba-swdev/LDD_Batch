#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "div_int"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");

static int major;
static int value;

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
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
    int values[2]; // Array to store the two numbers received from user space

    copy_from_user(&values, buffer, sizeof(int) * 2);

  

    // Print the received numbers and the result
    printk(KERN_INFO "Received numbers from user space: %d, %d\n", values[0], values[1]);
    // divide the two numbers
    value = values[0] / values[1];

  

    return sizeof(int); // Return the size of data written (optional)
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
    printk(KERN_INFO "Divide Integer: Device registered with major number %d\n", major);
    return 0;
}

static void __exit double_integer_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Divide Integer: Device unregistered\n");
}

module_init(double_integer_init);
module_exit(double_integer_exit);
