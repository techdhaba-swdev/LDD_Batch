#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define LED_DEV_MAJOR 170
#define LED_DEV_MINOR 0

#define LED_OFF '0'
#define LED_ON '1'

static dev_t led_dev;
static struct cdev led_cdev;
static struct file_operations led_fops; // Structure to hold file operations

static spinlock_t led_lock; // Spinlock for synchronization
static int led_state = 0; // Variable to store LED state

// Open function for the device
static int led_open(struct inode *inode, struct file *filp) {
    return 0; // Allow opening the device
}

// Release function for the device
static int led_release(struct inode *inode, struct file *filp) {
    return 0; // Clean up (no specific resources in this example)
}

// Write function for the device
static ssize_t led_write(struct file *filp, const char __user *user_buf, size_t count, loff_t *f_pos) {
    char value;

    if (count != sizeof(value)) {
        return -EINVAL; // Validate data size
    }

    if (copy_from_user(&value, user_buf, count)) {
        return -EFAULT; // Handle copy_from_user error
    }

    spin_lock(&led_lock);
    led_state = (value == LED_ON) ? 1 : 0; // Update LED state
    spin_unlock(&led_lock);

    printk(KERN_INFO "LED state: %d\n", led_state); // Print LED state to kernel log
    return count;
}

// Read function for the device
static ssize_t led_read(struct file *filp, char __user *user_buf, size_t count, loff_t *f_pos) {
    char value = (led_state == 1) ? LED_ON : LED_OFF; // Get current LED state

    if (copy_to_user(user_buf, &value, sizeof(value))) {
        return -EFAULT; // Handle copy_to_user error
    }

    return sizeof(value);
}

// Module initialization function
static int __init led_driver_init(void) {
    int ret;

    // Allocate a device number
    ret = alloc_chrdev_region(&led_dev, LED_DEV_MINOR, 1, "led_dev");
    if (ret < 0) {
        return ret; // Return error if allocation fails
    }

    // Initialize character device structure
    cdev_init(&led_cdev, &led_fops);

    // Add character device to the kernel
    ret = cdev_add(&led_cdev, led_dev, 1);
    if (ret < 0) {
        goto free_dev; // Jump to cleanup if addition fails
    }

    spin_lock_init(&led_lock); // Initialize spinlock

    printk(KERN_INFO "LED driver initialized\n"); // Print initialization message to kernel log
    return 0;

free_dev:
    unregister_chrdev_region(led_dev, 1); // Free the device number on failure
    return ret; // Return error code
}

// Module exit function
static void __exit led_driver_exit(void) {
    cdev_del(&led_cdev); // Delete character device from the kernel
    unregister_chrdev_region(led_dev, 1); // Unregister the device number
    printk(KERN_INFO "LED driver exited\n"); // Print exit message to kernel log
}

// Specify the initialization and exit functions
module_init(led_driver_init);
module_exit(led_driver_exit);

// Module metadata
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Virtual LED Driver");

