#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h> 
#include <linux/string.h> 

#define DEVICE_NAME "mychardev"
static dev_t dev_number;
static struct cdev mychardev_cdev;

// Function prototypes
static int mychardev_open(struct inode *inode, struct file *file);
static int mychardev_release(struct inode *inode, struct file *file);
static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset);
static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset);

static struct file_operations mychardev_fops = {
    .owner = THIS_MODULE,
    .open = mychardev_open,
    .release = mychardev_release,
    .read = mychardev_read,
    .write = mychardev_write,
};

static int mychardev_open(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device opened\n");
  return 0;
}
static int mychardev_release(struct inode *inode, struct file *file) {
  printk(KERN_INFO "MYCHARDEV: Device closed\n");
  return 0;
}

static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset) {
  char message[] = "Hello from the kernel!\n";
  size_t to_copy = strlen(message);

  if (count > to_copy) {
    count = to_copy;
  }

  if (copy_to_user(user_buffer, message, count)) {
    return -EFAULT;
  }

  return count;
}

static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset) {
  printk(KERN_INFO "MYCHARDEV: Writing not supported\n");
  return -EOPNOTSUPP;
}

static int __init mychardev_init(void) {
  int ret;

  // Allocate device number
  ret = alloc_chrdev_region(&dev_number, 0, 1, DEVICE_NAME);
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
  unregister_chrdev_region(dev_number, 1);
  return ret;
}

static void __exit mychardev_exit(void) {
  cdev_del(&mychardev_cdev);
  unregister_chrdev_region(dev_number, 1);
  printk(KERN_INFO "MYCHARDEV: Module unloaded\n");
}

module_init(mychardev_init);
module_exit(mychardev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple character device driver");