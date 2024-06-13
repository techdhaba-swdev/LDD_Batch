#include <linux/init.h>             
#include <linux/module.h>          
#include <linux/fs.h>               
#include <linux/uaccess.h>          

#define DEVICE_NAME "reverse_string" // The device will appear at /dev/reverse_string using this value
#define BUFFER_SIZE 100              // Buffer size for the device

static char device_buffer[BUFFER_SIZE]; // Buffer to store data written to the device
static int major_number;                // Stores the device number -- determined automatically

// The device open function that is called each time the device is opened
static int device_open(struct inode *inode, struct file *file) {
    return 0; // Successfully opened the device
}

// The device release function that is called whenever the device is closed/released
static int device_release(struct inode *inode, struct file *file) {
    return 0; // Successfully released the device
}

// The device read function that is called when the device is read from user space
static ssize_t device_read(struct file *file, char *buffer, size_t length, loff_t *offset) {
    int bytes_to_copy = BUFFER_SIZE - (int)(*offset);
    if (bytes_to_copy > length) {
        bytes_to_copy = length;
    }
    if (bytes_to_copy == 0) {
        return 0; 
    }
    if (copy_to_user(buffer, device_buffer + *offset, bytes_to_copy)) {
        return -EFAULT; // Failed to copy data to user space
    }
    *offset += bytes_to_copy; // Update the file offset
    return bytes_to_copy; // Return the number of bytes read
}

// The device write function that is called when the device is written to from user space
static ssize_t device_write(struct file *file, const char *buffer, size_t length, loff_t *offset) {
    int bytes_to_write = length;
    if (bytes_to_write > BUFFER_SIZE) {
        bytes_to_write = BUFFER_SIZE; // Ensure we don't overflow the buffer
    }
    if (copy_from_user(device_buffer, buffer, bytes_to_write)) {
        return -EFAULT; // Failed to copy data from user space
    }
    // Reverse the string in the device buffer
    for (int i = 0; i < bytes_to_write / 2; i++) {
        char temp = device_buffer[i];
        device_buffer[i] = device_buffer[bytes_to_write - i - 1];
        device_buffer[bytes_to_write - i - 1] = temp;
    }
    return bytes_to_write; 
}

// A structure containing pointers to the device functions
static struct file_operations fops = {
    .open = device_open,
    .read = device_read,
    .write = device_write,
    .release = device_release,
};


static int __init driver_init(void) {
    // Register the device and obtain a major number dynamically
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Registered correctly with major number %d\n", major_number);
    return 0;
}

static void __exit driver_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME); // Unregister the device
    printk(KERN_INFO "Unregistered the device\n");
}

module_init(driver_init); // Register the initialization function
module_exit(driver_exit); // Register the cleanup function

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dhriti"); 
MODULE_DESCRIPTION("Character Device Driver for Reversing Strings"); 
