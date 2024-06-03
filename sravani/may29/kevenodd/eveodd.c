#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>     // kmalloc()
#include <linux/uaccess.h>  // copy_to/from_user()
#include <linux/kthread.h>  // kernel threads
#include <linux/sched.h>    // task_struct 
#include <linux/delay.h>

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;
static struct task_struct *etx_thread;
static struct task_struct *odd_thread;
static struct task_struct *even_thread;

static int odd_thread_function(void *pv);
static int even_thread_function(void *pv);

// File operation function prototypes
static int etx_open(struct inode *inode, struct file *file);
static int etx_release(struct inode *inode, struct file *file);
static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off);
static ssize_t etx_write(struct file *filp, const char __user *buf, size_t len, loff_t *off);

// File operation structure
static struct file_operations fops =
{
    .owner = THIS_MODULE,
    .read = etx_read,
    .write = etx_write,
    .open = etx_open,
    .release = etx_release,
};

// Function to handle opening of the device file
static int etx_open(struct inode *inode, struct file *file)
{
    pr_info("Device File Opened...!!!\n");
    return 0;
}

// Function to handle closing of the device file
static int etx_release(struct inode *inode, struct file *file)
{
    pr_info("Device File Closed...!!!\n");
    return 0;
}

// Function to handle reading from the device file
static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
    pr_info("Read function\n");
    return 0;
}

// Function to handle writing to the device file
static ssize_t etx_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
    pr_info("Write Function\n");
    return len;
}

// Thread function prototype
static int odd_thread_function(void *pv);
static int even_thread_function(void *pv);

// Odd number thread function
static int odd_thread_function(void *pv)
{
    int i = 1;  // Start from 1 for odd numbers
    while (!kthread_should_stop()) {
        pr_info("Odd Thread: %d\n", i);
        i += 2;  // Increment by 2 for next odd number
        msleep(1000); // Sleep for 1 second
    }
    return 0;
}

// Even number thread function
static int even_thread_function(void *pv)
{
    int i = 0;  // Start from 0 for even numbers
    while (!kthread_should_stop()) {
        pr_info("Even Thread: %d\n", i);
        i += 2;  // Increment by 2 for next even number
        msleep(1000); // Sleep for 1 second
    }
    return 0;
}

// Module initialization function
static int __init etx_driver_init(void)
{
    // Allocate major number
    if (alloc_chrdev_region(&dev, 0, 1, "etx_Dev") < 0) {
        pr_err("Cannot allocate major number\n");
        return -1;
    }
    pr_info("Major = %d Minor = %d \n", MAJOR(dev), MINOR(dev));

    // Initialize cdev structure
    cdev_init(&etx_cdev, &fops);

    // Add character device to the system
    if (cdev_add(&etx_cdev, dev, 1) < 0) {
        pr_err("Cannot add the device to the system\n");
        goto r_class;
    }

    // Create struct class
    if (IS_ERR(dev_class = class_create("etx_class"))) {
        pr_err("Cannot create the struct class\n");
        goto r_class;
    }

    // Create device
    if (IS_ERR(device_create(dev_class, NULL, dev, NULL, "etx_device"))) {
        pr_err("Cannot create the Device \n");
        goto r_device;
    }

    // Create odd number thread
    odd_thread = kthread_create(odd_thread_function, NULL, "Odd Thread");
    if (IS_ERR(odd_thread)) {
        pr_err("Cannot create odd thread\n");
        goto r_device;
    } else {
        wake_up_process(odd_thread);
    }

    // Create even number thread
    even_thread = kthread_create(even_thread_function, NULL, "Even Thread");
    if (IS_ERR(even_thread)) {
        pr_err("Cannot create even thread\n");
        goto r_device;
    } else {
        wake_up_process(even_thread);
    }

    pr_info("Device Driver Insert...Done!!!\n");
    return 0;

r_device:
    device_destroy(dev_class, dev);
r_class:
    class_destroy(dev_class);
    unregister_chrdev_region(dev, 1);
    cdev_del(&etx_cdev);
    return -1;
}

// Module exit function
static void __exit etx_driver_exit(void)
{
    // Stop odd and even threads
    kthread_stop(odd_thread);
    kthread_stop(even_thread);

    // Destroy device and class
    device_destroy(dev_class, dev);
    class_destroy(dev_class);

    // Delete cdev structure and unregister major number
    cdev_del(&etx_cdev);
    unregister_chrdev_region(dev, 1);

    pr_info("Device Driver Remove...Done!!\n");
}

// Register module initialization and exit functions
module_init(etx_driver_init);
module_exit(etx_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("techdhaba");
