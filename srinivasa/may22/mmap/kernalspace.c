#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "calc_device"
#define BUF_SIZE 256

static char kernel_buffer[BUF_SIZE];
static int result;

static int dev_open(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int dev_release(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
    int error_count = 0;
    error_count = copy_to_user(buffer, &result, sizeof(result));
    if (error_count == 0) {
        printk(KERN_INFO "Sent %d characters to the user\n", sizeof(result));
        return sizeof(result);
    } else {
        printk(KERN_INFO "Failed to send data to the user\n");
        return -EFAULT;
    }
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
    int num1, num2;
    sscanf(buffer, "%d+%d", &num1, &num2);
    result = num1 + num2;
    printk(KERN_INFO "Calculation result: %d\n", result);
    return len;
}

static struct file_operations fops = {
    .open = dev_open,
    .read = dev_read,
    .write = dev_write,
    .release = dev_release,
};

static int __init calc_init(void) {
    printk(KERN_INFO "Initializing the calc module\n");
    register_chrdev(0, DEVICE_NAME, &fops);
    return 0;
}

static void __exit calc_exit(void) {
    unregister_chrdev(0, DEVICE_NAME);
    printk(KERN_INFO "Exiting the calc module\n");
}

module_init(calc_init);
module_exit(calc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple calculator kernel module");
