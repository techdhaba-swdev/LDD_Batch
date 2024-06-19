//Header files for the api,structures....
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>

#define DEVICE_NAME "my_ioctl_device"
#define IOCTL_MAGIC 'k' //Declared magic number (A Unique number used to differentiate IOCTL calls from one another)
#define IOCTL_SET_STRING _IOW(IOCTL_MAGIC, 2, char *) //IOCTL Macros which we use to interact with user(Read and write data)
#define IOCTL_GET_STRING _IOR(IOCTL_MAGIC, 3, char *)

static char kernel_string[100] = {0}; // Buffer to store string from user space

//Open system call(Invokes when user gives open command)
static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}
//Release system call(Invokes when user closes the file)
static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}
//IOCTL system call (when user gives ioctl commands to communicate with kernel)
static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    switch (cmd) {
        case IOCTL_SET_STRING:
            if (copy_from_user(kernel_string, (char __user *)arg, sizeof(kernel_string))) {
                return -EFAULT;
            }
            printk(KERN_INFO "String received: %s\n", kernel_string);
            break;
        case IOCTL_GET_STRING:
            if (copy_to_user((char __user *)arg, kernel_string, sizeof(kernel_string))) {
                return -EFAULT;
            }
            printk(KERN_INFO "String sent to user: %s\n", kernel_string);
            break;
        default:
            return -ENOTTY;
    }
    return 0;
}
//File operation structrue which has system calls which we use in the code
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .unlocked_ioctl = device_ioctl,
};

static int major_number; //Decalared Major number(Which is nothing but id number of the device)
static struct cdev my_cdev; //Declared a char device structrue to represent char device driver(THe structure acts as a layer between user and hardware of the device)

//init api invoked when user initializes the device
static int __init my_ioctl_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops); //registering the major number here by assigning number using refister_chrdev
    if (major_number < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number);
        return major_number;
    }

    cdev_init(&my_cdev, &fops); //Initialized cdev
    my_cdev.owner = THIS_MODULE;
    if (cdev_add(&my_cdev, MKDEV(major_number, 0), 1)) { //registering the  cdev structure 
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ALERT "Adding cdev failed\n");
        return -1;
    }

    printk(KERN_INFO "Device registered with major number %d\n", major_number);
    return 0;
}
//exit api invoked when user deinitializes the device
static void __exit my_ioctl_exit(void) {
    cdev_del(&my_cdev); //deleting the cdev
    unregister_chrdev(major_number, DEVICE_NAME); //unregistering the device
    printk(KERN_INFO "Device unregistered\n");
}
//Macros used to define the initialize and cleanup functions of loadable kernel
module_init(my_ioctl_init);
module_exit(my_ioctl_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sarath M");
MODULE_DESCRIPTION("A simple Linux char driver with ioctl for string set/get");
