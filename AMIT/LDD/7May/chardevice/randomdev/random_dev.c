#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/random.h>

#define DEVICE_NAME "randomdev"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AMIT");
MODULE_DESCRIPTION("A simple random number device driver");

static int Major;

static int device_open(struct inode *inode, struct file *file) //this api called when device is opened
{
    printk(KERN_INFO "Device opened\n");       //print msg indicate that device opened
    return 0;
}

static int device_release(struct inode *inode, struct file *file) //this api called when device is closed
{
    printk(KERN_INFO "Device closed\n");    //print msg indicate that device closed
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) // this api called when user read  device file
{                                                                                     
    int bytes_read;
    get_random_bytes(&bytes_read, sizeof(int));                                            //generate a random number to send it to user
    bytes_read %= 1000; // Limit to 0-999 for simplicity

    if (copy_to_user(buffer, &bytes_read, sizeof(int)) != 0) {                              //copy random number to user space
        return -EFAULT; // Error while copying data to user space
    }

    return sizeof(int);
}

static struct file_operations fops = {         //initialize fops structure
    .read = device_read,                      //fn pointer to read
    .open = device_open,                      //fn pointer to open
    .release = device_release,                //fn pointer to close
};

static int __init randomdev_init(void)       //initialize random_dev function , this fn is called when module is loaded using insmod
{
    Major = register_chrdev(0, DEVICE_NAME, &fops);    //this fn register register char device with kernel
    if (Major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", Major); 
        return Major;
    }
    printk(KERN_INFO "Registered char device with major number %d\n", Major);
    return 0;
}

static void __exit randomdev_exit(void)        //this fn called when module is unload by using rmmod
{
    unregister_chrdev(Major, DEVICE_NAME);      //this fn unregister char device from kernel
    printk(KERN_INFO "Unregistered char device\n");
}

module_init(randomdev_init);  //this macros ensure that module behaves correctly during loading and unloading
module_exit(randomdev_exit);
