#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/spinlock.h>

static dev_t led_dev;
static struct cdev led_cdev;

// Function prototypes
static int led_open(struct inode *inode, struct file *filp);
static int led_release(struct inode *inode, struct file *filp);
static ssize_t led_write(struct file *filp, const char __user *user_buf,
                         size_t count, loff_t *f_pos);
static ssize_t led_read(struct file *filp, char __user *user_buf,
                        size_t count, loff_t *f_pos);

// File operations structure
static struct file_operations led_fops = {
    .owner = THIS_MODULE,
    .open = led_open,
    .release = led_release,
    .write = led_write,
    .read = led_read,
};

static spinlock_t led_lock; // Spinlock for synchronization
static int led_state = 0; // 0: off, 1: on


static int led_open(struct inode *inode, struct file *filp) {
    return 0; 
}

static int led_release(struct inode *inode, struct file *filp) {
    return 0;
}

// Define the write function
static ssize_t led_write(struct file *filp, const char __user *user_buf,
                         size_t count, loff_t *f_pos) {
    char value;

    if (count != sizeof(value)) {
        return -EINVAL; 
    }

    if (copy_from_user(&value, user_buf, count)) {
        return -EFAULT; 
    }

    spin_lock(&led_lock);
    led_state = (value == '1') ? 1 : 0; // Update state (1: on, 0: off)
    spin_unlock(&led_lock);

    printk(KERN_INFO "LED state: %d\n", led_state);
    return count;
}


static ssize_t led_read(struct file *filp, char __user *user_buf,
                        size_t count, loff_t *f_pos) {
    char value;

    if (count != sizeof(value)) {
        return -EINVAL; 
    }

    spin_lock(&led_lock);
    value = (led_state == 1) ? '1' : '0'; // Read state (1: on, 0: off)
    spin_unlock(&led_lock);

    if (copy_to_user(user_buf, &value, count)) {
        return -EFAULT; 
    }

    return count;
}

// Initialization function
static int __init led_driver_init(void) {
    int ret;

    // Allocate a device number dynamically
    ret = alloc_chrdev_region(&led_dev, 0, 1, "led_dev");
    if (ret < 0) {
        printk(KERN_ERR "Failed to allocate a major number\n");
        return ret;
    }

    // Print the major number to the kernel log
    printk(KERN_INFO "LED driver initialized with major number %d\n", MAJOR(led_dev));

    // Initialize character device structure
    cdev_init(&led_cdev, &led_fops);

    // Add character device to the kernel
    ret = cdev_add(&led_cdev, led_dev, 1);
    if (ret < 0) {
        unregister_chrdev_region(led_dev, 1);
        printk(KERN_ERR "Failed to add cdev\n");
        return ret;
    }

    spin_lock_init(&led_lock); // Initialize spinlock

    return 0;
}

// Exit function
static void __exit led_driver_exit(void) {
    cdev_del(&led_cdev);
    unregister_chrdev_region(led_dev, 1);
    printk(KERN_INFO "LED driver exited\n");
}

module_init(led_driver_init);
module_exit(led_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Virtual LED Driver");
