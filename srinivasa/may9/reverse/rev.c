#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "reverse"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("srinivas");

static int major;
static char message[100];
static int msg_len = 0;

static int device_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO " device opened \n");
	return 0;
}
static int device_release(struct inode *inode, struct file *file) {
       	printk(KERN_INFO "Device closed\n");
        return 0;
}
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
        int error_count = 0;
       	error_count = copy_to_user(buffer, &message, msg_len);
       
        return msg_len;
}
static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    
    copy_from_user(&message, buffer, msg_len);
    int i , j;
    char temp;
    for (i =0, j = length - 1; i < j; i++, j--)
    {
         temp = message[i];
         message[i] = message[j];
         message[j] = temp;
         }
    
    return length;
}

static struct file_operations fops = {
	.read = device_read,
        .write = device_write,
        .open = device_open,
        .release = device_release,
};

static int __init double_integer_init(void) {
       	major = register_chrdev(0, DEVICE_NAME, &fops);
        if (major < 0) {
		printk(KERN_ALERT "Registering char device failed with %d\n", major);
                return major;
         }
	printk(KERN_INFO "reverse: Device registered with major number %d\n", major);
        return 0;
}

static void __exit double_integer_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Double Integer: Device unregistered\n");
}

module_init(double_integer_init);
module_exit(double_integer_exit);
