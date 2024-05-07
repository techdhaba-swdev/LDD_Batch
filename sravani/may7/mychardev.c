#include <linux/init.h> //initialization header
#include <linux/module.h>//require for module initialization and cleanup
#include <linux/kernel.h>//kernel related funtionalities
#include <linux/fs.h>//file system related functionalities
#include <linux/uaccess.h>//user space access utilities
#include <linux/cdev.h> //charecter device regisration
#include <linux/string.h> //string manipulation functions

#define DEVICE_NAME "mychardev"//device name definition
static dev_t dev_number;//device number
static struct cdev mychardev_cdev;//character device structure

// Function prototypes
static int mychardev_open(struct inode *inode, struct file *file);
static int mychardev_release(struct inode *inode, struct file *file);
static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset);
static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset);

//file operation structure
static struct file_operations mychardev_fops = {
    .owner = THIS_MODULE,
    .open = mychardev_open,
    .release = mychardev_release,
    .read = mychardev_read,
    .write = mychardev_write,
};

//function to handle device open operration 
static int mychardev_open(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device opened\n");
  return 0;
}

//function to handle device release operation
static int mychardev_release(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device closed\n");
  return 0;
}

//function to handle device readd operation
static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset) {
  char message[] = "Hello from the kernel!\n";//msg sent to  userspace 
  size_t to_copy = strlen(message);//length of the message

  if (count > to_copy) {
    count = to_copy;//limit count to msg length
  }

  //copy msg to user space
  if (copy_to_user(user_buffer, message, count)) {
    return -EFAULT;//return error if copy fails
  }

  return count;//return number of bytes read
}

//function handle device write operation
static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset) {
  printk(KERN_INFO "MYCHARDEV: Writing not supported\n");
  return -EOPNOTSUPP;//indicating that write operation is not supported
}

//module intialization function
static int __init mychardev_init(void) {
  int ret;

  // Allocate device number
  ret = alloc_chrdev_region(&dev_number, 0, 1, DEVICE_NAME);
  if (ret < 0) {
    return ret;//return error if allocation fails
  }

  // Initialize character device structure
  cdev_init(&mychardev_cdev, &mychardev_fops);

  // Add character device to the system
  ret = cdev_add(&mychardev_cdev, dev_number, 1);
  if (ret < 0) {
    goto free_dev_num;//clean up and return error if addition fails
  }

  printk(KERN_INFO "MYCHARDEV: Successfully registered character device\n");
  return 0;

free_dev_num:
  unregister_chrdev_region(dev_number, 1);//free device number allocation
  return ret;
}

//module exit function
static void __exit mychardev_exit(void) {
  cdev_del(&mychardev_cdev);//remove character device from the syste
  unregister_chrdev_region(dev_number, 1);//free device number allocation
  printk(KERN_INFO "MYCHARDEV: Module unloaded\n");
}
//module initialization and exit macros
module_init(mychardev_init);
module_exit(mychardev_exit);
//module metadata
MODULE_LICENSE("GPL");//license information
MODULE_AUTHOR("Your Name");//author information
MODULE_DESCRIPTION("A simple character device driver");//description of odddule

