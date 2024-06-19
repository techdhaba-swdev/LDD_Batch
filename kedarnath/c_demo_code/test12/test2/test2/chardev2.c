#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>  
#include<linux/uaccess.h>
#include<linux/fs.h> 

#define DEVICE_NAME "chardev2"

MODULE_LICENSE("GPL");

static int major;
static char str[100]="Hello from kernal space";

static int char_open(struct inode *inode,struct file *file);
static int char_release(struct inode *inode,struct file *file);
static ssize_t char_read(struct file *file,char *buffer,size_t length,loff_t *offset);

static struct file_operations fops={
	.open = char_open,
	.release = char_release,
	.read = char_read, 

};


static ssize_t char_read(struct file *file,char *buffer,size_t length,loff_t *offset){

	printk(KERN_INFO "this is read api\n");
	copy_to_user(buffer,str,sizeof(str));  
	return 0; 	

}

static int char_open(struct inode *inode,struct file *file){

	printk(KERN_INFO "device is opend\n");
	return 0;

}

static int char_release(struct inode *inode,struct file *file){

	printk(KERN_INFO "device is closed\n");
	return 0;

}

static int __init char_init(void){
	
	major=register_chrdev(0,DEVICE_NAME,&fops);
	printk(KERN_INFO "major number is %d \n",major);
	printk(KERN_INFO "module is inserted\n");
	return 0;

}

static void __exit char_exit(void){

	unregister_chrdev(major,DEVICE_NAME); 
	printk(KERN_INFO "module is removed\n");

}

module_init(char_init);
module_exit(char_exit);

