#include <linux/init.h>         // Include the initialization header file
#include <linux/module.h>       // Include the module header file
#include <linux/fs.h>           // Include the file system header file
#include <linux/uaccess.h>      // Include the user access header file
#include <linux/random.h>       // Include the random number generator header file

#define DEVICE_NAME "randomdev" // Define the name of the random number device

MODULE_LICENSE("GPL");          // Specify the license under which the module is distributed
MODULE_AUTHOR("Your Name");     // Specify the author of the module
MODULE_DESCRIPTION("A simple random number device driver");  // Provide a description of the module

static int Major;               // Declare a static variable to hold the major number of the registered device

// Function to handle device open operation
static int device_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device opened\n");    // Log a message indicating the device is opened
    return 0;                               // Return success
}

// Function to handle device close operation
static int device_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device closed\n");    // Log a message indicating the device is closed
    return 0;                               // Return success
}

// Function to handle device read operation
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
    int bytes_read;
    get_random_bytes(&bytes_read, sizeof(int));  // Generate a random number
    bytes_read %= 1000;                          // Limit the random number to the range 0-999 for simplicity

    if (copy_to_user(buffer, &bytes_read, sizeof(int)) != 0) {
        return -EFAULT;                         // Return an error if there is a problem copying data to user space
    }

    return sizeof(int);                         // Return the size of the data read
}

// Define a structure containing pointers to the device's file operation functions
static struct file_operations fops = {
    .read = device_read,        // Read operation
    .open = device_open,        // Open operation
    .release = device_release,  // Release operation
};

// Initialization function for the module
static int __init randomdev_init(void)
{
    Major = register_chrdev(0, DEVICE_NAME, &fops);  // Register the character device
    if (Major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", Major);  // Log an error message if registration fails
        return Major;
    }
    printk(KERN_INFO "Registered char device with major number %d\n", Major);   // Log a message with the major number if registration is successful
    return 0;                                                                   // Return success
}

// Exit function for the module
static void __exit randomdev_exit(void)
{
    unregister_chrdev(Major, DEVICE_NAME);  // Unregister the character device
    printk(KERN_INFO "Unregistered char device\n");  // Log a message indicating the device is unregistered
}

module_init(randomdev_init);    // Specify the initialization function of the module
module_exit(randomdev_exit);    // Specify the cleanup function of the module
