#include <linux/init.h>       // module initialization and cleanup
#include <linux/module.h>     // kernel modules
#include <linux/fs.h>         // Linux file system support
#include <linux/uaccess.h>    // user space access functions

#define DEVICE_NAME "chardev" // Name for the device
#define BUF_LEN 80            // Length of the message buffer

MODULE_LICENSE("GPL");        // License for the module
MODULE_AUTHOR("Your Name");   // Author of the module
MODULE_DESCRIPTION("A simple character device driver"); // Description of the module

static int Major;             // Major number for the device
static char msg[BUF_LEN];     // Message buffer
static char *msg_Ptr;         // Pointer to the message buffer

// Function called when the device is opened
static int device_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device opened\n");  // Print message indicating device is opened
    return 0;                             
}

// Function called when the device is closed
static int device_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device closed\n");  // Print message indicating device is closed
    return 0;                             
}

// Function called when data is read from the device
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
    int bytes_read = 0;                     // Number of bytes read

    if (*msg_Ptr == 0)                      // If end of message is reached
        return 0;                           // Return 0

    while (length && *msg_Ptr) {            // While there is space in the buffer and message is not fully read
        put_user(*(msg_Ptr++), buffer++);   // Copy message byte by byte from kernel space to user space
        length--;                           // Decrement length
        bytes_read++;                       // Increment bytes_read
    }

    return bytes_read;                      // Return number of bytes read
}

// Function called when data is written to the device
static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset)
{
    int bytes_written = 0;                  // Number of bytes written

    if (length > BUF_LEN)                   // If length of data exceeds buffer length
        return -EINVAL;                     // Return error

    memset(msg, 0, BUF_LEN);                // Clear the message buffer
    strncpy(msg, buffer, length);           // Copy data from user space buffer to message buffer
    msg_Ptr = msg;                          // Set pointer to the message buffer
    bytes_written = length;                 // Set number of bytes written

    return bytes_written;                   // Return number of bytes written
}

// Structure that defines file operations for the device
static struct file_operations fops = {
    .read = device_read,                   // Function pointer for reading from the device
    .write = device_write,                 // Function pointer for writing to the device
    .open = device_open,                   // Function pointer for opening the device
    .release = device_release,             // Function pointer for releasing the device
};

// Function called during module initialization
static int __init chardev_init(void)
{
    Major = register_chrdev(0, DEVICE_NAME, &fops);  // Register character device with the kernel
    if (Major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", Major);  // Print error message if registration fails
        return Major;                    // Return error code
    }
    printk(KERN_INFO "Registered char device with major number %d\n", Major);   // Print message indicating successful registration
    return 0;                            
}

// Function called during module cleanup
static void __exit chardev_exit(void)
{
    unregister_chrdev(Major, DEVICE_NAME);   // Unregister character device from the kernel
    printk(KERN_INFO "Unregistered char device\n");  // Print message indicating device is unregistered
}

module_init(chardev_init);    // Macro to specify initialization function
module_exit(chardev_exit);    // Macro to specify cleanup function



