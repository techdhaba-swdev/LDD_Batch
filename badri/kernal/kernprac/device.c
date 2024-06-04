#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/module.h>

#define DEVICE_NAME "buffer"
#define BUF_LEN 1000

static int major;
static char msg[BUF_LEN];

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


static ssize_t device_write (struct file *file , const char __user *buffer , size_t length , loff_t *offset)
{
if(length > sizeof(msg) -1 )
{
printk(KERN_INFO "kernel space lenth exceeds msg length \n");
	length = sizeof(msg) -1;
}
 if(copy_from_user(&msg , buffer , length))
{
printk (KERN_INFO "kernel space failed to read data from user\n");
return -EFAULT;
}
msg[length] = '\0';
printk(KERN_INFO "copied data from user to kernel %s \n" , msg);
return length;
}

static struct file_operations fops = {
.owner = THIS_MODULE,
.open = device_open,
.write = device_write,
.release = device_release,
};

static int __init device_start(void){
major = register_chrdev(0 , DEVICE_NAME , &fops);
if(major < 0)
{
printk(KERN_INFO "major number is not created successfully \n");
return -1;
}
printk("major number for device registered successfully %d \n " , major);
return 0;
}
static void __exit device_stop(void)
{
unregister_chrdev(major , DEVICE_NAME);
printk(KERN_INFO "device unregistered with major number %d successfully \n ",major);

}

module_init(device_start);
module_exit(device_stop);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BADRINATH");
MODULE_DESCRIPTION("READING BUFFER FROM USER");
