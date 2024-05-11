#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>

#define DEVICE_NAME "addition"
#define BUFFER_SIZE 1024

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple kernel module to add two numbers");

static int major_number;
static char buffer[BUFFER_SIZE];
static int buffer_length;
static DEFINE_MUTEX(addition_mutex);

static int addition_open(struct inode *inode, struct file *file) {
    mutex_lock(&addition_mutex);
    return 0;
}

static int addition_release(struct inode *inode, struct file *file) {
    mutex_unlock(&addition_mutex);
    return 0;
}

static ssize_t addition_read(struct file *file, char *data, size_t length, loff_t *offset) {
    int bytes_read = 0;
    if (*offset == 0) {
        if (copy_to_user(data, buffer, buffer_length) != 0) {
            return -EFAULT;
        }
        bytes_read = buffer_length;
        *offset = buffer_length;
    }
    return bytes_read;
}

static ssize_t addition_write(struct file *file, const char *data, size_t length, loff_t *offset) {
    int result;
    int num1, num2;

    if (copy_from_user(buffer, data, length) != 0) {
        return -EFAULT;
    }

    buffer[length] = '\0';
    sscanf(buffer, "%d %d", &num1, &num2);

    result = num1 + num2;
    snprintf(buffer, BUFFER_SIZE, "Result: %d\n", result);
    buffer_length = strlen(buffer);

    return length;
}

static struct file_operations addition_fops = {
    .open = addition_open,
    .release = addition_release,
    .read = addition_read,
    .write = addition_write,
};

static int __init addition_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &addition_fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Registered correctly with major number %d\n", major_number);
    mutex_init(&addition_mutex);
    return 0;
}

static void __exit addition_exit(void) {
    mutex_destroy(&addition_mutex);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Unregistered the device\n");
}

module_init(addition_init);
module_exit(addition_exit);

