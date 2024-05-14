#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/sched.h> // For task scheduling
#include <linux/workqueue.h> // For workqueue APIs
#include <linux/slab.h> // For kmalloc and kfree
#include <linux/delay.h>
#define DEVICE_NAME "irq_device"
#define MAJOR_NUM 510  // Replace with a valid major number if necessary

static dev_t dev_num;
static struct cdev cdev;
static struct workqueue_struct *my_workqueue;
static struct work_struct my_work;

static irqreturn_t my_irq_handler(int irq, void *dev_id) {
    // Process the interrupt (simulated work)
    printk(KERN_INFO "Interrupt received, processing...\n");
   msleep(1000); // Simulate processing time

    return IRQ_HANDLED;
}

static int my_device_open(struct inode *inode, struct file *filp) {
    return 0;
}

static long my_device_ioctl(struct file *filp, unsigned int cmd, unsigned long arg) {
    int data;

    // Validate ioctl command and data (replace with actual validation)
    if (cmd != 0 || copy_from_user(&data, (void __user *)arg, sizeof(data))) {
        return -EFAULT;
    }

    // Schedule work for deferred execution
    queue_work(my_workqueue, &my_work);

    return 0;
}

static void my_work_function(struct work_struct *work) {
    printk(KERN_INFO "Work function executed.\n");
    // Perform actual work here
}

static struct file_operations my_fops = {
    .owner = THIS_MODULE,
    .open = my_device_open,
    .unlocked_ioctl = my_device_ioctl,
};

static int __init my_module_init(void) {
    int ret;

    // Register character device
    ret = alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
    if (ret < 0) {
        return ret;
    }

    cdev_init(&cdev, &my_fops);
    ret = cdev_add(&cdev, dev_num, 1);
    if (ret < 0) {
        goto free_dev_region;
    }

    // Create workqueue
    my_workqueue = create_workqueue("my_workqueue");
    if (!my_workqueue) {
        ret = -ENOMEM;
        goto cdev_del;
    }

    // Initialize work
    INIT_WORK(&my_work, my_work_function);

    // Request an IRQ for demonstration (replace with actual IRQ usage)
    ret = request_irq(12, my_irq_handler, IRQF_SHARED, DEVICE_NAME, THIS_MODULE);
    if (ret) {
        goto destroy_workqueue;
    }

    return 0;

destroy_workqueue:
    destroy_workqueue(my_workqueue);
cdev_del:
    cdev_del(&cdev);
    
free_dev_region:
    unregister_chrdev_region(dev_num, 1);
    return ret;
}

static void __exit my_module_exit(void) {
    // Remove IRQ
    free_irq(12, THIS_MODULE);

    // Flush and destroy workqueue
    flush_workqueue(my_workqueue);
    destroy_workqueue(my_workqueue);

    // Remove character device
    cdev_del(&cdev);
    unregister_chrdev_region(dev_num, 1);
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Sample Linux kernel module");
