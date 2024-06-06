#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "simple_char_device"
#define BUFFER_SIZE 1024

static int major_number;
static char device_buffer[BUFFER_SIZE];
static struct cdev my_cdev;
static int device_open = 0;

//File operations prototypes 
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

// File operations structure 
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
};

//Open device function 
static int device_open(struct inode *inode, struct file *file) {
    if (device_open) {
        return -EBUSY;
    }
    device_open++;
    try_module_get(THIS_MODULE);
    return 0;
}

// Release device  function
static int device_release(struct inode *inode, struct file *file) {
    device_open--;
    module_put(THIS_MODULE);
    return 0;
}

/ Read from device 
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    int bytes_read = 0;
    if (*offset >= BUFFER_SIZE) {
        return 0;
    }
    if (*offset + length > BUFFER_SIZE) {
        length = BUFFER_SIZE - *offset;
    }
    if (copy_to_user(buffer, device_buffer + *offset, length) != 0) {
        return -EFAULT;
    }
    *offset += length;
    bytes_read += length;
    return bytes_read;
}

// Write to device 
static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    if (*offset >= BUFFER_SIZE) {
        return -ENOMEM;
    }
    if (*offset + length > BUFFER_SIZE) {
        length = BUFFER_SIZE - *offset;
    }
    if (copy_from_user(device_buffer + *offset, buffer, length) != 0) {
        return -EFAULT;
    }
    *offset += length;
    return length;
}

// Module initialization 
static int __init simple_char_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register character device\n");
        return major_number;
    }
    printk(KERN_INFO "Registered char device with major number %d\n", major_number);
    
    cdev_init(&my_cdev, &fops);
    my_cdev.owner = THIS_MODULE;
    if (cdev_add(&my_cdev, MKDEV(major_number, 0), 1) < 0) {
        unregister_chrdev(major_number, DEVICE_NAME);
        return -1;
    }
    return 0;
}

// Module exit 
static void __exit simple_char_exit(void) {
    cdev_del(&my_cdev);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Unregistered char device\n");
}

module_init(simple_char_init);
module_exit(simple_char_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("aman");
MODULE_DESCRIPTION("simple character device driver");
