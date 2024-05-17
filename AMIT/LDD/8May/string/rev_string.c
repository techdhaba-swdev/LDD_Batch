#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "rev_dev"

static char message[100] = {0}; // Stores the received string
static int message_len = 0;     // Keeps track of string length

// Function to reverse a string
static void reverse_string(char *str, int len) {
  int start = 0;
  int end = len - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

// Write operation
static ssize_t reverse_dev_write(struct file *filp, const char __user *user_buf,
                                size_t count, loff_t *f_pos) {
  // Check for buffer overflow
  if (count > sizeof(message)) {
    printk(KERN_WARNING "String too long\n");
    return -EINVAL;
  }

  // Copy data from user space to kernel space
  if (copy_from_user(message, user_buf, count)) {
    return -EFAULT;
  }

  message_len = count;
  reverse_string(message, message_len); // Reverse the string

  printk(KERN_INFO "Received string: %s\n", message);
  return count;
}

static const struct file_operations reverse_dev_fops = {
  .owner = THIS_MODULE,
  .write = reverse_dev_write,
};

static int __init reverse_dev_init(void) {
  int ret;

  // Register a character device
  ret = register_chrdev(0, DEVICE_NAME, &reverse_dev_fops);
  if (ret < 0) {
    printk(KERN_ERR "Failed to register character device\n");
    return ret;
  }

  printk(KERN_INFO "Reverse device registered\n");
  return 0;
}

static void __exit reverse_dev_exit(void) {
  unregister_chrdev(0, DEVICE_NAME);
  printk(KERN_INFO "Reverse device unregistered\n");
}

module_init(reverse_dev_init);
module_exit(reverse_dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple character driver for reversing strings");
