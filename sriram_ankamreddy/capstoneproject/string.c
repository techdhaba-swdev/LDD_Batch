#include <linux/init.h>          // Required for module initialization and exit macros
#include <linux/module.h>        // Required for module-related macros and functions
#include <linux/fs.h>            // Required for file operations structure
#include <linux/uaccess.h>       // Required for copy_to_user and copy_from_user functions
#include <linux/cdev.h>          // Required for character device registration
#include <linux/string.h>        // Required for string manipulation functions

#define DEVICE_NAME "my_string_slicer_device" // Define the name of the device
#define IOCTL_MAGIC 'c'                       // Define a magic number for ioctl
#define IOCTL_SLICE _IOWR(IOCTL_MAGIC, 1, struct slice_data) // Define ioctl command with magic number and command number

// Define a structure to hold the string slicing data
struct slice_data {
    char input[256];  // Input string
    char output[256]; // Output string containing first characters of each word
};

// Function to handle device open
static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "String slicer device opened\n"); // Log message
    return 0; // Return success
}

// Function to handle device close
static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "String slicer device closed\n"); // Log message
    return 0; // Return success
}

// Custom tokenization function
static char *strtok_custom(char *str, const char *delim, char **saveptr) {
    char *token;

    if (str == NULL) {
        str = *saveptr;
    }

    str += strspn(str, delim);
    if (*str == '\0') {
        return NULL;
    }

    token = str;
    str = strpbrk(token, delim);
    if (str == NULL) {
        *saveptr = token + strlen(token);
    } else {
        *str = '\0';
        *saveptr = str + 1;
    }

    return token;
}

// Function to handle ioctl calls
static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    struct slice_data data; // Declare a structure to hold slicing data
    char *saveptr;
    char *token;

    switch (cmd) { // Check which ioctl command was received
        case IOCTL_SLICE: // If the command is IOCTL_SLICE
            if (copy_from_user(&data, (struct slice_data __user *)arg, sizeof(data))) { // Copy data from user space
                return -EFAULT; // Return error if copy fails
            }

            // Initialize output string
            memset(data.output, 0, sizeof(data.output));
            int j = 0;

            // Perform the slicing operation using custom tokenizer
            token = strtok_custom(data.input, " ", &saveptr);
            while (token != NULL) {
                data.output[j++] = token[0]; // Get the first character of each word
                token = strtok_custom(NULL, " ", &saveptr);   // Move to the next word
            }

            if (copy_to_user((struct slice_data __user *)arg, &data, sizeof(data))) { // Copy result back to user space
                return -EFAULT; // Return error if copy fails
            }

            // Log the operation performed
            printk(KERN_INFO "Input string: %s\n", data.input);
            printk(KERN_INFO "Output string: %s\n", data.output);
            break;
        default:
            return -ENOTTY; // Return "inappropriate ioctl" error for unknown commands
    }

    return 0; // Return success
}

// Define the file operations structure
static struct file_operations fops = {
    .owner = THIS_MODULE, // Set the owner of the module
    .open = device_open, // Set the open function
    .release = device_release, // Set the release function
    .unlocked_ioctl = device_ioctl, // Set the ioctl function
};

static int major_number; // Declare a variable to hold the major number
static struct cdev my_cdev; // Declare a character device structure

// Module initialization function
static int __init my_string_slicer_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops); // Register the character device and get the major number
    if (major_number < 0) { // Check if registration failed
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number); // Log error message
        return major_number; // Return the error code
    }

    cdev_init(&my_cdev, &fops); // Initialize the character device with file operations
    my_cdev.owner = THIS_MODULE; // Set the owner of the character device
    if (cdev_add(&my_cdev, MKDEV(major_number, 0), 1)) { // Add the character device to the system
        unregister_chrdev(major_number, DEVICE_NAME); // Unregister the character device if adding fails
        printk(KERN_ALERT "Adding cdev failed\n"); // Log error message
        return -1; // Return error code
    }

    printk(KERN_INFO "String slicer device registered with major number %d\n", major_number); // Log success message
    return 0; // Return success
}

// Module exit function
static void __exit my_string_slicer_exit(void) {
    cdev_del(&my_cdev); // Delete the character device
    unregister_chrdev(major_number, DEVICE_NAME); // Unregister the character device
    printk(KERN_INFO "String slicer device unregistered\n"); // Log success message
}

module_init(my_string_slicer_init); // Set the initialization function
module_exit(my_string_slicer_exit); // Set the exit function

MODULE_LICENSE("GPL"); // Set the license of the module
MODULE_AUTHOR("Group A"); // Set the author of the module
MODULE_DESCRIPTION("A simple string slicer char driver with ioctl"); // Set the description of the module
MODULE_VERSION("0.1"); // Set the version of the module