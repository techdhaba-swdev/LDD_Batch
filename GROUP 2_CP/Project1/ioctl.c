#include <linux/init.h> // Include initialization macros
#include <linux/module.h> // Include module macros
#include <linux/fs.h> // Include file system support
#include <linux/uaccess.h> // Include user access support
#include <linux/cdev.h> // Include character device support

#define DEVICE_NAME "my_ioctl_device" // Define the device name
#define IOCTL_MAGIC 'k' // Define the ioctl magic number
#define IOCTL_CMD _IOW(IOCTL_MAGIC, 1, int) // Define an ioctl command with a writable argument

// Function called when the device is opened
static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n"); // Log that the device was opened
    return 0; // Return success
}

// Function called when the device is closed
static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n"); // Log that the device was closed
    return 0; // Return success
}

// Function called when an ioctl command is issued
static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    int value; // Variable to store the value from user space

    switch (cmd) { // Switch based on the command received
        case IOCTL_CMD: // Handle our specific ioctl command
            // Copy the integer value from user space to kernel space
            if (copy_from_user(&value, (int __user *)arg, sizeof(value))) {
                return -EFAULT; // Return error if copy fails
            }
            printk(KERN_INFO "IOCTL received: %d\n", value); // Log the received value
            break; // Break from the switch statement
        default: // Default case for unrecognized commands
            return -ENOTTY; // Return error for invalid command
    }
    return 0; // Return success
}

// Define file operations structure
static struct file_operations fops = {
    .owner = THIS_MODULE, // Set the owner of the file operations
    .open = device_open, // Set the open function
    .release = device_release, // Set the release function
    .unlocked_ioctl = device_ioctl, // Set the ioctl function
};

static int major_number; // Variable to store the major number
static struct cdev my_cdev; // Character device structure

// Module initialization function
static int __init my_ioctl_init(void) {
    // Register character device and obtain a major number
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) { // Check if registration failed
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number); // Log the failure
        return major_number; // Return the error code
    }

    // Initialize and add the cdev structure
    cdev_init(&my_cdev, &fops); // Initialize the cdev structure with file operations
    my_cdev.owner = THIS_MODULE; // Set the owner of the cdev
    if (cdev_add(&my_cdev, MKDEV(major_number, 0), 1)) { // Add the cdev structure to the system
        unregister_chrdev(major_number, DEVICE_NAME); // Unregister the device if cdev_add fails
        printk(KERN_ALERT "Adding cdev failed\n"); // Log the failure
        return -1; // Return error code
    }

    printk(KERN_INFO "Device registered with major number %d\n", major_number); // Log the successful registration
    return 0; // Return success
}

// Module cleanup function
static void __exit my_ioctl_exit(void) {
    // Remove the cdev structure and unregister the device
    cdev_del(&my_cdev); // Delete the cdev structure
    unregister_chrdev(major_number, DEVICE_NAME); // Unregister the character device
    printk(KERN_INFO "Device unregistered\n"); // Log that the device was unregistered
}

module_init(my_ioctl_init); // Specify the initialization function
module_exit(my_ioctl_exit); // Specify the cleanup function

MODULE_LICENSE("GPL"); // Set the module license
MODULE_AUTHOR("Your Name"); // Set the module author
MODULE_DESCRIPTION("A simple Linux char driver with ioctl"); // Set the module description
MODULE_VERSION("0.1")
