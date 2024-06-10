#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/random.h>

#define DEVICE_NAME "temperature_sensor"
#define MAX_TEMP 100

static int major_num;
static int temp = 0;

// OPEN DEVICE
static int device_open(struct inode *inode, struct file *file) {

    return 0;
}

// RELEASE DEVICE
static int device_release(struct inode *inode, struct file *file) {
    
    return 0;
}

static ssize_t device_read(struct file *file, char *buffer, size_t length, loff_t *offset) {
    
    get_random_bytes(&temp, sizeof(temp));
    temp %= (MAX_TEMP + 1);

    if (copy_to_user(buffer, &temp, sizeof(temp)) != 0) {
        return -EFAULT; 
    }

    return sizeof(temp);
}

static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
    .read = device_read,
};

static int __init device_init(void) {
    major_num = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_num < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_num;
    }
    printk(KERN_INFO "Device Registered correctly with major number %d\n", major_num);
    return 0;
}

static void __exit device_exit(void) {
    unregister_chrdev(major_num, DEVICE_NAME);
    printk(KERN_INFO "Device unregistered\n");
}

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dhriti");
MODULE_DESCRIPTION("A simple Linux character device driver for temperature sensor");
