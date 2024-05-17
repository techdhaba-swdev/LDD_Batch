#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/cdev.h>
#define DEVICE_NAME "add_integer"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");

static int major;
static int value1, value2;
dev_t device_number;
static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    int sum = value1 + value2;
    long sn=copy_to_user(buffer, &sum, sizeof(int));
    printk(KERN_INFO "Sum sent to user space: %d\n", sum);
    return sizeof(int);
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    if (*offset == 0) {
        long n=copy_from_user(&value1, buffer, sizeof(int));
        if(n>0){
        printk(KERN_INFO "First value received from user space: %d\n", value1);
        *offset += sizeof(int);}
    } else {
        long n=copy_from_user(&value2, buffer, sizeof(int));
        if(n>0){
        printk(KERN_INFO "Second value received from user space: %d\n", value2);
        *offset = 0;}
    }
    return sizeof(int);
}
static struct cdev my_cdev;

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

struct class 
static int __init add_integer_init(void) {
    //major = register_chrdev(0, DEVICE_NAME, &fops);
   major =alloc_chrdev_region(&device_number,0,1,"mayur");
   
   
   
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    cdev_init(&my_cdev,&fops) ;
   my_cdev.owner=THIS_MODULE;
   cdev_add(&my_cdev,device_number,1);
    printk(KERN_INFO "Add Integer: Device registered with major number %d\n", major);
    return 0;
}

static void __exit add_integer_exit(void) {
     cdev_del(&my_cdev);
     //unregister_chrdev_region(device_number,1);
    //unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Add Integer: Device unregistered\n");
}

module_init(add_integer_init);
module_exit(add_integer_exit);


