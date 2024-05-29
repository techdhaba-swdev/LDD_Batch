
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>                 //kmalloc()
#include <linux/uaccess.h>              //copy_to/from_user()
#include <linux/kthread.h>             //kernel threads
#include <linux/sched.h>               //task_struct
#include <linux/delay.h>
#include <linux/err.h>

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;

static int __init etx_driver_init(void);
static void __exit etx_driver_exit(void);

static struct task_struct *etx_thread;

static int etx_open(struct inode *inode, struct file *file);
static int etx_release(struct inode *inode, struct file *file);
static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t * off);
static ssize_t etx_write(struct file *filp, const char __user *buf, size_t len, loff_t * off);

int thread_function(void *pv);

int thread_function(void *pv)
{
    int i=0;
    while(!kthread_should_stop()) {
        if (i % 2 == 0)
            pr_info("Even Thread Function %d\n", i);
        else
            pr_info("Odd Thread Function %d\n", i);
        i++;
        msleep(1000);
    }
    return 0;
}

static struct file_operations fops =
{
    .owner          = THIS_MODULE,
    .read           = etx_read,
    .write          = etx_write,
    .open           = etx_open,
    .release        = etx_release,
};

static int etx_open(struct inode *inode, struct file *file)
{
    pr_info("Device File Opened...!!!\n");
    return 0;
}

static int etx_release(struct inode *inode, struct file *file)
{
    pr_info("Device File Closed...!!!\n");
    return 0;
}

static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
    pr_info("Read function\n");
    return 0;
}

static ssize_t etx_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
    pr_info("Write Function\n");
    return len;
}

static int __init etx_driver_init(void)
{
    if((alloc_chrdev_region(&dev, 0, 1, "etx_Dev")) <0){
        pr_err("Cannot allocate major number\n");
        return -1;
    }
    pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));

    cdev_init(&etx_cdev,&fops);

    if((cdev_add(&etx_cdev,dev,1)) < 0){
        pr_err("Cannot add the device to the system\n");
        goto r_class;
    }

    dev_class = class_create("etx_class");
    if(IS_ERR(dev_class)) {
        pr_err("Cannot create the struct class\n");
        goto r_class;
    }

    if(device_create(dev_class,NULL,dev,NULL,"etx_device") == NULL) {
        pr_err("Cannot create the Device \n");
        goto r_device;
    }

    etx_thread = kthread_create(thread_function,NULL,"eTx Thread");
    if(etx_thread) {
        wake_up_process(etx_thread);
    } else {
        pr_err("Cannot create kthread\n");
        goto r_device;
    }

    pr_info("Device Driver Insert...Done!!!\n");
    return 0;

r_device:
    class_destroy(dev_class);
r_class:
    unregister_chrdev_region(dev,1);
    cdev_del(&etx_cdev);
    return -1;
}

static void __exit etx_driver_exit(void)
{
    kthread_stop(etx_thread);
    device_destroy(dev_class,dev);
    class_destroy(dev_class);
    cdev_del(&etx_cdev);
    unregister_chrdev_region(dev, 1);
    pr_info("Device Driver Remove...Done!!\n");
}

module_init(etx_driver_init);
module_exit(etx_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kiruthiga");
MODULE_DESCRIPTION("A simple device driver - Kernel Thread");
MODULE_VERSION("1.14");

	

