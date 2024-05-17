#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/mutex.h>

#define DEVICE_NAME "swap_device"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple device driver for swapping numbers using mutex");
MODULE_VERSION("1.0");

static int major_number;
static struct device* swap_device = NULL;
static DEFINE_MUTEX(swap_mutex);
static int number1 = 0;
static int number2 = 0;

static int swap_open(struct inode *, struct file *);
static int swap_release(struct inode *, struct file *);
static ssize_t swap_read(struct file *, char *, size_t, loff_t *);
static ssize_t swap_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fops = {
    .open = swap_open,
    .read = swap_read,
    .write = swap_write,
    .release = swap_release,
};

static int __init swap_init(void) {
    // Register device driver
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }

    // Create device node
    swap_device = device_create(THIS_MODULE, NULL, MKDEV(major_number, 0), NULL, DEVICE_NAME);
    if (IS_ERR(swap_device)) {
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ALERT "Failed to create the device\n");
        return PTR_ERR(swap_device);
    }

    printk(KERN_INFO "Swap device driver loaded\n");
    return 0;
}

static void __exit swap_exit(void) {
    device_destroy(MKDEV(major_number, 0));
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Swap device driver unloaded\n");
}

static int swap_open(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static ssize_t swap_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
    printk(KERN_INFO "Read operation not supported\n");
    return -EINVAL;
}

static ssize_t swap_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
    int num1, num2;
    if (len < sizeof(int) * 2) {
        printk(KERN_ALERT "Insufficient data\n");
        return -EINVAL;
    }

    if (copy_from_user(&num1, buffer, sizeof(int)) != 0) {
        printk(KERN_ALERT "Failed to copy data from user\n");
        return -EFAULT;
    }
    if (copy_from_user(&num2, buffer + sizeof(int), sizeof(int)) != 0) {
        printk(KERN_ALERT "Failed to copy data from user\n");
        return -EFAULT;
    }

    // Lock mutex
    mutex_lock(&swap_mutex);
    // Swap numbers
    number1 = num2;
    number2 = num1;
    // Unlock mutex
    mutex_unlock(&swap_mutex);

    printk(KERN_INFO "Numbers swapped: %d, %d\n", number1, number2);
    return len;
}

static int swap_release(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

module_init(swap_init);
module_exit(swap_exit);
