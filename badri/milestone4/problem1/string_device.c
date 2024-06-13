#include <linux/init.h> // Include the header file for kernel module initialization.
#include <linux/module.h> // Include the header file for kernel modules.
#include <linux/kernel.h> // Include the header file for kernel functions.
#include <linux/fs.h> // Include the header file for file system-related functions.
#include <linux/uaccess.h> // Include the header file for user space access.

#define DEVICE_NAME "reversing_string" // Define the name of the device.
#define MAX_LENGTH 100 // Define the maximum length of input string.

static int major_number; // Declare a variable to store the major number of the device.
static char input_string[MAX_LENGTH]; // Declare an array to store the input string.
static char reversed_string[MAX_LENGTH]; // Declare an array to store the reversed string.

static int reverse_open(struct inode *inode, struct file *file) { // Define the function called when the device is opened.
    printk(KERN_INFO "Device opened\n"); // Print a message indicating the device is opened.
    return 0; // Return 0 to indicate success.
}

static int reverse_release(struct inode *inode, struct file *file) { // Define the function called when the device is closed.
    printk(KERN_INFO "Device closed\n"); // Print a message indicating the device is closed.
    return 0; // Return 0 to indicate success.
}

static ssize_t reverse_write(struct file *file, const char *buffer, size_t length, loff_t *offset) { // Define the function called when data is written to the device.
    if (length > MAX_LENGTH) { // Check if the input string is too long.
        printk(KERN_ALERT "Input string is too long\n"); // Print an error message.
        return -EINVAL; // Return an error code.
    }

    if (copy_from_user(input_string, buffer, length)) { // Copy the input string from user space to kernel space.
        return -EFAULT; // Return an error code if copying fails.
    }
    input_string[length] = '\0'; // Null-terminate the input string.

    // Reverse the input string
    int i, j; // Declare variables for iterating through the string.
    for (i = 0, j = length - 1; i < length; ++i, --j) { // Reverse the string.
        reversed_string[i] = input_string[j];
    }
    reversed_string[i] = '\0'; // Null-terminate the reversed string.

    printk(KERN_INFO "Input string: %s\n", input_string); // Print the input string.
    printk(KERN_INFO "Reversed string: %s\n", reversed_string); // Print the reversed string.

    return length; // Return the number of bytes written.
}

static ssize_t reverse_read(struct file *file, char *buffer, size_t length, loff_t *offset) { // Define the function called when data is read from the device.
    int bytes_to_copy = strlen(reversed_string); // Determine the number of bytes to copy.
    if (bytes_to_copy > length) { // Check if the buffer size is smaller than the string length.
        bytes_to_copy = length; // Adjust the number of bytes to copy.
    }

    if (copy_to_user(buffer, reversed_string, bytes_to_copy)) { // Copy the reversed string from kernel space to user space.
        return -EFAULT; // Return an error code if copying fails.
    }

    return bytes_to_copy; // Return the number of bytes copied.
}

static struct file_operations fops = { // Define the file operations structure for the device.
    .open = reverse_open, // Assign the open function.
    .release = reverse_release, // Assign the release function.
    .write = reverse_write, // Assign the write function.
    .read = reverse_read, // Assign the read function.
};

static int __init reverse_init(void) { // Define the initialization function for the module.
    major_number = register_chrdev(0, DEVICE_NAME, &fops); // Register the character device.
    if (major_number < 0) { // Check if registration failed.
        printk(KERN_ALERT "Failed to register a major number\n"); // Print an error message.
        return major_number; // Return the error code.
    }
    printk(KERN_INFO "Reverse string device registered, major number: %d\n", major_number); // Print a message indicating successful registration.
    return 0; // Return 0 to indicate success.
}

static void __exit reverse_exit(void) { // Define the exit function for the module.
    unregister_chrdev(major_number, DEVICE_NAME); // Unregister the character device.
    printk(KERN_INFO "Reverse string device unregistered\n"); // Print a message indicating successful unregistration.
}

module_init(reverse_init); // Specify the initialization function.
module_exit(reverse_exit); // Specify the exit function.

MODULE_LICENSE("GPL"); // Specify the license of the module.
MODULE_AUTHOR("Your Name"); // Specify the author of the module.
MODULE_DESCRIPTION("Kernel module for reversing a string"); // Specify the description of the module.
