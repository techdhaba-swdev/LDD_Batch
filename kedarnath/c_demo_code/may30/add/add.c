#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "addition_device"
#define BUF_LEN 80

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple character device driver for addition");
MODULE_VERSION("0.1");

static int major;
static char msg[BUF_LEN];
static char *msg_ptr;

static int device_open(struct inode *inode, struct file *file)
{
    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    return 0;
}

static ssize_t device_read(struct file *filep, char *buffer, size_t len, loff_t *offset)
{
    int bytes_read = 0;
    if (*msg_ptr == 0)
        return 0;

    while (len && *msg_ptr) {
        put_user(*(msg_ptr++), buffer++);
        len--;
        bytes_read++;
    }
    return bytes_read;
}

static ssize_t device_write(struct file *filep, const char *buffer, size_t len, loff_t *offset)
{
    int number1, number2, result;

    if (len > BUF_LEN)
        return -EINVAL;

    if (copy_from_user(msg, buffer, len))
        return -EFAULT;

    sscanf(msg, "%d %d", &number1, &number2);

    result = number1 + number2;

    sprintf(msg, "Result of addition: %d\n", result);

    msg_ptr = msg;

    return len;
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release
};

static int __init addition_init(void)
{
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major;
    }
    printk(KERN_INFO "Registered successfully with major number %d\n", major);
    return 0;
}

static void __exit addition_exit(void)
{
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Unregistered successfully\n");
}

module_init(addition_init);
module_exit(addition_exit);




