#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/spinlock.h>

#define DEVICE_NAME "data_transfer"
#define DATA_SIZE sizeof(struct user_data)

struct user_data {
  int value;
  char message[20];
};

static dev_t dev_num;
static struct cdev my_cdev;
static spinlock_t my_lock;
static struct user_data kernel_data;

static int my_open(struct inode *inode, struct file *filp) {
  pr_info("Device opened\n");
  return 0;
}

static int my_release(struct inode *inode, struct file *filp) {
  pr_info("Device closed\n");
  return 0;
}

static ssize_t my_write(struct file *filp, const char __user *user_buf,
                       size_t count, loff_t *f_pos) {
  struct user_data data;
  unsigned long flags;

  if (count != DATA_SIZE) {
    pr_err("Invalid data size: %zu, expected %zu\n", count, DATA_SIZE);
    return -EINVAL;
  }

  spin_lock_irqsave(&my_lock, flags);

  if (copy_from_user(&data, user_buf, count)) {
    spin_unlock_irqrestore(&my_lock, flags);
    pr_err("Error copying data from user\n");
    return -EFAULT;
  }

  kernel_data = data;
  pr_info("Received data: value = %d, message = %s\n", data.value, data.message);

  spin_unlock_irqrestore(&my_lock, flags);

  return count;
}

static ssize_t my_read(struct file *filp, char __user *user_buf,
                      size_t count, loff_t *f_pos) {
  unsigned long flags;
  ssize_t ret;

  if (count != DATA_SIZE) {
    pr_err("Invalid data size for read: %zu, expected %zu\n", count, DATA_SIZE);
    return -EINVAL;
  }

  spin_lock_irqsave(&my_lock, flags);

  if (copy_to_user(user_buf, &kernel_data, DATA_SIZE)) {
    spin_unlock_irqrestore(&my_lock, flags);
    pr_err("Error copying data to user\n");
    return -EFAULT;
  }

  ret = DATA_SIZE;
  pr_info("Sent data: value = %d, message = %s\n", kernel_data.value, kernel_data.message);

  spin_unlock_irqrestore(&my_lock, flags);

  return ret;
}

static const struct file_operations my_fops = {
  .owner = THIS_MODULE,
  .open = my_open,
  .release = my_release,
  .write = my_write,
  .read = my_read,
};

static int __init data_transfer_init(void) {
  int ret;

  ret = alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
  if (ret < 0) {
    pr_err("Failed to allocate character device region\n");
    return ret;
  }

  spin_lock_init(&my_lock);
  cdev_init(&my_cdev, &my_fops);

  ret = cdev_add(&my_cdev, dev_num, 1);
  if (ret < 0) {
    unregister_chrdev_region(dev_num, 1);
    return ret;
  }

  pr_info("Device %s created with major number: %u\n", DEVICE_NAME, MAJOR(dev_num));
  return 0;
}

static void __exit data_transfer_exit(void) {
  cdev_del(&my_cdev);
  unregister_chrdev_region(dev_num, 1);
  pr_info("Device %s removed\n", DEVICE_NAME);
}

module_init(data_transfer_init);
module_exit(data_transfer_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Character device for data transfer with spinlock");
