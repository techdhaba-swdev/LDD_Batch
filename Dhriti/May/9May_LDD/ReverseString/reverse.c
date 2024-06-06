#include <linux/init.h>         // Initialization and cleanup functions
#include <linux/module.h>       
#include <linux/kernel.h>       // Contains types, macros, functions for the kernel
#include <linux/fs.h>           // File operations structures and functions
#include <linux/uaccess.h>      // Provides functions to safely access user space memory

#define DEVICE_NAME "reverse"  // Device name for the module
#define MAX_LENGTH 100                 // Maximum length of input/output strings

static int major_number;                // Major number assigned to the device
static char input_string[MAX_LENGTH];   // Buffer to store input string from user
static char reversed_string[MAX_LENGTH];// Buffer to store reversed string

// Function called when the device is opened
static int reverse_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

// Function called when the device is closed
static int reverse_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

// Function called when data is written to the device
static ssize_t reverse_write(struct file *file, const char *buffer, size_t length, loff_t *offset) {
    // Check if input string is too long
    if (length > MAX_LENGTH) {
        printk(KERN_ALERT "Input string is too long\n");
        return -EINVAL;
    }

    // Copy input string from user space to kernel space
    if (copy_from_user(input_string, buffer, length)) {
        return -EFAULT;
    }
    input_string[length] = '\0'; // Null-terminate the input string

    // Reverse the input string
    int i, j;
    for (i = 0, j = length - 1; i < length; ++i, --j) {
        reversed_string[i] = input_string[j];
    }
    reversed_string[i] = '\0'; // Null-terminate the reversed string

    // Print input and reversed strings
    printk(KERN_INFO "Input string: %s\n", input_string);
    printk(KERN_INFO "Reversed string: %s\n", reversed_string);

    return length;
}

// Function called when data is read from the device
static ssize_t reverse_read(struct file *file, char *buffer, size_t length, loff_t *offset) {
    // Determine number of bytes to copy
    int bytes_to_copy = strlen(reversed_string);
    if (bytes_to_copy > length) {
        bytes_to_copy = length;
    }

    // Copy reversed string from kernel space to user space
    if (copy_to_user(buffer, reversed_string, bytes_to_copy)) {
        return -EFAULT;
    }

    return bytes_to_copy;
}

// Structure containing file operations for the device
static struct file_operations fops = {
    .open = reverse_open,
    .release = reverse_release,
    .write = reverse_write,
    .read = reverse_read,
};

// Function called when the module is loaded
static int __init reverse_init(void) {
    // Register character device and obtain major number
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Reverse string device registered, major number: %d\n", major_number);
    return 0;
}

// Function called when the module is unloaded
static void __exit reverse_exit(void) {
    // Unregister character device
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Reverse string device unregistered\n");
}

// Macros to specify module initialization and exit functions
module_init(reverse_init);
module_exit(reverse_exit);

// Module metadata
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dhriti");
MODULE_DESCRIPTION("Kernel module for reversing a string");

