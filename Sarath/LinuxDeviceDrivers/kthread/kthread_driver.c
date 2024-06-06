#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include<linux/slab.h>                 //kmalloc()
#include<linux/uaccess.h>              //copy_to/from_user()
#include <linux/kthread.h>             //kernel threads
#include <linux/sched.h>               //task_struct 
#include <linux/delay.h>
#include <linux/err.h>

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;
 
 int __init etx_driver_init(void);
 void __exit etx_driver_exit(void);
 
static struct task_struct *etx_thread1;
static struct task_struct *etx_thread2;
 
/*
** Function Prototypes
*/
/***** Driver functions ********/
 int etx_open(struct inode *inode, struct file *file);
 int etx_release(struct inode *inode, struct file *file);
 ssize_t etx_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
 ssize_t etx_write(struct file *filp, const char *buf, size_t len, loff_t * off);
 /******************/
 
int thread_function1(void *pv);
int thread_function2(void *pv);
static int i=0;
DEFINE_SPINLOCK(char_spinlock);
/*
** Thread
*/
int thread_function1(void *pv)
{
    while(!kthread_should_stop()) {

	    if(!spin_is_locked(&char_spinlock)){
		    pr_info("Spin is not locked in function 1\n");
	    }
	   spin_lock(&char_spinlock);
	   if(spin_is_locked(&char_spinlock)){
		   pr_info("spin is locked in kthread function 1\n");
	   }
	   i++;
        pr_info("In Thread Function %d\n", i++);
	spin_unlock(&char_spinlock);
        msleep(1000);
	}
    return 0;
}

int thread_function2(void *pv)
{
    while(!kthread_should_stop()) {

            if(!spin_is_locked(&char_spinlock)){
                    pr_info("Spin is not locked in function 2\n");
            }
           spin_lock(&char_spinlock);
           if(spin_is_locked(&char_spinlock)){
                   pr_info("spin is locked in kthread function 2\n");
           }
           i++;
        pr_info("In Thread Function2 -  %d\n", i++);
        spin_unlock(&char_spinlock);
        msleep(1000);
	}
    return 0;
}



/*
** File operation sturcture
*/ 
static struct file_operations fops =
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
 int etx_open(struct inode *inode, struct file *file)
{
        pr_info("Device File Opened...!!!\n");
        return 0;
}

/*
** This function will be called when we close the Device file
*/   
 int etx_release(struct inode *inode, struct file *file)
{
        pr_info("Device File Closed...!!!\n");
        return 0;
}

/*
** This function will be called when we read the Device file
*/
 ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
        pr_info("Read function\n");
 
        return 0;
}

/*
** This function will be called when we write the Device file
*/
 ssize_t etx_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
        pr_info("Write Function\n");
        return len;
}

/*
** Module Init function
*/  
 int __init etx_driver_init(void)
{
        //Allocating Major number
        if((alloc_chrdev_region(&dev, 0, 1, "etx_Dev")) <0){
                pr_err("Cannot allocate major number\n");
                return -1;
        }
        pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));
 
        //Creating cdev structure
        cdev_init(&etx_cdev,&fops);
 
       //Adding character device to the system
        if((cdev_add(&etx_cdev,dev,1)) < 0){
            pr_err("Cannot add the device to the system\n");
            goto r_class;
        }
 
        //Creating struct class
        if(IS_ERR(dev_class = class_create("etx_class"))){
            pr_err("Cannot create the struct class\n");
            goto r_class;
        }
 
        //Creating device
        if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"etx_device"))){
            pr_err("Cannot create the Device \n");
            goto r_device;
        }
 
        etx_thread1 = kthread_create(thread_function1,NULL,"eTx Thread");
        if(etx_thread1) {
            wake_up_process(etx_thread1);
        } else {
            pr_err("Cannot create kthread1\n");
            goto r_device;
        }
        /* You can use this method also to create and run the thread */
        etx_thread2 = kthread_run(thread_function2,NULL,"eTx Thread");
        if(etx_thread2) {
            pr_info("Kthread2 Created Successfully...\n");
        } else {
            pr_err("Cannot create kthread2\n");
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

/*
** Module exit function
*/  
 void __exit etx_driver_exit(void)
{
        kthread_stop(etx_thread1);
	kthread_stop(etx_thread2);
        device_destroy(dev_class,dev);
        class_destroy(dev_class);
        cdev_del(&etx_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver Remove...Done!!\n");
}

module_init(etx_driver_init);
module_exit(etx_driver_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("MS");
MODULE_DESCRIPTION("A simple device driver - Kernel Thread");
//MODULE_VERSION("1.14");
