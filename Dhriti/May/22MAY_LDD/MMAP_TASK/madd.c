#include <linux/kernel.h> // Needed for KERN_INFO
#include <linux/module.h> // Needed by all modules
#include <linux/fs.h>     // Needed for file operations
#include <linux/uaccess.h> // Needed for copy_to_user and copy_from_user

#define DEVICE_NAME "add_device" // Define the device name

static int major_num; // Variable to store the major number assigned to our device

// Define a structure to hold the operation data
struct addition_operation {
    int num1;
    int num2;
    int sum;
};

static struct addition_operation operation; // Variable to hold the operation data

// Device open function
static int device_open(struct inode *inode, struct file *file) {
    try_module_get(THIS_MODULE); // Increment module usage count
    return 0;
}

// Device release function
static int device_release(struct inode *inode, struct file *file) {
    module_put(THIS_MODULE); // Decrement module usage count
    return 0;
}

// Device write function
static ssize_t device_write(struct file *file, const char *buffer, size_t length, loff_t *offset) {
    if (copy_from_user(&operation, buffer, sizeof(struct addition_operation))) { // Copy data from user space to kernel space
        return -EFAULT; // Return error if copy fails
    }
    
    operation.sum = operation.num1 + operation.num2; // Perform addition
    
    return length; // Return the number of bytes written
}

// Device read function
static ssize_t device_read(struct file *file, char *buffer, size_t length, loff_t *offset) {
    if (copy_to_user(buffer, &operation, sizeof(struct addition_operation))) { // Copy result from kernel space to user space
        return -EFAULT; // Return error if copy fails
    }
    
    return sizeof(struct addition_operation); // Return the number of bytes read
}

// File operations structure
static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
    .write = device_write,
    .read = device_read,
};

// Module initialization function
static int __init addition_init(void) {
    major_num = register_chrdev(0, DEVICE_NAME, &fops); // Register the character device
    if (major_num < 0) {
        printk(KERN_ALERT "Addition Module: Failed to register a major number\n"); // Print error message if registration fails
        return major_num;
    }
    printk(KERN_INFO "Addition Module: Registered correctly with major number %d\n", major_num); // Print success message
    return 0;
}

// Module exit function
static void __exit addition_exit(void) {
    unregister_chrdev(major_num, DEVICE_NAME); // Unregister the character device
    printk(KERN_INFO "Addition Module: Unregistered\n"); // Print unregistration message
}

module_init(addition_init); // Specify initialization function
module_exit(addition_exit); // Specify exit function

MODULE_LICENSE("GPL"); // Specify license
MODULE_AUTHOR("Your Name"); // Specify author
MODULE_DESCRIPTION("A simple addition module with struct"); // Specify description
