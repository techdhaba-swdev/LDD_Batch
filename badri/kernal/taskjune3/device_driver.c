#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "multiple"

static int major;
static int value;
static int res;

static int device_open(struct inode *inode , struct file *file)
{
	printk(KERN_INFO "device opened successfully\n");
	return 0;
}
static int device_release (struct inode *inode , struct file *file)
{
	printk(KERN_INFO "device closed successfully\n");
	return 0;
}

static ssize_t device_read(struct file *file , char __user *buffer , size_t length , loff_t *offset)
{
if( copy_to_user(buffer , &res , sizeof(int)))
{
	printk(KERN_INFO "not able to copy data to user \n");
	return -EFAULT;
}
 
printk(KERN_INFO "result copied to user space\n");
 return sizeof(int);
}

static ssize_t device_write(struct file *file , const char __user *buffer , size_t length , loff_t *offset)
{
	
	if(copy_from_user(&value , buffer , sizeof(int)) !=0)
	{
		printk("not able to copy data from user \n");
		return -EFAULT;
	}
	printk(KERN_INFO "value copied from userspace is %d\n",value);

	for (int i = 1 ; i<= 10 ; i++)
	{
		 res = value * i;
		printk(KERN_INFO "multiple of 2  %d \n",res);
	}
	
	return sizeof(int);
}

static struct file_operations fops = {
	.open = device_open,
	.read = device_read,
	.write = device_write,
	.release = device_release,
};

static int __init device_start(void)
{
	major = register_chrdev(0 , DEVICE_NAME , &fops);

	if (major < 0 ){
		printk(KERN_INFO "major number is not registered \n");
		return -1 ;
	}
	printk(KERN_INFO "registered with major number for device is %d \n",major);
	return 0;
}

static void __exit device_stop(void)
{
unregister_chrdev(major , DEVICE_NAME);
printk(KERN_INFO " device is unregistered with major number %d\n",major);
}

module_init(device_start);
module_exit(device_stop);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BADRINATH");
MODULE_DESCRIPTION("MULTIPLE OF VALUE");
