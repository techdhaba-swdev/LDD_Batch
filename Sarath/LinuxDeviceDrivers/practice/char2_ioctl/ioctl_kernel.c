#include<linux/module.h>
#include<linux/fs.h>
#include<linux/ioctl.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/uaccess.h>
#include<linux/cdev.h>
#include<linux/kdev_t.h>
#define DEVICE_NAME "char_ioctl"
#define MEM_SIZE 4096

//defining ioctl code
#define WR_DATA _IOW('k','0',char *)
#define RD_DATA _IOR('k','1',char *)

//function prototype
static long char_ioctl(struct file *file,unsigned int ioctl_num,unsigned long ioctl_par);
static int device_open(struct inode *inode,struct file *file);
static int device_release(struct inode *inode,struct file *file);
static int __init device_init(void);
static void __exit device_exit(void);
ssize_t bytes_read;
ssize_t bytes_write;
static int *kernel_memory;
static int major;
static char kernel_message[100];
static struct cdev ioctl_cdev;
dev_t dev;
//file structure
static struct file_operations fops={
	.open=device_open,
	.release=device_release,
	.unlocked_ioctl=char_ioctl,
};

//body of API's
//All these functions follow SINGLE RESPONSIBILITY
static int device_open(struct inode *inode,struct file *file){
	if((kernel_memory=kmalloc(MEM_SIZE,GFP_KERNEL))==0){
		printk(KERN_INFO"Memory cannot be allocated");
		return -1;
	}
	printk(KERN_INFO"Device file opened and Memory allocation successfull");
	return 0;
}

static int device_release(struct inode *inode,struct file *file){
	kfree(kernel_memory);
	printk(KERN_INFO"Device is released and Memory is free");
	return 0;
}

static long char_ioctl(struct file *file,unsigned int ioctl_num,unsigned long ioctl_par){
	switch(ioctl_num){
		case WR_DATA:
			bytes_write=copy_from_user(kernel_message,(char __user *)ioctl_par,sizeof(kernel_message));
			printk(KERN_INFO"Message from kernel is %s",kernel_message);
			break;
		case RD_DATA:
			bytes_read=copy_to_user((char __user *)ioctl_par,kernel_message,sizeof(kernel_message));
			printk(KERN_INFO"Read String is %s",kernel_message);
			break;
	}
	return 0;
}

static int __init device_init(void){
	major=alloc_chrdev_region(&dev,0,1,DEVICE_NAME);
	if(major<0){
		printk(KERN_INFO"Device Registration unsuccessfull");
		return -1;
	}
	printk(KERN_INFO"Device Registration successfull with major number %d and minor number %d",MAJOR(dev),MINOR(dev));
	cdev_init(&ioctl_cdev,&fops);
	if(cdev_add(&ioctl_cdev,dev,1)<0){
		printk(KERN_ALERT"Error adding cdev");
		goto r_class;
	}
	return 0;
r_class:
	unregister_chrdev_region(dev,1);
	return -1;
}

static void __exit device_exit(void){
	unregister_chrdev(major,DEVICE_NAME);
	cdev_del(&ioctl_cdev);
	printk(KERN_INFO"Device Unregistered with major %d",major);
}

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MS");
MODULE_DESCRIPTION("A SIMPLE CHAR DRIVER USING IOCTL");
