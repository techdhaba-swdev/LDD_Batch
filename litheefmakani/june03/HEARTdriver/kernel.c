#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>

static dev_t heart_dev;
static struct cdev heart_cdev;

static int heart_open(struct inode *inode, struct file *filp) {
  // Simulate heart rate reading (replace with actual sensor access)
  printk(KERN_INFO "Heart rate: 80 bpm\n");
  return 0;
}

static struct file_operations heart_fops = {
  .owner = THIS_MODULE,
  .open = heart_open,
};

static int __init heart_driver_init(void) {
  int ret;

  ret = alloc_chrdev_region(&heart_dev, 0, 0, "heart_dev");
  if (ret < 0) {
    return ret;
  }

  cdev_init(&heart_cdev, &heart_fops);
  ret = cdev_add(&heart_cdev, heart_dev, 1);
  if (ret < 0) {
    unregister_chrdev_region(heart_dev, 1);
    return ret;
  }

  printk(KERN_INFO "Heart rate driver initialized\n");
  return 0;
}

static void __exit heart_driver_exit(void) {
  cdev_del(&heart_cdev);
  unregister_chrdev_region(heart_dev, 1);
  printk(KERN_INFO "Heart rate driver exited\n");
}

module_init(heart_driver_init);
module_exit(heart_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("litheef");
MODULE_DESCRIPTION("Simple heart rate driver");
