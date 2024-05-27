#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "simple_char_device"
#define BUFFER_SIZE 256

static dev_t dev_number;
static struct cdev cdev;
static char device_buffer[BUFFER_SIZE] = {0};

static int device_open(struct inode *inode, struct file *filp) {
    printk(KERN_INFO "%s: Device opened\n", DEVICE_NAME);
    return 0;
}

static ssize_t device_write(struct file *filp, const char __user *user_buf,
                            size_t count, loff_t *f_pos) {
    if (count > BUFFER_SIZE - 1) {
        printk(KERN_WARNING "%s: Input exceeds buffer size\n", DEVICE_NAME);
        return -EINVAL;
    }

    if (copy_from_user(device_buffer, user_buf, count)) {
        return -EFAULT;
    }

    device_buffer[count] = '\0'; // Null-terminate the buffer
    printk(KERN_INFO "%s: User data written to buffer\n", DEVICE_NAME);
    return count;
}

static ssize_t device_read(struct file *filp, char __user *user_buf,
                           size_t count, loff_t *f_pos) {
    int bytes_to_read = strlen(device_buffer) - *f_pos;

    if (bytes_to_read <= 0) { // No more data to read
        return 0;
    }

    if (count > bytes_to_read) {
        count = bytes_to_read;
    }

    if (copy_to_user(user_buf, device_buffer + *f_pos, count)) {
        return -EFAULT;
    }

    *f_pos += count; // Update the file position
    return count;
}

static int device_release(struct inode *inode, struct file *filp) {
    printk(KERN_INFO "%s: Device closed\n", DEVICE_NAME);
    return 0;
}

static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .write = device_write,
    .read = device_read,
    .release = device_release,
};

static int __init device_init(void) {
    int result;

    result = alloc_chrdev_region(&dev_number, 0, 1, DEVICE_NAME);
    if (result < 0) {
        printk(KERN_ALERT "%s: Failed to allocate device number\n", DEVICE_NAME);
        return result;
    }

    cdev_init(&cdev, &fops);
    result = cdev_add(&cdev, dev_number, 1);
    if (result < 0) {
        printk(KERN_ALERT "%s: Failed to add cdev\n", DEVICE_NAME);
        unregister_chrdev_region(dev_number, 1);
        return result;
    }

    printk(KERN_INFO "%s: Device registered with major number %d\n", DEVICE_NAME, MAJOR(dev_number));
    return 0;
}

static void __exit device_exit(void) {
    cdev_del(&cdev);
    unregister_chrdev_region(dev_number, 1);
    printk(KERN_INFO "%s: Device unregistered\n", DEVICE_NAME);
}

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple character device driver");
