#include <linux/init.h>//include the kernal's module initialization and cleanup functions
#include <linux/module.h>//include the module-related macros and functions
#include <linux/kernel.h>//include kernal-related functions and macros
#include <linux/fs.h>//include file system related functions and structures
#include <linux/uaccess.h>//include functions for copying data to/from user space
#include <linux/cdev.h> //include character device related functions and structures
#include <linux/string.h> //include string manipulation functions

#define DEVICE_NAME "mychardev"//define the name for the chaacter device
static dev_t dev_number;//variable to hold the device number
static struct cdev mychardev_cdev;//structure to represent the character device

// Function prototypes
static int mychardev_open(struct inode *inode, struct file *file);//function to handle device open
static int mychardev_release(struct inode *inode, struct file *file);//function to handle device close
static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset);//function to handle read from device
static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset);//function to handle write to device
													////file operations structure

static struct file_operations mychardev_fops = {
    .owner = THIS_MODULE,//owner of the file operations(this module)
    .open = mychardev_open,//pointer to the open function
    .release = mychardev_release,//pointer to the release function
    .read = mychardev_read,//pointer to the read function
    .write = mychardev_write,//pointer to the write function
};
//function to handle device open
static int mychardev_open(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device opened\n");//print a msg to the kernal log
  return 0;//retrun 0 to indicate success
}
//function to handle device close
static int mychardev_release(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device closed\n");//print a msg to the kernal log
  return 0;//return 0 to indicate success
}
//function to handle read from device
static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset) {
  char message[] = "Hello from the kernel!\n";//define a msg to be sent to user space
  size_t to_copy = strlen(message);//get the length of the msg

  if (count > to_copy) {
    count = to_copy;//limit the number of bytes of copy to count if it greater than the msg length
  }

  if (copy_to_user(user_buffer, message, count)) {//copy the msg to user space
    return -EFAULT;//return an error code if the copy fails
  }

  return count;//return the number of bytes copied
}
//function to handle write to device
static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset) {
  printk(KERN_INFO "MYCHARDEV: Writing not supported\n");//printa msg to the kernal log
  return -EOPNOTSUPP;//return an error code to indiacte that writing is not supported
}
//module initialization function
static int __init mychardev_init(void) {
  int ret;

  // Allocate device number
  ret = alloc_chrdev_region(&dev_number, 0, 1, DEVICE_NAME);//alloacte a range of char device numbers
  if (ret < 0) {
    return ret;//return an error code if alloacation fails
  }

  // Initialize character device structure
  cdev_init(&mychardev_cdev, &mychardev_fops);//initialize the cdev structure with file operations

  // Add character device to the system
  ret = cdev_add(&mychardev_cdev, dev_number, 1);//add the character device to the system
  if (ret < 0) {
    goto free_dev_num;//jump to label 'free_dev_num' if cdev_add fails
  }

  printk(KERN_INFO "MYCHARDEV: Successfully registered character device\n");
  return 0;//indicate success 

free_dev_num:
  unregister_chrdev_region(dev_number, 1);//unregister the device number allocation
  return ret;//return the error code
}
//module exit function
static void __exit mychardev_exit(void) {
  cdev_del(&mychardev_cdev);//remove the character device from the system
  unregister_chrdev_region(dev_number, 1);//unregister the device number alloacation
  printk(KERN_INFO "MYCHARDEV: Module unloaded\n");//print a msg to the kernal log
}
//register module initialaization and exit functions
module_init(mychardev_init);//specify the function to be called at module insertion
module_exit(mychardev_exit);//specify the function to be called at module removal

//module information
MODULE_LICENSE("GPL");//set the license of the module
MODULE_AUTHOR("Chandana");//set the author of the module
MODULE_DESCRIPTION("A simple character device driver");//set the description  of the module


