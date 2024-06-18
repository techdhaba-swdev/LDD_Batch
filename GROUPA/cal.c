#include <linux/init.h>          // Required for module initialization and exit macros
#include <linux/module.h>        // Required for module-related macros and functions
#include <linux/fs.h>            // Required for file operations structure
#include <linux/uaccess.h>       // Required for copy_to_user and copy_from_user functions
#include <linux/cdev.h>          // Required for character device registration

#define DEVICE_NAME "my_calculator_device" // Define the name of the device
#define IOCTL_MAGIC 'c'                    // Define a magic number for ioctl
#define IOCTL_CALC _IOWR(IOCTL_MAGIC, 1, struct calc_data) // Define ioctl command with magic number and command number

// Define a structure to hold the calculation data
struct calc_data {
    int num1;      // First operand
    int num2;      // Second operand
    char operation; // Operation to perform (+, -, *, /)
    int result;    // Result of the operation
};

// Function to handle device open
static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Calculator device opened\n"); // Log message
    return 0; // Return success
}

// Function to handle device close
static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Calculator device closed\n"); // Log message
    return 0; // Return success
}

// Function to handle ioctl calls
static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    struct calc_data data; // Declare a structure to hold calculation data

    switch (cmd) { // Check which ioctl command was received
        case IOCTL_CALC: // If the command is IOCTL_CALC
            if (copy_from_user(&data, (struct calc_data __user *)arg, sizeof(data))) { // Copy data from user space
                return -EFAULT; // Return error if copy fails
            }
            
            // Perform the requested operation
            switch (data.operation) {
                case '+':
                    data.result = data.num1 + data.num2; // Addition
                    break;
                case '-':
                    data.result = data.num1 - data.num2; // Subtraction
                    break;
                case '*':
                    data.result = data.num1 * data.num2; // Multiplication
                    break;
                case '/':
                    if (data.num2 == 0) { // Check for division by zero
                        return -EINVAL; // Return invalid argument error
                    }
                    data.result = data.num1 / data.num2; // Division
                    break;
                default:
                    return -EINVAL; // Return invalid argument error for unknown operations
            }

            if (copy_to_user((struct calc_data __user *)arg, &data, sizeof(data))) { // Copy result back to user space
                return -EFAULT; // Return error if copy fails
            }

            // Log the operation performed
            printk(KERN_INFO "Operation %c: %d %c %d = %d\n", data.operation, data.num1, data.operation, data.num2, data.result);
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
static int __init my_calculator_init(void) {
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

    printk(KERN_INFO "Calculator device registered with major number %d\n", major_number); // Log success message
    return 0; // Return success
}

// Module exit function
static void __exit my_calculator_exit(void) {
    cdev_del(&my_cdev); // Delete the character device
    unregister_chrdev(major_number, DEVICE_NAME); // Unregister the character device
    printk(KERN_INFO "Calculator device unregistered\n"); // Log success message
}

module_init(my_calculator_init); // Set the initialization function
module_exit(my_calculator_exit); // Set the exit function

MODULE_LICENSE("GPL"); // Set the license of the module
MODULE_AUTHOR("Group A"); // Set the author of the module
MODULE_DESCRIPTION("A simple calculator char driver with ioctl"); // Set the description of the module
MODULE_VERSION("0.1"); // Set the version of the module
