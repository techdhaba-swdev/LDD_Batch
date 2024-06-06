#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/uaccess.h>
#include<linux/cdev.h>
#include<linux/slab.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/err.h>
#include<linux/kdev_t.h>
#include<linux/init.h>

#define mem_size 1024
#define DEVICE_NAME "simple_char_driver"

dev_t dev;
static int major;
uint8_t *kernel_buffer;
static struct cdev dev_cdev;
static char kernel_buff[mem_size];
static int dev_open(struct inode *inode,struct file *file);
static int dev_release(struct inode *inode,struct file *file);
static ssize_t dev_read(struct file *filp,char __user *buff,size_t len,loff_t *off);
static ssize_t dev_write(struct file *filp,const char *buff,size_t len,loff_t *off);
static int __init dev_init(void);
static void __exit dev_exit(void);

static struct file_operations fops={
	.owner=THIS_MODULE,
	.read=dev_read,
	.write=dev_write,
	.open=dev_open,
	.release=dev_release,
};

static int dev_open(struct inode *inode,struct file *file){
	if((kernel_buffer=kmalloc(mem_size,GFP_KERNEL))==0){
		pr_err("Cannot allocate memory");
		return -1;
	}
	pr_info("Memory allocation done");
	return 0;
}

static int dev_release(struct inode *inode,struct file *file){
	kfree(kernel_buffer);
	pr_info("Memory is set free");
	return 0;
}

static ssize_t dev_read(struct file *filp,char *buff,size_t len,loff_t *off){
	copy_to_user(buff,kernel_buff,mem_size);
	pr_info("Device reading is done");
	return mem_size;
}

static ssize_t dev_write(struct file *filp,const char *buff,size_t len,loff_t *off){
	copy_from_user(kernel_buff,buff,len);
	pr_info("Device write is done");
	return len;
}

static int __init dev_init(void){
	major=alloc_chrdev_region(&dev,0,1,DEVICE_NAME);
	if(major<0){
		pr_err("Cannot register device");
		return -1;
	}
	cdev_init(&dev_cdev,&fops);
	if(cdev_add(&dev_cdev,dev,1)<0){
		pr_err("Cannot add device");
		goto r_class;
	}
	pr_info("Major = %d , Minor = %d",MAJOR(dev),MINOR(dev));
	pr_info("Device insertion done");
	return 0;
r_class:
	unregister_chrdev_region(dev,1);
	return -1;
}

static void __exit dev_exit(void){
	kfree(kernel_buffer);
	cdev_del(&dev_cdev);
	unregister_chrdev_region(dev,1);
	pr_info("Device is removed");
}

module_init(dev_init);
module_exit(dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SARATH M");
MODULE_DESCRIPTION("SIMPLE CHAR DRIVER PRACTICE");
