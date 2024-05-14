//including all the required headerfiles
#include <linux/init.h>  //build the kernal from the source
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/string.h>
#define DEVICE_NAME "mychardev"
//function declerations
static int mychardev_open(struct inode *inode, struct file *file);
static int mychardev_release(struct inode *inode, struct file *file);
static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset);
static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset);


static dev_t dev_number;   //dev_t is used to hold the device number
static struct cdev mychardev_cdev; //structure encapsulates the file_operations structure
static struct file_operations mychardev_fops = {
    .owner = THIS_MODULE,
    .open = mychardev_open,
    .release = mychardev_release,
    .read = mychardev_read,
    .write = mychardev_write,
};
//function to open
static int mychardev_open(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device opened\n");
  return 0;
}
//function to close the device
static int mychardev_release(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device closed\n");
  return 0;
}
//function to read the message
static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset) {
  char message[] = "Hello from the kernel!\n";
  size_t to_copy = strlen(message);  //size_t is used for a count of bytes
  if (count > to_copy) {
    count = to_copy;
  }
  if (copy_to_user(user_buffer, message, count)) { //copy a block of data into user
    return -EFAULT;
  }
  return count;
}
//function to write the mesaege
static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset) {
  printk(KERN_INFO "MYCHARDEV: Writing not supported\n");
  return -EOPNOTSUPP;
}
//function to inistialize the module
static int __init mychardev_init(void) {
  int ret;
  // Allocate device number
  ret = alloc_chrdev_region(&dev_number, 0, 1, DEVICE_NAME); //allocates the range of char device numbers
  if (ret < 0) {
    return ret;
  }
  // Initialize character device structure
  cdev_init(&mychardev_cdev, &mychardev_fops);

  // Add character device to the system
  ret = cdev_add(&mychardev_cdev, dev_number, 1);
  if (ret < 0) {
    goto free_dev_num;
  }
  printk(KERN_INFO "MYCHARDEV: Successfully registered character device\n");
  return 0;
free_dev_num:
  unregister_chrdev_region(dev_number, 1);  //this function will unregister the range of char device numbers 
  return ret;
}
//function to exit the module
static void __exit mychardev_exit(void) {
  cdev_del(&mychardev_cdev);   //delete the character device from the system
  unregister_chrdev_region(dev_number, 1);//this function will unregister the range of char device numbers
  printk(KERN_INFO "MYCHARDEV: Module unloaded\n");
}
module_init(mychardev_init);
module_exit(mychardev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple character device driver");
