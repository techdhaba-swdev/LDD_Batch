#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/init.h>
#include<linux/uaccess.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/ioctl.h>

#define WR_DATA _IOW('a','1',int)
#define RD_DATA _IOR('a','2',int)
#define mem_size 20
#define DEVICE_NAME "my_dev_ioctl"

static int *kern_buff;
static int major;
static struct cdev my_cdev;
dev_t dev;

static int dev_open(struct inode *inode,struct file *file);
static int dev_release(struct inode *inode,struct file *file);
static long my_ioctl(struct file *file,unsigned int cmd,unsigned long arg);
static int __init dev_init(void);
static void __exit dev_exit(void);

static struct file_operations fops={
	.open=dev_open,
	.release=dev_release,
	.unlocked_ioctl=my_ioctl,
};

static int dev_open(struct inode *inode,struct file *file){
	pr_info("Device opened successfully");
	return 0;
}

static int dev_release(struct inode *inode,struct file *file){
	pr_info("Device released successfully");
	return 0;
}

static int __init dev_init(void){
	major=alloc_chrdev_region(&dev,0,1,DEVICE_NAME);
	cdev_init(&my_cdev,&fops);
	if(cdev_add(&my_cdev,dev,1)<0){
		printk(KERN_ALERT"Cannot add char device");
		goto r_class;
	}
	if(major<0){
		printk(KERN_ALERT"Cannot register the device");
		return -1;
	}
	printk(KERN_INFO"MAJOR %d MINOR %d",MAJOR(dev),MINOR(dev));
	return 0;

r_class:
	unregister_chrdev_region(dev,1);
	return 0;
}

static void __exit dev_exit(void){
	unregister_chrdev_region(dev,1);
	cdev_del(&my_cdev);
	printk(KERN_INFO"Device unregistered successfully");
}

static long my_ioctl(struct file *file,unsigned int cmd,unsigned long arg){
	switch(cmd){
		case WR_DATA:
			copy_from_user(kern_buff,(int *)arg,mem_size);
			printk(KERN_INFO"Data written successfully in kernel which is %d",kern_buff);
			break;
		case RD_DATA:
			copy_to_user((int *)arg,kern_buff,mem_size);
			printk(KERN_INFO"Data read successfully in kernel which is %d",(int *)arg);
			break;
	}
	return 0;
}

module_init(dev_init);
module_exit(dev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("MS");
MODULE_DESCRIPTION("A SIMPLE IOCTL PRACTICCE CODE");
