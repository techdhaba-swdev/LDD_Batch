#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/mutex.h>

#define DEVICE_NAME "my_device"
#define MAJOR_NUM 240  // Replace with a valid major number if necessary

static dev_t dev_num;
static struct cdev cdev;
static DEFINE_MUTEX(mutex); // Define a mutex

static irqreturn_t my_irq_handler(int irq, void *dev_id) {
    // No need for mutex in interrupt context
    printk(KERN_INFO "Interrupt received, processing...\n");
    // Simulate processing time
    mdelay(1000); // Use mdelay instead of sleep in interrupt context
    return IRQ_HANDLED;
}

static int my_device_open(struct inode *inode, struct file *filp) {
    return 0;
}

static long my_device_ioctl(struct file *filp, unsigned int cmd, unsigned long arg) {
    int data;
    // Use mutex for synchronization
    mutex_lock(&mutex);

    // Validate ioctl command and data (replace with actual validation)
    if (cmd != 0 || copy_from_user(&data, (void __user *)arg, sizeof(data))) {
        mutex_unlock(&mutex);
        return -EFAULT;
    }

    // Schedule a soft IRQ (replace with actual work triggered by data)
    raise_softirq_irqoff(IRQ_WORK); // Assuming you want to schedule a work queue

    mutex_unlock(&mutex);
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
    ret = request_irq(IRQ_NUMBER, my_irq_handler, IRQF_SHARED, DEVICE_NAME, NULL);
    if (ret) {
        cdev_del(&cdev);
        unregister_chrdev_region(dev_num, 1);
        return ret;
    }

    printk(KERN_INFO "Module initialized successfully\n");
    return 0;
}

static void __exit my_module_exit(void) {
    free_irq(IRQ_NUMBER, NULL);
    cdev_del(&cdev);
    unregister_chrdev_region(dev_num, 1);
    printk(KERN_INFO "Module exited\n");
}

module_init(my_module_init);
module_exit(my_module_exit);
MODULE_LICENSE("GPL");



