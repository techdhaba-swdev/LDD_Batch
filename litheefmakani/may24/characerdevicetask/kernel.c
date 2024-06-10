#include <linux/module.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "mychardev"
#define BUFFER_SIZE 1024

static char device_buffer[BUFFER_SIZE];
static int open_count = 0;

static int mychardev_open(struct inode *inode, struct file *file)
{
    if (open_count > 0)
        return -EBUSY; // Device is already open

    open_count++;
    return 0;
}

static int mychardev_release(struct inode *inode, struct file *file)
{
    open_count--;
    return 0;
}

static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
    // Check if offset is past the end of the buffer
    if (*offset >= BUFFER_SIZE)
        return 0; // End of file

    // Calculate how many bytes can be read from the offset
    size_t bytes_to_read = min(count, (size_t)(BUFFER_SIZE - *offset));

    // Copy data from device buffer to user space
    if (copy_to_user(user_buffer, device_buffer + *offset, bytes_to_read))
        return -EFAULT; // Error copying data to user space

    // Update offset
    *offset += bytes_to_read;

    return bytes_to_read;
}

static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
    // Check if offset is past the end of the buffer
    if (*offset >= BUFFER_SIZE)
        return -ENOSPC; // No space left on device

    // Calculate how many bytes can be written from the offset
    size_t bytes_to_write = min(count, (size_t)(BUFFER_SIZE - *offset));

    // Copy data from user space to device buffer
    if (copy_from_user(device_buffer + *offset, user_buffer, bytes_to_write))
        return -EFAULT; // Error copying data from user space

    // Update offset
    *offset += bytes_to_write;

    return bytes_to_write;
}

static struct file_operations mychardev_fops = {
    .open = mychardev_open,
    .release = mychardev_release,
    .read = mychardev_read,
    .write = mychardev_write,
};

static int __init mychardev_init(void)
{
    // Register the character device
    if (register_chrdev(0, DEVICE_NAME, &mychardev_fops) < 0) {
        printk(KERN_ALERT "Failed to register %s\n", DEVICE_NAME);
        return -1;
    }
    printk(KERN_INFO "Registered %s\n", DEVICE_NAME);
    return 0;
}

static void __exit mychardev_exit(void)
{
    // Unregister the character device
    unregister_chrdev(0, DEVICE_NAME);
    printk(KERN_INFO "Unregistered %s\n", DEVICE_NAME);
}

module_init(mychardev_init);
module_exit(mychardev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A basic character device driver");

