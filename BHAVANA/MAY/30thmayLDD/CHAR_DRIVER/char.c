#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>

#define DEVICE_NAME "char_device"
#define BUFFER_SIZE 1024

static int major_number;
static char device_buffer[BUFFER_SIZE];
static struct cdev char_cdev;

static int dev_open(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "char_device: Device opened\n");
    return 0;
}

static int dev_release(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "char_device: Device closed\n");
    return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
    int bytes_read = len;
    if (*offset >= BUFFER_SIZE) return 0;
    if (*offset + len > BUFFER_SIZE) bytes_read = BUFFER_SIZE - *offset;

    if (copy_to_user(buffer, device_buffer + *offset, bytes_read)) {
        return -EFAULT;
    }
    
    *offset += bytes_read;
    printk(KERN_INFO "char_device: Sent %d bytes to the user\n", bytes_read);
    return bytes_read;
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
    int bytes_to_write = len;
    if (*offset >= BUFFER_SIZE) return -EFAULT;
    if (*offset + len > BUFFER_SIZE) bytes_to_write = BUFFER_SIZE - *offset;

    if (copy_from_user(device_buffer + *offset, buffer, bytes_to_write)) {
        return -EFAULT;
    }
    
    *offset += bytes_to_write;
    printk(KERN_INFO "char_device: Received %d bytes from the user\n", bytes_to_write);
    return bytes_to_write;
}

static struct file_operations fops = {
    .open = dev_open,
    .release = dev_release,
    .read = dev_read,
    .write = dev_write,
};

static int __init char_device_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "char_device failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "char_device: registered correctly with major number %d\n", major_number);

    cdev_init(&char_cdev, &fops);
    char_cdev.owner = THIS_MODULE;
    if (cdev_add(&char_cdev, MKDEV(major_number, 0), 1) < 0) {
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ALERT "char_device failed to add cdev\n");
        return -1;
    }
    printk(KERN_INFO "char_device: device class created correctly\n");
    return 0;
}

static void __exit char_device_exit(void) {
    cdev_del(&char_cdev);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "char_device: Goodbye from the LKM!\n");
}

module_init(char_device_init);
module_exit(char_device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author");
MODULE_DESCRIPTION("A simple Linux char driver");
MODULE_VERSION("0.1");
