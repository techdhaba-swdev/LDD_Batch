#include <linux/init.h>         //  module initialization & cleanup
#include <linux/module.h>       //  module functionality
#include <linux/kernel.h>       //  kernel functions
#include <linux/fs.h>           //  file system operations
#include <linux/uaccess.h>      //  user-space access

#define DEVICE_NAME "calculator"    // Define the name of the device

static int major_number;        // Major number for the device
static char operation;          // Character to store the operation
static int operand1;            // First operand
static int operand2;            // Second operand
static int result;              // Result of the operation

// Function to handle opening of the device file
static int calculator_dev_open(struct inode *inode, struct file *file) {
    return 0;   // Return success
}

// Function to handle closing of the device file
static int calculator_dev_release(struct inode *inode, struct file *file) {
    return 0;   // Return success
}

// Function to handle writing to the device file
static ssize_t calculator_dev_write(struct file *file, const char *buf, size_t count, loff_t *ppos) {
    sscanf(buf, "%c %d %d", &operation, &operand1, &operand2);  // input
    switch (operation) {    //  operation based on the input
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 != 0)
                result = operand1 / operand2;
            else
                result = -1; // Division by zero error
            break;
        default:
            return -EINVAL; // Invalid operation
    }
    return count;   // Return the number of bytes written
}

// Function to handle reading from the device file
static ssize_t calculator_dev_read(struct file *file, char *buf, size_t count, loff_t *ppos) {
    int len = 0;
    if (result >= 0) {  // If there is a valid result
        len = snprintf(buf, count, "%d\n", result);  // Format and copy the result to the user buffer
        result = -1; // Reset the result
    }
    return len; // Return the length of data written to the buffer
}

// Structure containing file operations supported by the device
static struct file_operations calculator_dev_fops = {
    .open = calculator_dev_open,
    .release = calculator_dev_release,
    .write = calculator_dev_write,
    .read = calculator_dev_read,
};

// Function to initialize the module
static int __init calculator_dev_init(void) {
    // Register a character device with the kernel
    major_number = register_chrdev(0, DEVICE_NAME, &calculator_dev_fops);
    if (major_number < 0) { // Check if registration failed
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;    // Return the error code
    }
    // Print a message indicating successful registration
    printk(KERN_INFO "Calculator device registered, major number: %d\n", major_number);
    return 0;   // Return success
}

// Function to cleanup and exit the module
static void __exit calculator_dev_exit(void) {
    // Unregister the character device from the kernel
    unregister_chrdev(major_number, DEVICE_NAME);
    // Print a message indicating successful unregistration
    printk(KERN_INFO "Calculator device unregistered\n");
}

// Macro to specify the initialization function of the module
module_init(calculator_dev_init);
// Macro to specify the cleanup function of the module
module_exit(calculator_dev_exit);

// Module information
MODULE_LICENSE("GPL");                  // License type
MODULE_AUTHOR("Dhriti");                // Author
MODULE_DESCRIPTION("Simple calculator device driver");  // Description

