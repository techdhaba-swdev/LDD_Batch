#include <linux/init.h>      // Initialization of module and cleanup
#include <linux/module.h>    // specific module funcution
#include <linux/fs.h>        // File system structures
#include <linux/uaccess.h>   // Copy to/from user space functions
#include <linux/random.h>    // Random number generation functions

#define DEVICE_NAME "randomdev"  // Name of the device

MODULE_LICENSE("GPL");              // Module license
MODULE_AUTHOR("Dhriti");         // Module author
MODULE_DESCRIPTION("A simple random number device driver");  // Module description

static int Major;  // Major number for the device

// Function called when the device file is opened
static int device_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device opened\n");  // Print message indicating device file has opened
    return 0;  
}

// Function called when the device file is been closed
static int device_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device closed\n");  // Print message indicating device close
    return 0;  // Return success
}

// Function called when data is read from the device file
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
    int bytes_read;  // Variable to store the random number
    get_random_bytes(&bytes_read, sizeof(int));  // Generate a random number
    bytes_read %= 1000;  // Limit random number to 0-999 for simplicity

    // Copy the random number to the user buffer
    if (copy_to_user(buffer, &bytes_read, sizeof(int)) != 0) {
        return -EFAULT;  // Return error if copying fails
    }

    return sizeof(int);  // Return size of data read
}

static ssize_t device_write(struct file *flip, const char *buffer, size_t length, loff_t  *offset)
{
	printk(KERN_ALERT "Write operation not supported\n");
	return -EINVAL;
}

// Structure defining the file operations for the device
static struct file_operations fops = {
    .read = device_read,    // Read operation
    .write = device_write,
    .open = device_open,        // Open operation
    .release = device_release,  // Release operation
};

// Initialization function called when the module is loaded
static int __init randomdev_init(void)
{
    Major = register_chrdev(0, DEVICE_NAME, &fops);  // Register the character device
    if (Major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", Major);  // Print error message if registration fails
        return Major;  // Return error code
    }
    printk(KERN_INFO "Registered char device with major number %d\n", Major);  // Print message indicating successful registration
    return 0;  // Return success
}


// Cleanup function called when the module is unloaded
static void __exit randomdev_exit(void)
{
    unregister_chrdev(Major, DEVICE_NAME);  // Unregister the character device
    printk(KERN_INFO "Unregistered char device\n");  // Print message indicating device unregister
}

// Define initialization and cleanup functions for the module
module_init(randomdev_init);
module_exit(randomdev_exit);
