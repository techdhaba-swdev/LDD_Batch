#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h> 
#include <linux/uaccess.h> 

#define DEVICE_NAME "char_dev"
#define BUF_SIZE 1024

static char my_buffer[BUF_SIZE];


static int mychardev_open(struct inode *inode, struct file *file) 
{
  
    printk(KERN_INFO "Device opened :\n");
    return 0;
}

static ssize_t mychardev_read(struct file *file, char __user *buf, size_t len, loff_t *offset) 
{
    if (copy_to_user(buf, my_buffer, len))
        return -EFAULT;
    return len;
}

static ssize_t mychardev_write(struct file *file, const char __user *buf, size_t len, loff_t *offset) 
{
    if (copy_from_user(my_buffer, buf, len))
        return -EFAULT;
    return len;
}

static int mychardev_release(struct inode *inode, struct file *file) 
{
    
    printk(KERN_INFO "Device closed :\n");
    return 0;
}

static struct file_operations mychardev_fops = 
{
    .owner = THIS_MODULE,
    .open = mychardev_open,
    .read = mychardev_read,
    .write = mychardev_write,
    .release = mychardev_release,
};

static int __init mychardev_init(void) 
{
    register_chrdev(0, DEVICE_NAME, &mychardev_fops);
    printk(KERN_INFO "Character device registered\n");
    return 0;
}

static void __exit mychardev_exit(void) 
{
    unregister_chrdev(0, DEVICE_NAME);
    printk(KERN_INFO "Character device unregistered\n");
}

module_init(mychardev_init);
module_exit(mychardev_exit);
MODULE_LICENSE("GPL");
