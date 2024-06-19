#include <linux/init.h> // For module initialization and cleanup functions
#include <linux/module.h> // For defining the module and its information
#include <linux/fs.h> // For file operations
#include <linux/uaccess.h> // For data transfer between user and kernel space
#include <linux/cdev.h> // For character device registration

// Define device name and IOCTL magic number
#define DEVICE_NAME "char_cal" // Name of the device
#define IOCTL_MAGIC 'k' // Magic number for IOCTL commands

// Define IOCTL commands for basic and advanced arithmetic
#define IOCTL_BASIC_ARITH _IOWR(IOCTL_MAGIC, 1, int[3]) // IOCTL for basic arithmetic operations
#define IOCTL_ADVANCED_ARITH _IOWR(IOCTL_MAGIC, 2, int[3]) // IOCTL for advanced arithmetic operations

// Define IOCTL commands for specific arithmetic operations
#define IOCTL_ADD _IOWR(IOCTL_BASIC_ARITH, 1, int[3]) // IOCTL for addition
#define IOCTL_SUB _IOWR(IOCTL_BASIC_ARITH, 2, int[3]) // IOCTL for subtraction
#define IOCTL_MUL _IOWR(IOCTL_ADVANCED_ARITH, 1, int[3]) // IOCTL for multiplication
#define IOCTL_DIV _IOWR(IOCTL_ADVANCED_ARITH, 2, int[3]) // IOCTL for division
#define IOCTL_MOD _IOWR(IOCTL_ADVANCED_ARITH, 3, int[3]) // IOCTL for modulus

// Device open function
static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n"); // Log message indicating the device has been opened
    return 0; // Return success
}

// Device release (close) function
static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n"); // Log message indicating the device has been closed
    return 0; // Return success
}

/*
 * Single Responsibility Principle (SRP): The device_ioctl function is responsible 
 * solely for handling IOCTL commands. It does not handle any other operations 
 * like opening or closing the device.
 *
 * Open/Closed Principle (OCP): The function can be extended to handle more IOCTL 
 * commands by adding more cases to the switch statement, without modifying the existing code.
 */
static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    int values[3]; // Array to hold operands and result: [operand1, operand2, result]

    // Copy data from user space to kernel space
    if (copy_from_user(values, (int __user *)arg, sizeof(values))) {
        return -EFAULT; // Return error if copy fails
    }

    // Handle the specific IOCTL commands
    switch (cmd) {
        case IOCTL_ADD:
            values[2] = values[0] + values[1]; // Perform addition
            printk(KERN_INFO "Add %d + %d = %d\n", values[0], values[1], values[2]); // Log the result
            break;
        case IOCTL_SUB:
            values[2] = values[0] - values[1]; // Perform subtraction
            printk(KERN_INFO "Subtract: %d - %d = %d\n", values[0], values[1], values[2]); // Log the result
            break;
        case IOCTL_MUL:
            values[2] = values[0] * values[1]; // Perform multiplication
            printk(KERN_INFO "Multiply: %d * %d = %d\n", values[0], values[1], values[2]); // Log the result
            break;
        case IOCTL_DIV:
            if (values[1] == 0) {
                printk(KERN_ALERT "Division by zero error\n"); // Log division by zero error
                return -EINVAL; // Return error for invalid argument
            }
            values[2] = values[0] / values[1]; // Perform division
            printk(KERN_INFO "Divide: %d / %d = %d\n", values[0], values[1], values[2]); // Log the result
            break;
        case IOCTL_MOD:
            if (values[1] == 0) {
                printk(KERN_ALERT "Modulus by zero error\n"); // Log modulus by zero error
                return -EINVAL; // Return error for invalid argument
            }
            values[2] = values[0] % values[1]; // Perform modulus
            printk(KERN_INFO "Modulus: %d %% %d = %d\n", values[0], values[1], values[2]); // Log the result
            break;
        default:
            return -ENOTTY; // Return error for unsupported IOCTL command
    }

    // Copy the result back to user space
    if (copy_to_user((int __user *)arg, values, sizeof(values))) {
        return -EFAULT; // Return error if copy fails
    }

    return 0; // Return success
}

// File operations structure
/*
 * Interface Segregation Principle (ISP): The file_operations structure defines 
 * a minimal interface for the device driver, ensuring it only contains methods 
 * necessary for this particular device, without including unrelated functionalities.
 */
static struct file_operations fops = {
    .owner = THIS_MODULE, // Module that owns this file operations structure
    .open = device_open, // Pointer to the device open function
    .release = device_release, // Pointer to the device release function
    .unlocked_ioctl = device_ioctl, // Pointer to the device ioctl function
};

static int major_number; // Major number for the device
static struct cdev my_cdev; // Character device structure

// Module initialization function
/*
 * Dependency Inversion Principle (DIP): The code depends on high-level abstractions 
 * (e.g., file_operations, cdev), which are provided by the Linux kernel. This 
 * makes the driver more flexible and easier to maintain.
 */
static int __init my_ioctl_init(void) {
    // Register the character device and get the major number
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number); // Log registration failure
        return major_number; // Return the error code
    }

    // Initialize and add the character device
    cdev_init(&my_cdev, &fops); // Initialize the character device
    my_cdev.owner = THIS_MODULE; // Set the owner of the character device
    if (cdev_add(&my_cdev, MKDEV(major_number, 0), 1)) { // Add the character device to the system
        unregister_chrdev(major_number, DEVICE_NAME); // Unregister the device if adding fails
        printk(KERN_ALERT "Adding cdev failed\n"); // Log adding failure
        return -1; // Return error
    }

    printk(KERN_INFO "Device registered with major number %d\n", major_number); // Log successful registration
    return 0; // Return success
}

// Module cleanup function
static void __exit my_ioctl_exit(void) {
    cdev_del(&my_cdev); // Delete the character device
    unregister_chrdev(major_number, DEVICE_NAME); // Unregister the device
    printk(KERN_INFO "Device unregistered\n"); // Log device unregistration
}

// Specify the module initialization and cleanup functions
module_init(my_ioctl_init); // Register the initialization function
module_exit(my_ioctl_exit); // Register the cleanup function

MODULE_LICENSE("GPL"); // Define the license for the module
MODULE_AUTHOR("Your Name"); // Define the author of the module
MODULE_DESCRIPTION("A simple Linux char driver with ioctl for calculator operations"); // Define the description of the module
