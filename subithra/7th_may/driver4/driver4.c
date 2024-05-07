#include <linux/init.h>                // Include the initialization header file
#include <linux/module.h>              // Include the module header file
#include <linux/fs.h>                  // Include the file system header file
#include <linux/uaccess.h>             // Include the user access header file

#define DEVICE_NAME "chardev"         // Define the name of the character device
#define BUF_LEN 80                     // Define the length of the message buffer

MODULE_LICENSE("GPL");                // Specify the license under which the module is distributed
MODULE_AUTHOR("Your Name");           // Specify the author of the module
MODULE_DESCRIPTION("A simple character device driver");  // Provide a description of the module

static int Major;                      // Declare a static variable to hold the major number of the registered device
static char msg[BUF_LEN];              // Declare a static array to hold the message buffer
static char *msg_Ptr;                  // Declare a pointer to the message buffer

// Function to handle device open operation
static int device_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device opened\n");   // Log a message indicating the device is opened
    return 0;                              // Return success
}

// Function to handle device close operation
static int device_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device closed\n");   // Log a message indicating the device is closed
    return 0;                              // Return success
}

// Function to handle device read operation
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
    int bytes_read = 0;

    if (*msg_Ptr == 0)
        return 0;                           // If the message buffer is empty, return 0

    while (length && *msg_Ptr) {
        put_user(*(msg_Ptr++), buffer++);  // Copy characters from the message buffer to the user buffer
        length--;
        bytes_read++;
    }

    return bytes_read;                     // Return the number of bytes read
}

// Function to handle device write operation
static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset)
{
    int bytes_written = 0;

    if (length > BUF_LEN)
        return -EINVAL;                    // If the length of the message exceeds the buffer size, return an error

    memset(msg, 0, BUF_LEN);               // Clear the message buffer
    strncpy(msg, buffer, length);          // Copy the message from the user buffer to the message buffer
    msg_Ptr = msg;                         // Set the message pointer to point to the beginning of the message buffer
    bytes_written = length;                // Update the number of bytes written

    return bytes_written;                  // Return the number of bytes written
}

// Define a structure containing pointers to the device's file operation functions
static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

// Initialization function for the module
static int __init chardev_init(void)
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
static void __exit chardev_exit(void)
{
    unregister_chrdev(Major, DEVICE_NAME);  // Unregister the character device
    printk(KERN_INFO "Unregistered char device\n");  // Log a message indicating the device is unregistered
}

module_init(chardev_init);    // Specify the initialization function of the module
module_exit(chardev_exit);    // Specify the cleanup function of the module

	

