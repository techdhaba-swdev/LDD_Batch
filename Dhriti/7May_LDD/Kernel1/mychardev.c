#include <linux/init.h>        // Module Initialization and cleamup
#include <linux/module.h>      // Modulr definitions
#include <linux/kernel.h>      // Kernel-related functions and printk
#include <linux/fs.h>          // File system support
#include <linux/uaccess.h>     // User space access functions
#include <linux/cdev.h>        // Character device registration functions
#include <linux/string.h>      // String manipulation functions

#define DEVICE_NAME "mychardev"   // Name of the device
static dev_t dev_number;           // Device number
static struct cdev mychardev_cdev; // Character device structure

// Function declaration
static int mychardev_open(struct inode *inode, struct file *file);
static int mychardev_release(struct inode *inode, struct file *file);
static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset);
static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset);

// Structure defining file operations for the device
static struct file_operations mychardev_fops = {  //this struct file operation defines the operation can be peformed on a file
    .owner = THIS_MODULE, //owner of the file operation
    .open = mychardev_open, //open func ptr
    .release = mychardev_release, //release func ptr
    .read = mychardev_read, //read func ptr
    .write = mychardev_write, //write func ptr to device file
};

// to handle device open operation
static int mychardev_open(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device opened\n"); // Log message indicating device is opened
  return 0; // Returning success
}

//  to handle device release operation
static int mychardev_release(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device closed\n"); // Log message indicating device is closed
  return 0; // Returning success
}

//  to handle read from the device
static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset) {
  char message[] = "Hello from the kernel!\n"; // Message to be returned to user
  size_t to_copy = strlen(message); // Calculate length of message

  if (count > to_copy) { // If requested count is more than message length
    count = to_copy; // Set count to message length
  }

  if (copy_to_user(user_buffer, message, count)) { // Copy message to user space from kernel space 
    return -EFAULT; // Return error if copying fails
  }

  return count; // Return number of bytes successfully copied
}

// Function to handle write to the device
static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset) {
  printk(KERN_INFO "MYCHARDEV: Writing not supported\n"); // print message indicating writing is not supported
  return -EOPNOTSUPP; // Return error indicating operation is not supported
}

// Module initialization function
static int __init mychardev_init(void) {
  int ret;

  // Allocate device number dynamically
  ret = alloc_chrdev_region(&dev_number, 0, 1, DEVICE_NAME); //alloc_chrdev_region: this api is used to allocate a range of character device numbers.Contains first device number, a name for device.
  if (ret < 0) {
    return ret; // Return error if allocation fails
  }

  // Initialize character device structure
  cdev_init(&mychardev_cdev, &mychardev_fops); //cdev_init: this api initializes a struct cdev which represents a charc device and file operation callbacks for the device

  // Add character device to the system
  ret = cdev_add(&mychardev_cdev, dev_number, 1); //cdev_add: this api adds the charac device to the system. It associates the device with allocated device numberand make it available foruse.
  if (ret < 0) {
    goto free_dev_num; // Jump to cleanup if adding device fails
  }

  printk(KERN_INFO "MYCHARDEV: Successfully registered character device\n"); // Log message indicating successful registration
  return 0; // Return success

free_dev_num:
  unregister_chrdev_region(dev_number, 1); // Free allocated device number
  return ret; // Return error code
}

// Module exit function
static void __exit mychardev_exit(void) {
  cdev_del(&mychardev_cdev); // Remove character device from the system
  unregister_chrdev_region(dev_number, 1); // Free allocated device number
  printk(KERN_INFO "MYCHARDEV: Module unloaded\n"); // Log message indicating module is unloaded
}

module_init(mychardev_init); // Register module initialization function. it gets called when the module is loded into the kernel.
module_exit(mychardev_exit); // Register module exit function. unloaded from the kernel

MODULE_LICENSE("GPL");          // Module license
MODULE_AUTHOR("Your Name");     // Module author
MODULE_DESCRIPTION("A simple character device driver"); // Module description

