#include <linux/init.h> //Initialization & cleanup
#include <linux/module.h> //Kernel Modules
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>

#define DEV_NAME "calculator"
#define BUFF 100

// Structure to hold calculator state
struct calculator {
    int operand1;
    int operand2;
    int result;
    struct mutex mutex; // Mutex to protect shared resources
};



// IOCTL command to set operands
#define CALC_SET_OPERANDS _IOW('c', 1, int[2])

// IOCTL handler function
static long calc_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    int operands[2];

    switch (cmd) {
        case CALC_SET_OPERANDS:
            // Copy operands from user space
            if (copy_from_user(operands, (int *)arg, sizeof(operands))) {
                return -EFAULT;
            }
            // Lock mutex to prevent concurrent access
            mutex_lock(&calc.mutex);
            calc.operand1 = operands[0];
            calc.operand2 = operands[1];
            // Perform addition
            calc.result = calc.operand1 + calc.operand2;
            // Unlock mutex
            mutex_unlock(&calc.mutex);
            break;
        default:
            return -ENOTTY; // Command not supported
    }

    return 0;
}

// File operations structure
static const struct file_operations calc_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = calc_ioctl,
};

static dev_t dev_num;
static struct cdev *char_device;

static int __init calc_init(void) {
    // Initialize mutex
    mutex_init(&calc.mutex);
    // Allocate device number
    if (alloc_chrdev_region(&dev_num, 0, 1, DEV_NAME) < 0) {
        printk(KERN_ERR "Failed to allocate device number\n");
        return -1;
    }
    // Initialize character device structure
    char_device = cdev_alloc();
    if (char_device == NULL) {
        printk(KERN_ERR "Failed to allocate cdev structure\n");
        unregister_chrdev_region(dev_num, 1);
        return -1;
    }
    // Initialize file operations
    cdev_init(char_device, &calc_fops);
    // Add device to system
    if (cdev_add(char_device, dev_num, 1) < 0) {
        printk(KERN_ERR "Failed to add device\n");
        cdev_del(char_device);
        unregister_chrdev_region(dev_num, 1);
        return -1;
    }
    printk(KERN_INFO "Calculator device initialized\n");
    return 0;
}

static void __exit calc_exit(void) {
    // Clean up
    cdev_del(char_device);
    unregister_chrdev_region(dev_num, 1);
    mutex_destroy(&calc.mutex);
    printk(KERN_INFO "Calculator device removed\n");
}

module_init(calc_init);
module_exit(calc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dhriti");
MODULE_DESCRIPTION("Calculator character device driver");




