#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>       // kmalloc()
#include <linux/uaccess.h>    // copy_to/from_user()
#include <linux/kthread.h>    // kernel threads
#include <linux/sched.h>      // task_struct 
#include <linux/delay.h>
#include <linux/err.h>

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;

static int __init etx_driver_init(void);
static void __exit etx_driver_exit(void);

static struct task_struct *even_thread;
static struct task_struct *odd_thread;

/*
** Function Prototypes
*/
/** Driver functions ***/
static int etx_open(struct inode *inode, struct file *file);
static int etx_release(struct inode *inode, struct file *file);
static ssize_t etx_read(struct file *filp, 
                char __user *buf, size_t len,loff_t * off);
static ssize_t etx_write(struct file *filp, 
                const char __user *buf, size_t len, loff_t * off);
 /******/

int even_thread_function(void *pv);
int odd_thread_function(void *pv);

/*
** Thread for even numbers
*/
int even_thread_function(void *pv)
{
    int i = 0;
    while(!kthread_should_stop()) {
        pr_info("Even Number: %d\n", i);
        i += 2;
        msleep(1000);
    }
    return 0;
}

/*
** Thread for odd numbers
*/
int odd_thread_function(void *pv)
{
    int i = 1;
    while(!kthread_should_stop()) {
        pr_info("Odd Number: %d\n", i);
        i += 2;
        msleep(1000);
    }
    return 0;
}

/*
** File operation structure
*/ 
static struct file_operations etx_fops =
{
        .owner          = THIS_MODULE,
        .read           = etx_read,
        .write          = etx_write,
        .open           = etx_open,
        .release        = etx_release,
};

/*
** This function will be called when we open the Device file
*/  
static int etx_open(struct inode *inode, struct file *file)
{
        pr_info("Device File Opened...!!!\n");
        return 0;
}

/*
** This function will be called when we close the Device file
*/   
static int etx_release(struct inode *inode, struct file *file)
{
        pr_info("Device File Closed...!!!\n");
        return 0;
}

/*
** This function will be called when we read the Device file
*/
static ssize_t etx_read(struct file *filp, 
                char __user *buf, size_t len, loff_t *off)
{
        pr_info("Read function\n");
 
        return 0;
}

/*
** This function will be called when we write the Device file
*/
static ssize_t etx_write(struct file *filp, 
                const char __user *buf, size_t len, loff_t *off)
{
        pr_info("Write Function\n");
        return len;
}

/*
** Module Init function
*/  
static int __init etx_driver_init(void)
{
        /* Allocating Major number */
        if((alloc_chrdev_region(&dev, 0, 1, "etx_Dev")) <0){
                pr_err("Cannot allocate major number\n");
                return -1;
        }
        pr_info("Major = %d Minor = %d \n", MAJOR(dev), MINOR(dev));
 
        /* Creating cdev structure */
        cdev_init(&etx_cdev, &etx_fops);
 
        /* Adding character device to the system */
        if((cdev_add(&etx_cdev, dev, 1)) < 0){
            pr_err("Cannot add the device to the system\n");
            goto r_class;
        }
 
        /* Creating struct class */
        if(IS_ERR(dev_class = class_create(THIS_MODULE, "etx_class"))){
            pr_err("Cannot create the struct class\n");
            goto r_class;
        }
 
        /* Creating device */
        if(IS_ERR(device_create(dev_class, NULL, dev, NULL, "etx_device"))){
            pr_err("Cannot create the Device \n");
            goto r_device;
        }
 
        /* Creating even thread */
        even_thread = kthread_create(even_thread_function, NULL, "even_thread");
        if(even_thread) {
            wake_up_process(even_thread);
        } else {
            pr_err("Cannot create even thread\n");
            goto r_device;
        }

        /* Creating odd thread */
        odd_thread = kthread_create(odd_thread_function, NULL, "odd_thread");
        if(odd_thread) {
            wake_up_process(odd_thread);
        } else {
            pr_err("Cannot create odd thread\n");
            goto r_device;
        }

        pr_info("Device Driver Insert...Done!!!\n");
        return 0;
 
r_device:
        class_destroy(dev_class);
r_class:
        unregister_chrdev_region(dev, 1);
        cdev_del(&etx_cdev);
        return -1;
}

/*
** Module exit function
*/  
static void __exit etx_driver_exit(void)
{
        kthread_stop(even_thread);
        kthread_stop(odd_thread);
        device_destroy(dev_class, dev);
        class_destroy(dev_class);
        cdev_del(&etx_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver Remove...Done!!\n");
}
 
module_init(etx_driver_init);
module_exit(etx_driver_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ganavi");
MODULE_DESCRIPTION("A simple device driver - Kernel Thread");
MODULE_VERSION("1.14");

