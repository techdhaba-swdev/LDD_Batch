#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SRINU");

#define DEVICE_NAME " double_the_integer"
static int value ;
static int major;
static int double_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO " device opened");
	return 0;
}

static int double_release(struct inode *inode, struct file *file)
{
        printk(KERN_INFO " device closed");
        return 0;
}
 
static ssize_t double_read(struct file *file, static char __user *buffer, size_t length, loff_t *offset)
{
	copy_to_user(buffer, &value, sizeof(int));
	printk(KERN_INFO " DATA SEND TO USER SPACE");
	return sizeof(int);
}
static ssize_t double_write(struct file *file, static char __user *buffer, size_t length, loff_t *offset)
{       
        copy_from_user(&value, buffer, sizeof(int));
        printk(KERN_INFO " DATA recived  TO USER SPACE");
	value = value*2;

        return sizeof(int);
}
static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = double_open,
	.release = double_release,
	.write = double_write,
	.read = double_read,
};
static int __init double_init(void )
{
	major = register_chrdev(0, DEVICE_NAME, &fops);
	printk(KERN_INFO " device registred with major number %d",major);
	return 0;
}

static void __exit double_exit(void )
{
	unregister_chrdev(major, DEVICE_NAME);
	printk(KERN_INFO " device unregistred ");
}

module_init(double_init);
module_exit(double_exit);



