/*Question:

Develop a basic character device driver in C for Linux that interacts with a virtual temperature sensor. The driver should:

Create a character device file in the /dev directory
Respond to user-space read requests by returning a random integer between 0 and 100, representing the "temperature"
Implement error handling for invalid operations (e.g., write requests)
Provide appropriate cleanup when the device is unloaded*/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/random.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "sensor_temp"//this is the device name 
#define MAX_TEMP 100// we need to set the maximum temperature is 100

static int major_num;//it stores the major number assigned to the device 
static struct cdev temp_cdev;//structure of character device 

static int temp_open(struct inode *inode, struct file *filp) { //function for device open 
    return 0;
}

static ssize_t temp_read(struct file *filp, char __user *buf, size_t len, loff_t *off) { //it will akes the random value for temperature 
    int temp;
    get_random_bytes(&temp, sizeof(temp));
    temp %= (MAX_TEMP + 1); // Ensure temp is between 0 and MAX_TEMP
    if (copy_to_user(buf, &temp, sizeof(temp))) {
        return -EFAULT; // Error handling for copy_to_user
    }
    return sizeof(temp);
}

static int temp_release(struct inode *inode, struct file *filp) {//function for device close
    return 0;
}

static struct file_operations fops = { //structure that holds pointers to the callback functions 
    .owner = THIS_MODULE,
    .open = temp_open,
    .read = temp_read,
    .release = temp_release,
};

static int __init temp_init(void) { //intialization unction called when the module is loaded
    dev_t dev = 0;
    int ret;

    // Dynamically allocate a major number for the device
    ret = alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME);
    if (ret < 0) {
        printk(KERN_ERR "Failed to allocate major number\n");
        return ret;
    }
    major_num = MAJOR(dev);

    // Initialize the character device structure
    cdev_init(&temp_cdev, &fops);
    temp_cdev.owner = THIS_MODULE;

    // Add the character device to the system
    ret = cdev_add(&temp_cdev, dev, 1);
    if (ret < 0) {
        unregister_chrdev_region(dev, 1);
        printk(KERN_ERR "Failed to add character device\n");
        return ret;
    }

    // Print the allocated major number
    printk(KERN_INFO "Temperature sensor driver loaded. Major number: %d\n", major_num);
    return 0;
}

static void __exit temp_exit(void) {//clean up the function when module is unloaded.
    cdev_del(&temp_cdev);
    unregister_chrdev_region(MKDEV(major_num, 0), 1);//unregisters the allocated major number
    printk(KERN_INFO "Temperature sensor driver unloaded\n");
}

module_init(temp_init);
module_exit(temp_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("litheef");
MODULE_DESCRIPTION("Virtual temperature sensor driver");
