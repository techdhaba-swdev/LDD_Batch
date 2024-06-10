#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/random.h>
#include <linux/cdev.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Virtual Temperature Sensor Device Driver");

// Define the device name and major number
#define DEVICE_NAME "temp_sensor"
#define MAJOR_NUMBER 240

// Define the device structure
typedef struct {
    struct cdev cdev;
    int temperature;
} temp_sensor_dev_t;

static struct cdev temp_sensor_cdev;
static struct class *temp_sensor_class = NULL;

// Function to generate a random temperature value
int generate_temperature(void) {
    unsigned int rand;
    get_random_bytes(&rand, sizeof(rand));
    return rand % 101; // temperature range from 0 to 100
}

// Function to handle read requests
ssize_t temp_sensor_read(struct file *filp, char __user *buf, size_t count, loff_t *ppos) {
    int temperature = generate_temperature();
    char temp_str[10];
    int len = snprintf(temp_str, sizeof(temp_str), "%d\n", temperature);

    if (*ppos != 0) {
        return 0; // EOF
    }

    if (copy_to_user(buf, temp_str, len)) {
        return -EFAULT;
    }

    *ppos = len;
    return len;
}

// Function to handle write requests (not implemented)
ssize_t temp_sensor_write(struct file *filp, const char __user *buf, size_t count, loff_t *ppos) {
    return -EINVAL; // invalid operation, return error
}

// Function to handle device open
int temp_sensor_open(struct inode *inode, struct file *filp) {
    temp_sensor_dev_t *dev = kmalloc(sizeof(temp_sensor_dev_t), GFP_KERNEL);
    if (!dev) {
        return -ENOMEM;
    }
    filp->private_data = dev;
    return 0;
}

// Function to handle device release
int temp_sensor_release(struct inode *inode, struct file *filp) {
    temp_sensor_dev_t *dev = filp->private_data;
    kfree(dev);
    return 0;
}

// File operations structure
static const struct file_operations temp_sensor_fops = {
    .owner = THIS_MODULE,
    .read = temp_sensor_read,
    .write = temp_sensor_write,
    .open = temp_sensor_open,
    .release = temp_sensor_release,
};

// Initialize the module
static int __init temp_sensor_init(void) {
    int result;
    dev_t dev = MKDEV(MAJOR_NUMBER, 0);

    // Register the character device
    result = register_chrdev_region(dev, 1, DEVICE_NAME);
    if (result < 0) {
        printk(KERN_WARNING "temp_sensor: can't get major number %d\n", MAJOR_NUMBER);
        return result;
    }

    cdev_init(&temp_sensor_cdev, &temp_sensor_fops);
    temp_sensor_cdev.owner = THIS_MODULE;
    result = cdev_add(&temp_sensor_cdev, dev, 1);
    if (result) {
        printk(KERN_NOTICE "Error %d adding temp_sensor", result);
        unregister_chrdev_region(dev, 1);
        return result;
    }

    temp_sensor_class = class_create( DEVICE_NAME);
    if (IS_ERR(temp_sensor_class)) {
        cdev_del(&temp_sensor_cdev);
        unregister_chrdev_region(dev, 1);
        printk(KERN_NOTICE "Error creating temp_sensor class");
        return PTR_ERR(temp_sensor_class);
    }

    device_create(temp_sensor_class, NULL, dev, NULL, DEVICE_NAME);

    printk(KERN_INFO "temp_sensor: registered with major number %d\n", MAJOR_NUMBER);
    return 0;
}

// Cleanup the module
static void __exit temp_sensor_exit(void) {
    dev_t dev = MKDEV(MAJOR_NUMBER, 0);

    device_destroy(temp_sensor_class, dev);
    class_destroy(temp_sensor_class);
    cdev_del(&temp_sensor_cdev);
    unregister_chrdev_region(dev, 1);

    printk(KERN_INFO "temp_sensor: unregistered device\n");
}

// Define module initialization and cleanup functions
module_init(temp_sensor_init);
module_exit(temp_sensor_exit);
	

