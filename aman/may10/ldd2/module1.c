#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>

DEFINE_MUTEX(driver_mutex); // Define a mutex

dev_t dev_num;
struct cdev my_cdev;

static ssize_t driver_read(struct file *f, char __user *user_buffer, size_t count, loff_t *offset) {
  // Implement your read functionality here (consider using mutex)
  mutex_lock(&driver_mutex);
  // ... read data and copy to user_buffer ...
  mutex_unlock(&driver_mutex);
  return bytes_read; // Replace with actual number of bytes read
}

static ssize_t driver_write(struct file *f, const char __user *user_buffer, size_t count, loff_t *offset) {
  // Implement your write functionality here (consider using mutex)
  mutex_lock(&driver_mutex);
  // ... copy data from user_buffer ...
  mutex_unlock(&driver_mutex);
  return bytes_written; // Replace with actual number of bytes written
}

static const struct file_operations driver_fops = {
  .owner = THIS_MODULE,
  .read = driver_read,
  .write = driver_write,
};

static int __init driver_init(void) {
  int ret;
  ret = alloc_chrdev_region(&dev_num, 0, 1, "my_device");
  if (ret < 0) {
    return ret;
  }

  cdev_init(&my_cdev, &driver_fops);
  ret = cdev_add(&my_cdev, dev_num, 1);
  if (ret < 0) {
    goto free_dev_num;
  }

  printk(KERN_INFO "Device driver registered\n");
  return 0;

free_dev_num:
  unregister_chrdev_region(dev_num, 1);
  return ret;
}

static void __exit driver_exit(void) {
  cdev_del(&my_cdev);
  unregister_chrdev_region(dev_num, 1);
  printk(KERN_INFO "Device driver unregistered\n");
}

module_init(driver_init);
module_exit(driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple device driver with mutex");
