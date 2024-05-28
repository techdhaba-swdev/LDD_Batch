#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define BUFFER_SIZE 1024
#define DEVICE_NAME "basic_char_device"

static char device_buffer[BUFFER_SIZE];
static int device_is_open = 0; // Renamed to avoid conflict

static int device_open(struct inode *inode, struct file *file)
{
    if (device_is_open)
        return -EBUSY;

    device_is_open++;
    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    device_is_open--;
    return 0;
}

static ssize_t device_read(struct file *file, char __user *buffer, size_t length, loff_t *offset)
{
    ssize_t bytes_read = 0;
    if (*offset >= BUFFER_SIZE)
        return 0;

    bytes_read = min(length, (size_t)(BUFFER_SIZE - *offset));

    if (copy_to_user(buffer, device_buffer + *offset, bytes_read) != 0)
        return -EFAULT;

    *offset += bytes_read;
    return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *buffer, size_t length, loff_t *offset)
{
    ssize_t bytes_written = 0;
    if (*offset >= BUFFER_SIZE)
        return -ENOSPC;

    bytes_written = min(length, (size_t)(BUFFER_SIZE - *offset));

    if (copy_from_user(device_buffer + *offset, buffer, bytes_written) != 0)
        return -EFAULT;

    *offset += bytes_written;
    return bytes_written;
}

static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
};

static int __init chardev_init(void)
{
    if (register_chrdev(0, "chardev", &fops) < 0) {
        printk(KERN_ALERT "Failed to register char device\n");
        return -1;
    }
    printk(KERN_INFO "Character device registered\n");
    return 0;
}

static void __exit chardev_exit(void)
{
    unregister_chrdev(0, "chardev");
    printk(KERN_INFO "Character device unregistered\n");
}

module_init(chardev_init);
module_exit(chardev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Basic Character Device Driver");


