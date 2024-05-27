#include<linux/init.h>
#include<linux/module.h>
#include<linux/uaccess.h>
#include<linux/fs.h>

#define DEVICE_NAME "simple_chardev"

static char message[50];
static int major;

MODULE_LICENSE("GPL");
MODULE_AUTHOR("srinivasa");
MODULE_DESCRIPTION("a simple char dev");

static int device_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "device open");
	return 0;
}
static int device_release(struct inode *inode, struct file *file)
{
	printk(KERN_INFO " device close");
	return 0;
}
static ssize_t device_write(struct file *file,const char __user *buffer, size_t length, loff_t *offset)
{
      if (copy_from_user(message, buffer, length))
      {
	      return EFAULT;
      }
      printk(KERN_INFO " message written from user : %s",message);
      return length;

}

static ssize_t device_read(struct file *file, char __user *buffer, size_t length, loff_t *offset)
{       
      if (copy_to_user(buffer,message, length))
      {
              return EFAULT;
      }
      printk(KERN_INFO " message written to user : %s",message);
      return length;

}       



static struct file_operations fops = {
	.open = device_open,
	.release = device_release,
	.read = device_read,
	.write = device_write,
};
static int __init device_init(void)
{
	
	major = register_chrdev(0,DEVICE_NAME,&fops);
	if (major < 0){
		printk(KERN_ALERT " registration failed");
	}
	printk(KERN_INFO " device registered with major number %d",major);
	return 0;
}
static void __exit device_exit(void )
{
	unregister_chrdev(major, DEVICE_NAME);
}
module_init(device_init);
module_exit(device_exit);
