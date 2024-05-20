#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/semaphore.h>
#include <linux/mutex.h>
#include <linux/delay.h> // For msleep

#define DEVICE_NAME "my_device"
#define MAJOR_NUM 240 // Replace with a valid major number if necessary

static dev_t dev_num;
static struct cdev cdev;
static struct semaphore sem;
static DEFINE_MUTEX(mutex);

static irqreturn_t my_irq_handler(int irq, void *dev_id) {
    unsigned long flags;

    // Acquire mutex to protect shared data
    mutex_lock_irqsave(&mutex, flags);

    // Process the interrupt (simulated work)
    printk(KERN_INFO "Interrupt received, processing...\n");
    msleep(1000); // Simulate processing time with msleep

    // Release the mutex
    mutex_unlock_irqrestore(&mutex, flags);

    return IRQ_HANDLED;
}

static int my_device_open(struct inode *inode, struct file *filp) {
    return 0;
}

static long my_device_ioctl(struct file *filp, unsigned int cmd, unsigned long arg) {
    int data;
    unsigned long flags;

    // Validate ioctl command and data (replace with actual validation)
    if (cmd != 0 || copy_from_user(&data, (void __user *)arg, sizeof(data))) {
        return -EFAULT;
    }

    // Acquire semaphore to synchronize access to shared data (illustrative example)
    down(&sem);

    // Raise a soft IRQ (replace with actual work triggered by data)
    raise_softirq(1); // Use the appropriate softirq number

    // Release the semaphore
    up(&sem);

    return 0;
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
        unregister_chrdev_region(dev_num, 1);
        return ret;
    }

    // Request an IRQ for demonstration (replace with actual IRQ usage)
    ret = request_irq(12, my_irq_handler, IRQF_SHARED, DEVICE_NAME, NULL);
    if (ret < 0) {
        cdev_del(&cdev);
        unregister_chrdev_region(dev_num, 1);
        return ret;
    }

    return 0;
}

static void __exit my_module_exit(void) {
    free_irq(12, NULL); // Free the IRQ
    cdev_del(&cdev);
    unregister_chrdev_region(dev_num, 1);
}

module_init(my_module_init);
module_exit(my_module_exit);
MODULE_LICENSE("GPL");
