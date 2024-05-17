#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "reverse_dev"
#define BUFFER_SIZE 100

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple character device driver to reverse a string");

static int Major;
static char msg[BUFFER_SIZE] = {0};
static int msg_len = 0;

static int device_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
    int bytes_to_copy = min(length, (size_t)msg_len);

    if (copy_to_user(buffer, msg, bytes_to_copy) != 0) {
        return -EFAULT; // Error while copying data to user space
    }

    // Clear the message buffer after reading
    memset(msg, 0, sizeof(msg));
    msg_len = 0;

    return bytes_to_copy;
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset)
{
    if (length >= BUFFER_SIZE) {
        printk(KERN_ALERT "Input string is too long\n");
        return -EINVAL; // Invalid argument
    }

    // Copy the input string from user space
    if (copy_from_user(msg, buffer, length) != 0) {
        return -EFAULT; // Error while copying data from user space
    }

    // Reverse the string
    int i, j;
    char temp;
    for (i = 0, j = length - 1; i < j; ++i, --j) {
        temp = msg[i];
        msg[i] = msg[j];
        msg[j] = temp;
    }
    msg_len = length;

    return length;
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

static int __init reverse_string_init(void)
{
    Major = register_chrdev(0, DEVICE_NAME, &fops);
    if (Major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", Major);
        return Major;
    }
    printk(KERN_INFO "Registered char device with major number %d\n", Major);
    return 0;
}

static void __exit reverse_string_exit(void)
{
    unregister_chrdev(Major, DEVICE_NAME);
    printk(KERN_INFO "Unregistered char device\n");
}

module_init(reverse_string_init);
module_exit(reverse_string_exit);
