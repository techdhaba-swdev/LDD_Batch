#include <linux/init.h>          // Header file for kernel initialization functions
#include <linux/module.h>        // Header file for kernel module macros
#include <linux/kernel.h>        // Header file for kernel-specific functions and macros
#include <linux/fs.h>            // Header file for file system-related functions and structures
#include <linux/uaccess.h>       // Header file for user-space access functions
#include <linux/cdev.h>          // Header file for character device-related functions and structures
#include <linux/string.h>        // Header file for string manipulation functions

#define DEVICE_NAME "mychardev"  // Define the name of the character device

static dev_t dev_number;         // Variable to store device numbers
static struct cdev mychardev_cdev;  // Structure representing the character device

// Function prototypes
static int mychardev_open(struct inode *inode, struct file *file);
static int mychardev_release(struct inode *inode, struct file *file);
static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset);
static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset);

// Structure to define file operations for the character device
static struct file_operations mychardev_fops = {
    .owner = THIS_MODULE,
    .open = mychardev_open,
    .release = mychardev_release,
    .read = mychardev_read,
    .write = mychardev_write,
};

// Function to handle opening of the character device
static int mychardev_open(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device opened\n");  // Print message indicating device is opened
  return 0;  // Return success
}

// Function to handle closing of the character device
static int mychardev_release(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device closed\n");  // Print message indicating device is closed
  return 0;  // Return success
}

// Function to handle reading from the character device
static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset) {
  char message[] = "Hello from the kernel!\n";  // Define message to be read from the device
  size_t to_copy = strlen(message);  // Determine length of message

  if (count > to_copy) {
    count = to_copy;  // Limit count to the length of the message
  }

  if (copy_to_user(user_buffer, message, count)) {
    return -EFAULT;  // Return error if copy_to_user fails
  }

  return count;  // Return number of bytes read
}

// Function to handle writing to the character device
static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset) {
  printk(KERN_INFO "MYCHARDEV: Writing not supported\n");  // Print message indicating writing is not supported
  return -EOPNOTSUPP;  // Return operation not supported error
}

// Initialization function for the module
static int __init mychardev_init(void) {
  int ret;

  // Allocate device number
  ret = alloc_chrdev_region(&dev_number, 0, 1, DEVICE_NAME);
  if (ret < 0) {
    return ret;  // Return error if allocation fails
  }

  // Initialize character device structure
  cdev_init(&mychardev_cdev, &mychardev_fops);

  // Add character device to the system
  ret = cdev_add(&mychardev_cdev, dev_number, 1);
  if (ret < 0) {
    goto free_dev_num;  // Jump to label to free device number if adding fails
  }

  printk(KERN_INFO "MYCHARDEV: Successfully registered character device\n");  // Print message indicating registration success
  return 0;  // Return success

free_dev_num:
  unregister_chrdev_region(dev_number, 1);  // Free device number allocation
  return ret;  // Return error
}

// Exit function for the module
static void __exit mychardev_exit(void) {
  cdev_del(&mychardev_cdev);  // Delete character device from the system
  unregister_chrdev_region(dev_number, 1);  // Unregister device number
  printk(KERN_INFO "MYCHARDEV: Module unloaded\n");  // Print message indicating module is unloaded
}

module_init(mychardev_init);  // Define module initialization function
module_exit(mychardev_exit);  // Define module exit function

MODULE_LICENSE("GPL");  // Specify module license
MODULE_AUTHOR("BHAVANA");  // Specify module author
MODULE_DESCRIPTION("A simple character device driver");  // Specify module description
