#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "mychardev"
#define BUFFER_SIZE 256

static int major_number;
static char buffer[BUFFER_SIZE];
static int buffer_msg = 0;

static int mychardev_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "device opened\n");
    return 0;
}

static int mychardev_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "device closed\n");
    return 0;
}

static ssize_t mychardev_read(struct file *file, char *user_buffer, size_t length, loff_t *offset)
{
    ssize_t bytes_read = 0;
    if (length > buffer_msg)
        length = buffer_msg;
    
    if (copy_to_user(user_buffer, buffer, length) != 0)
        return -EFAULT;

    bytes_read = length;
    buffer_msg = 0; // Reset buffer after reading
    return bytes_read;
}

static ssize_t mychardev_write(struct file *file, const char *user_buffer, size_t length, loff_t *offset)
{
    ssize_t bytes_written = 0;
    if (length > BUFFER_SIZE)
        return -EINVAL;

    if (copy_from_user(buffer, user_buffer, length) != 0)
        return -EFAULT;

    buffer_msg = length;
    bytes_written = length;
    return bytes_written;
}

static struct file_operations mychardev_fops = {
    .open = mychardev_open,
    .release = mychardev_release,
    .read = mychardev_read,
    .write = mychardev_write,
};

static int __init mychardev_init(void){
	major_number = register_chrdev(0, DEVICE_NAME, &mychardev_fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "device registered, major number: %d\n", major_number);
    return 0;
}



static void __exit mychardev_exit(void)
{
    unregister_chrdev(0, DEVICE_NAME);
    printk(KERN_INFO "Unregistered character device %s\n", DEVICE_NAME);
}

module_init(mychardev_init);
module_exit(mychardev_exit);

MODULE_LICENSE("GPL");//license information
MODULE_AUTHOR("Your Name");//author information
MODULE_DESCRIPTION("A simple character device driver");//description of odddule
