#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "my_device"
#define BUF_LEN 100

static int major;
static char msg[BUF_LEN];
static int msg_len;

static int device_open(struct inode *inode, struct file *file) {
  return 0;
}

static int device_release(struct inode *inode, struct file *file) {
  return 0;
}

static ssize_t device_write(struct file *file, const char __user *buffer, size_t len, loff_t *offset) {
  if (len > BUF_LEN - 1) {
    printk(KERN_INFO "my_device: input too long\n");
    return -ENOSPC; // Consider using a more specific error code
  }

  if (copy_from_user(msg, buffer, len)) {
    return -EFAULT;
  }

  // Ensure null termination
  msg[len] = '\0';
  msg_len = len;

  printk(KERN_INFO "my_device: received %s\n", msg);
  return len;
}



static struct file_operations fops = {
  .open = device_open,
  .release = device_release,
  .write = device_write,
};

static int __init my_module_init(void) {
  major = register_chrdev(0, DEVICE_NAME, &fops);
  if (major < 0) {
    printk(KERN_ALERT "Registering char device failed with %d\n", major);
    return major;
  }

  printk(KERN_INFO "my_module: device registered with major number %d\n", major);
  return 0;
}

static void __exit my_module_exit(void) {
  unregister_chrdev(major, DEVICE_NAME);
  printk(KERN_INFO "my_module: device unregistered\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A simple kernel module to receive strings from user space");
MODULE_AUTHOR("Your Name");




