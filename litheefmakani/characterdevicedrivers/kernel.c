#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "mychardev" // Name of the device

static int major_number; // Variable to store the device number
static char message[256] = {0}; // Memory for the string that is passed from userspace

// Called when a process tries to open the device file
static int device_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device opened\n");
    return 0;
}

// Called when a process closes the device file
static int device_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device closed\n");
    return 0;
}

// Called when a process, which already opened the dev file, attempts to read from it
static ssize_t device_read(struct file *file, char *buffer, size_t length, loff_t *offset)
{
    // Copy the message from kernel space to user space
    int bytes_read = simple_read_from_buffer(buffer, length, offset, message, sizeof(message));
    printk(KERN_INFO "Read %d bytes from the device\n", bytes_read);
    return bytes_read;
}

// Called when a process writes to dev file
static ssize_t device_write(struct file *file, const char *buffer, size_t length, loff_t *offset)
{
    // Copy the message from user space to kernel space
    int bytes_written = simple_write_to_buffer(message, sizeof(message), offset, buffer, length);
    printk(KERN_INFO "Wrote %d bytes to the device\n", bytes_written);
    return bytes_written;
}

// File operations structure defined by Linux kernel
static struct file_operations fops = {
    .open = device_open,
    .read = device_read,
    .write = device_write,
    .release = device_release
};

// Module initialization function
static int __init chardev_init(void)
{
    // Register the device with the kernel
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Registered successfully with major number %d\n", major_number);
    return 0;
}

// Module exit function
static void __exit chardev_exit(void)
{
    // Unregister the device
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Unregistered the device\n");
}

module_init(chardev_init);
module_exit(chardev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple character device driver");
MODULE_VERSION("0.1");
