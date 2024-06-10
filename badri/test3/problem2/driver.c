#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "temp_sensor"

static int major;

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
	int temp;
	get_random_bytes(&temp , sizeof(int));//get_random_bytes is a function in kernel to generate random bytes of data
	temp = temp % 101;//condition to generate random temp between 0 and 100
   if( copy_to_user(buffer, &temp, sizeof(int)) !=0 )
   {
	   printk(KERN_ALERT "failed to send temperature to user \n");
	   return -EFAULT;
   }
   printk(KERN_INFO "sent temperature %d to the user \n",temp);
   return sizeof(int);
   
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    
    printk(KERN_ALERT " write operation is not implemented\n");
    return -EINVAL; //invalid argument error
         
  }

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

static int __init temp_start(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Double Integer: Device registered with major number %d\n", major);
    return 0;
}

static void __exit temp_end(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Double Integer: Device unregistered\n");
}

module_init(temp_start);
module_exit(temp_end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BADRINATH");
MODULE_DESCRIPTION("SIMPLE CHAR DRIVER FOR TEMPERATURE SENSOR");
