#include<linux/kernel.h>   
#include<linux/init.h>
#include<linux/fs.h> 
#include<linux/uaccess.h>
#include<linux/module.h>

#define DEVICE_NAME "chardev1" 

MODULE_LICENSE("GPL");


static int major;

static int char_open(struct inode *inode,struct file *file);
static int char_release(struct inode *inode,struct file *file);

static struct file_operations fops={
	.open = char_open,
	.release = char_release,
};
static int char_open(struct inode *inode,struct file *file){

	printk(KERN_INFO "this is open function\n");
	return 0;

}

static int char_release(struct inode *inode,struct file *file){

	printk(KERN_INFO "this is release function\n");
	return 0;

}  

static int __init char_module_init(void){

	major=register_chrdev(0,DEVICE_NAME,&fops); 
	printk(KERN_INFO "majoe number is %d\n",major);
	printk(KERN_INFO "this is init module\n");
	return 0;

}

static void __exit char_module_exit(void){
	
	unregister_chrdev(major,DEVICE_NAME);
	printk(KERN_INFO "this is exit module\n");

}

module_init(char_module_init);
module_exit(char_module_exit);   
