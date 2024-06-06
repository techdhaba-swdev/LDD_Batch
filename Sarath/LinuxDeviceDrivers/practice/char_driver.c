#include<linux/module.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include<linux/cdev.h>
#include<linux/kernel.h>
#include<linux/slab.h>
#include<linux/init.h>
#include<linux/device.h>
#include<linux/kdev_t.h>

#define mem_size 1024
#define DEVICE_NAME "my_character_device"
dev_t dev;
static int major;
//static struct cdev my_cdev;
//static struct class *dev_class;
uint8_t *kernel_buffer;

static int __init char_device_init(void);
static void __exit char_device_exit(void);

static int my_open(struct inode *inode,struct file *file);
static int my_release(struct inode *inode,struct file *file);
static size_t my_read(struct file *filp,char __user *buff,size_t len,loff_t *off);
static size_t my_write(struct file *filp,const char *buff,size_t len,loff_t *off);


static struct file_operations fops={
	//.owner=THIS_MODULE,
	.open=my_open,
	.read=my_read,
	.write=my_write,
	.release=my_release,
};

static int my_open(struct inode *inode,struct file *file){
	if(kernel_buffer=kmalloc(mem_size,GFP_KERNEL)==0){
		printk(KERN_INFO"Memory not allocated");
		return -1;
	}
	printk(KERN_INFO"Device opened successfully");
	return 0;
}
static int my_release(struct inode *inode,struct file *file){
	kfree(kernel_buffer);
	printk(KERN_INFO"Device file closed");
	return 0;
}
static ssize_t my_read(struct file *filp,char  *buff,size_t len,loff_t *off){
	copy_to_user(buff,kernel_buffer,mem_size);
	printk(KERN_INFO"Device read done");
	return mem_size;
}
static ssize_t my_write(struct file *filp,const char *buff,size_t len,loff_t *off){
	copy_from_user(kernel_buffer,buff,len);
	printk(KERN_INFO"Device write is done");
	return len;
}
static int __init char_device_init(void){
	major = register_chrdev(0, DEVICE_NAME, &fops);
	if(major <0){
		printk(KERN_INFO"Cant register device");
		return -1;
	}
	printk(KERN_INFO"Device registered with MAJOR %d and MINOR %d\n",MAJOR(dev),MINOR(dev));
	/*
	//creating cdev structure
	cdev_init(&my_cdev,&fops); //passing pointer to cdev structure and file operations structure
	//adding char device to system
	if((cdev_add(&my_cdev,dev,1))<0){ //1.pointer to cdev structure 2.device
		printk(KERN_INFO"Cannot add device to system\n");
		goto r_class;
	}
	//creating class
	if((dev_class=class_create(THIS_MODULE,"my_class"))==NULL){
		printk(KERN_INFO"Cannot create struct class\n");
		goto r_class;
	}
	//creating device
	if((device_create(dev_class,NULL,dev,NULL,"my_device"))==NULL){
		printk(KERN_INFO"Cannot create device\n");
		goto r_device;
	}

	printk(KERN_INFO"Device insertion Done\n");
	return 0;

r_device:
		class_destroy(dev_class);



r_class:
		unregister_chrdev_region(&dev,1);
		return -1;*/
}

static void __exit char_device_exit(void){
	unregister_chrdev_region(major,DEVICE_NAME);
	//device_destroy(dev_class,dev);
	//cdev_del(&my_cdev);
	//class_destroy(dev_class);
	printk(KERN_INFO"Device UNregistered");
}

module_init(char_device_init);
module_exit(char_device_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("SARATH");
MODULE_DESCRIPTION("Basic char device driver");
