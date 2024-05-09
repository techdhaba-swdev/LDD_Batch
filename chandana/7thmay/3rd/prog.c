#include <linux/init.h>//module initialization
#include <linux/module.h>//for module related macros
#include <linux/fs.h>//for file system related functions and structures
#include <linux/uaccess.h>//for user space memory access
#include <linux/random.h>//for random number generation functions

#define DEVICE_NAME "randomdev"//defines a macro device name with the value randomdev used to name device

//specify license,author and description of the module
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple random number device driver");

//declares a static integer variable Major to store device number
static int Major;

//this is a open function for a device called when device is open
static int device_open(struct inode *inode, struct file *file)
{
	//message to kernal log
    printk(KERN_INFO "Device opened\n");
    return 0;
}

//this is a release function called when device is closed
static int device_release(struct inode *inode, struct file *file)
{
	//message to kernal log
    printk(KERN_INFO "Device closed\n");
    return 0;
}

//this is a read function for the device 
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
    int bytes_read;
    get_random_bytes(&bytes_read, sizeof(int));
    bytes_read %= 1000; // Limit to 0-999 for simplicity

    if (copy_to_user(buffer, &bytes_read, sizeof(int)) != 0) {
        return -EFAULT; // Error while copying data to user space
    }

    return sizeof(int);
}

//defines a structure file_operations named fops
static struct file_operations fops = {
    .read = device_read,
    .open = device_open,
    .release = device_release,
};

//this is module initialization function 
static int __init randomdev_init(void)
{
	//register the device
    Major = register_chrdev(0, DEVICE_NAME, &fops);
    if (Major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", Major);
        return Major;
    }
    printk(KERN_INFO "Registered char device with major number %d\n", Major);
    return 0;
}

//this is module exit function it unregister the device
static void __exit randomdev_exit(void)
{
    unregister_chrdev(Major, DEVICE_NAME);
    printk(KERN_INFO "Unregistered char device\n");
}

//functions called when module is loaded
module_init(randomdev_init);
//function called when module is unloaded
module_exit(randomdev_exit);
