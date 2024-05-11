#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>

#define IOCTL_REVERSE_STRING _IOR('k', 1, int)

#define MAX_STRING_LENGTH 100

static char original_string[MAX_STRING_LENGTH];
static char reversed_string[MAX_STRING_LENGTH];

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

static ssize_t device_read(struct file *file, char __user *buffer, size_t length, loff_t *offset)
{
    int bytes_read = 0;
    if (*offset != 0)
        return 0;

    bytes_read = strlen(reversed_string);
    if (copy_to_user(buffer, reversed_string, bytes_read) != 0)
        return -EFAULT;

    *offset += bytes_read;
    return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *buffer, size_t length, loff_t *offset)
{
    if (length >= MAX_STRING_LENGTH)
        return -EINVAL;

    if (copy_from_user(original_string, buffer, length) != 0)
        return -EFAULT;

    original_string[length] = '\0';
    printk(KERN_INFO "Received string: %s\n", original_string);
    return length;
}

static long device_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param)
{
    switch (ioctl_num) {
        case IOCTL_REVERSE_STRING:
            // Reverse the string
            {
                int i, j;
                int length = strlen(original_string);
                for (i = length - 1, j = 0; i >= 0; --i, ++j)
                    reversed_string[j] = original_string[i];
                reversed_string[j] = '\0';
            }
            printk(KERN_INFO "Reversed string: %s\n", reversed_string);
            break;
        default:
            return -EINVAL;
    }
    return 0;
}

static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
    .unlocked_ioctl = device_ioctl,
};

static int __init reverse_string_init(void)
{
    printk(KERN_INFO "Reverse String: Module loaded\n");
    register_chrdev(0, "reverse_string", &fops);
    return 0;
}

static void __exit reverse_string_exit(void)
{
    unregister_chrdev(0, "reverse_string");
    printk(KERN_INFO "Reverse String: Module unloaded\n");
}

module_init(reverse_string_init);
module_exit(reverse_string_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple kernel module to reverse a string");

