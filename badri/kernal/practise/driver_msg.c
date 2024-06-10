#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>

#define DEVICE_NAME "msg"
#define LEN 1000

static char msg[LEN];
static int major;

static int device_open(struct inode *inode , struct file *file)
{
printk(KERN_INFO "device opened successfully \n ");
return 0;
}

static int device_release(struct inode *inode , struct file *file)
{
printk(KERN_INFO "device closed successfully\n");
return 0;
}

static ssize_t device_read (struct file *file , char __user *buffer , size_t length , loff_t *offset)
{
if (length > msg[LEN] -1 )
{
length = msg[LEN] -1;
}
if(copy_to_user (buffer , &msg , length) != 0)
{
printk("data read is unsuccessfull\n");
return -EFAULT;
}

msg[LEN] = '\0';
printk("message from user %s \n " , msg);
return length;


}

static ssize_t device_write(struct file *file , const char __user *buffer , size_t length , loff_t *offset)
{
	
if (length > msg[LEN] -1 )
{
length = msg[LEN] -1;
}
if(copy_from_user (&msg , buffer , length) != 0)
{
printk("data write is unsuccessfull\n");
return -EFAULT;
}

msg[LEN] = '\0';
printk("message from user %s \n " , msg);
return length;

}

static struct file_operations fops ={
.open = device_open,
.release = device_release,
.write = device_write,
.read = device_read,
};

static int __init device_start(void)
{
major = register_chrdev(0 , DEVICE_NAME , &fops);
if(major < 0)
{
printk(KERN_INFO "major number not registered successfully \n");
return -1;
}
printk(KERN_INFO "major number registered successfully %d\n " , major);

return 0;
}

static void __exit device_stop(void)
{
unregister_chrdev(major , DEVICE_NAME);
printk(KERN_INFO "device unregistered successfully \n");
}

module_init(device_start);
module_exit(device_stop);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BADRINATH");
MODULE_DESCRIPTION("MESSAGE TO BUFFER");
