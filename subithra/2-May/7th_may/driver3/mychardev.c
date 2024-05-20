#include <linux/init.h> // Include the necessary header files for initialization
#include <linux/module.h> // Include the module related header files
#include <linux/kernel.h> // Include the kernel related header files
#include <linux/fs.h> // Include the file system related header files
#include <linux/uaccess.h> // Include the header file for user space access

#include <linux/cdev.h> // Include cdev header for cdev related functions
#include <linux/string.h> // Include string header for strlen function

#define DEVICE_NAME "mychardev" // Define the name of the device

static dev_t dev_number; // Declare a variable to store device numbers
static struct cdev mychardev_cdev; // Declare a structure for the character device

// Function prototypes
static int mychardev_open(struct inode *inode, struct file *file); // Declare open function prototype
static int mychardev_release(struct inode *inode, struct file *file); // Declare release function prototype
static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset); // Declare read function prototype
static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset); // Declare write function prototype

// Define file operations structure with function pointers
static struct file_operations mychardev_fops = {
    .owner = THIS_MODULE, // Set owner to the current module
    .open = mychardev_open, // Set open function pointer
    .release = mychardev_release, // Set release function pointer
    .read = mychardev_read, // Set read function pointer
    .write = mychardev_write, // Set write function pointer
};

// Implementation of open function
static int mychardev_open(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device opened\n"); // Print a message indicating device opened
  return 0; // Return 0 indicating success
}

// Implementation of release function
static int mychardev_release(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device closed\n"); // Print a message indicating device closed
  return 0; // Return 0 indicating success
}

// Implementation of read function
static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset) {
  char message[] = "Hello from the kernel!\n"; // Define a message to be read
  size_t to_copy = strlen(message); // Get the length of the message

  if (count > to_copy) {
    count = to_copy; // Limit the count to the length of the message
  }

  if (copy_to_user(user_buffer, message, count)) { // Copy message to user space
    return -EFAULT; // Return error if copy fails
  }

  return count; // Return the number of bytes read
}

// Implementation of write function
static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset) {
  printk(KERN_INFO "MYCHARDEV: Writing not supported\n"); // Print a message indicating writing not supported
  return -EOPNOTSUPP; // Return error indicating operation not supported
}

// Module initialization function
static int __init mychardev_init(void) {
  int ret;

  // Allocate device number
  ret = alloc_chrdev_region(&dev_number, 0, 1, DEVICE_NAME); // Allocate a range of char device numbers
  if (ret < 0) {
    return ret; // Return error code if allocation fails
  }

  // Initialize character device structure
  cdev_init(&mychardev_cdev, &mychardev_fops); // Initialize cdev structure with file operations

  // Add character device to the system
  ret = cdev_add(&mychardev_cdev, dev_number, 1); // Add char device to the system
  if (ret < 0) {
    goto free_dev_num; // Jump to cleanup on failure
  }

  printk(KERN_INFO "MYCHARDEV: Successfully registered character device\n"); // Print success message
  return 0; // Return 0 indicating success

free_dev_num:
  unregister_chrdev_region(dev_number, 1); // Free allocated device number on failure
  return ret; // Return error code
}

// Module exit function
static void __exit mychardev_exit(void) {
  cdev_del(&mychardev_cdev); // Delete the cdev structure
  unregister_chrdev_region(dev_number, 1); // Unregister the char device region
  printk(KERN_INFO "MYCHARDEV: Module unloaded\n"); // Print module unload message
}

module_init(mychardev_init); // Register module initialization function
module_exit(mychardev_exit); // Register module exit function

MODULE_LICENSE("GPL"); // Set module license
MODULE_AUTHOR("rps"); // Set module author
MODULE_DESCRIPTION("A simple character device driver"); // Set module description
