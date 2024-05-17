#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "string_reverse"


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("String Reverse Device Driver");

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
    char input_string[] = "Hello, World!"; // Replace with user input
    size_t input_length = strlen(input_string);
    
    size_t i;

    // Reverse the string in-place
    for (i = 0; i < input_length / 2; ++i) {
        char temp = input_string[i];
        input_string[i] = input_string[input_length - i - 1];
        input_string[input_length - i - 1] = temp;
    }

    // Copy the reversed string to user space
    if (copy_to_user(buffer, input_string, input_length) != 0) {
        return -EFAULT; // Error while copying data to user space
    }

    return input_length;
}

static struct file_operations fops = {
    .read = device_read,
    .open = device_open,
    .release = device_release,
};


static int major;

static int __init string_reverse_init(void)
{
    int major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering reverse device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Registered reverse device with major number %d\n", major);
    return 0;
}

static void __exit string_reverse_exit(void)
{
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Unregistered reverse device1\n");
}

module_init(string_reverse_init);
module_exit(string_reverse_exit);
