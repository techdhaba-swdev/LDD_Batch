#include <linux/init.h> // Include necessary headers
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>

#define DEVICE_NAME "simple_char_driver" // Define device name
#define IOCTL_SET_MSG _IOW('q', 1, char *) // Define ioctl command

static char msg[100] = "Default message from the driver\n"; // Initialize message buffer
static int msg_len = 30; // Initialize message length
static int major; // Declare major number variable

static int device_open(struct inode *inode, struct file *file) { // Function to handle device open
    printk(KERN_INFO "Device opened\n"); // Print message to kernel log
    return 0; // Return success
}

static int device_release(struct inode *inode, struct file *file) { // Function to handle device close
    printk(KERN_INFO "Device closed\n"); // Print message to kernel log
    return 0; // Return success
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) { // Function to read from device
    int bytes_read = 0; // Initialize bytes read counter
    if (*offset >= msg_len) // Check if offset is greater than message length
        return 0; // Return 0 if end of message
    while (length && msg_len) { // Loop until length and message length are non-zero
        put_user(msg[(*offset)++], buffer++); // Copy message data to user buffer
        length--; // Decrement length
        bytes_read++; // Increment bytes read
    }
    return bytes_read; // Return bytes read
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) { // Function to write to device
    int bytes_written = 0; // Initialize bytes written counter
    if (*offset >= 100) // Check if offset is greater than or equal to 100
        return -ENOSPC; // Return error if no space left
    while (length && (*offset < 100)) { // Loop until length is non-zero and offset is less than 100
        get_user(msg[(*offset)++], buffer++); // Copy data from user buffer to message buffer
        length--; // Decrement length
        bytes_written++; // Increment bytes written
    }
    msg_len = *offset; // Update message length
    return bytes_written; // Return bytes written
}

static long device_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param) { // Function to handle ioctl commands
    char *temp; // Declare temporary buffer pointer
    switch (ioctl_num) { // Switch statement based on ioctl command
        case IOCTL_SET_MSG: // Handle IOCTL_SET_MSG command
            temp = (char *)ioctl_param; // Get message from user space
           copy_from_user(msg, temp, 100); // Copy message from user space to kernel space
           printk(KERN_INFO "New message set: %s\n",msg); 
	   msg_len = strlen(msg); // Get new message length
            break; // Exit switch statement
        default: // Default case
            return -EINVAL; // Return invalid argument error
    }
    return 0; // Return success
}

static struct file_operations fops = { // Define file operations structure
    .read = device_read, // Read operation
    .write = device_write, // Write operation
    .open = device_open, // Open operation
    .release = device_release, // Close operation
    .unlocked_ioctl = device_ioctl, // IOCTL operation
};

static int __init char_driver_init(void) { // Initialization function
    major = register_chrdev(0, DEVICE_NAME, &fops); // Register character device
    if (major < 0) { // Check if registration failed
        printk(KERN_ALERT "Failed to register a major number\n"); // Print error message
        return major; // Return error code
    }
    printk(KERN_INFO "Registered correctly with major number %d\n", major); // Print success message
    return 0; // Return success
}

static void __exit char_driver_exit(void) { // Exit function
    unregister_chrdev(major, DEVICE_NAME); // Unregister character device
    printk(KERN_INFO "Unregistered the device\n"); // Print message to kernel log
}

module_init(char_driver_init); // Register initialization function
module_exit(char_driver_exit); // Register exit function

MODULE_LICENSE("GPL"); // Set module license
MODULE_AUTHOR("Your Name"); // Set module author
MODULE_DESCRIPTION("A simple character device driver"); // Set module description
MODULE_VERSION("1.0"); // Set module version


