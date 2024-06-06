// *Single Responsibility Principle*

// A class should have only one job or responsibility.

// Applying this principle in Device Driver

#include <linux/fs.h>
#include <linux/uaccess.h>

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static struct file_operations open_release_fops = {
    .open = device_open,
    .release = device_release,
};



// Register Device
static int __init my_ioctl_init(void) {
    // Register character device and obtain a major number    
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) { // Check if registration failed
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number); // Log the failure
        return major_number; // Return the error code
    }

}

// Unregister device
static void __exit my_ioctl_exit(void) {
    // Remove the cdev structure and unregister the device
    cdev_del(&my_cdev); // Delete the cdev structure
    unregister_chrdev(major_number, DEVICE_NAME); // Unregister the character device
    printk(KERN_INFO "Device unregistered\n"); // Log that the device was unregistered
}


module_init(my_ioctl_init); //Separate Initialization Function

module_exit(my_ioctl_exit); // Separate Cleanup function


