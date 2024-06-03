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
static struct task_struct *odd_thread;
static struct task_struct *even_thread;

// Function prototypes
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

// Thread function that runs periodically and prints odd numbers
static int odd_thread_function(void *pv)
{
    int i = 1;
    while (!kthread_should_stop()) {
        pr_info("Odd Number: %d\n", i);
        i += 2;
        msleep(1000); // Sleep for 1 second
    }
    return 0;
}

// Thread function that runs periodically and prints even numbers
static int even_thread_function(void *pv)
{
    int i = 0;
    while (!kthread_should_stop()) {
        pr_info("Even Number: %d\n", i);
        i += 2;
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

    // Create cdev structure
    cdev_init(&etx_cdev, &fops);

    // Adding character device to the system
    if (cdev_add(&etx_cdev, dev, 1) < 0) {
        pr_err("Cannot add the device to the system\n");
        unregister_chrdev_region(dev, 1);
        return -1;
    }

    // Create struct class
    if ((dev_class = class_create("etx_class")) == NULL) {
        pr_err("Cannot create the struct class\n");
        unregister_chrdev_region(dev, 1);
        return -1;
    }

    // Device creation
    if (device_create(dev_class, NULL, dev, NULL, "etx_device") == NULL) {
        pr_err("Cannot create the Device 1\n");
        class_destroy(dev_class);
        return -1;
    }

    // Creating kernel threads
    odd_thread = kthread_run(odd_thread_function, NULL, "ODD_THREAD");
    even_thread = kthread_run(even_thread_function, NULL, "EVEN_THREAD");

    if (odd_thread && even_thread) {
        pr_info("Kernel Threads Created Successfully...\n");
    } else {
        pr_err("Cannot create kernel threads\n");
        return -1;
    }

    return 0;
}

// Module exit function
static void __exit etx_driver_exit(void)
{
    kthread_stop(odd_thread);
    kthread_stop(even_thread);
    device_destroy(dev_class, dev);
    class_destroy(dev_class);
    cdev_del(&etx_cdev);
    unregister_chrdev_region(dev, 1);
    pr_info("Kernel Module Removed Successfully...\n");
}

module_init(etx_driver_init);
module_exit(etx_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("OpenAI");
MODULE_DESCRIPTION("A simple Linux char driver");
