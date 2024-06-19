#include<linux/module.h>  
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h> 
#include<linux/uaccess.h>

#define DEVICE_NAME "chardev4"

MODULE_LICENSE("GPL"); 

static int major_number;
static char buffer_read[100]="Hello from kernal space";

static int char_open(struct inode *inode,struct file *file);
static int char_release(struct inode *inode,struct file *file);
static ssize_t char_read(struct file *file,char *buffer,size_t length,loff_t *offset); 

static struct file_operations fops={
	.open = char_open,
	.release = char_release,
	.read = char_read,

}; 

static int char_open(struct inode *inode,struct file *file){

	printk(KERN_INFO "this is open function\n");
	return 0;

}

static int char_release(struct inode *inode,struct file *file){

	printk(KERN_INFO "this is release function\n");
	return 0;

} 
static ssize_t char_read(struct file *file,char *buffer,size_t length,loff_t *offset){

	printk(KERN_INFO "this is read api\n");
	copy_to_user(buffer,buffer_read,sizeof(buffer_read));
	printk(KERN_INFO "%s\n",buffer_read); 
	return 0;

}





static int __init char_init(void){

	major_number=register_chrdev(0,DEVICE_NAME,&fops);
	printk("major number is %d\n",major_number);
	printk(KERN_INFO "this is init module\n");
	return 0;

}

static void __exit char_exit(void){

	unregister_chrdev(major_number,DEVICE_NAME); 
	printk(KERN_INFO "this is exit module\n");

}

module_init(char_init);
module_exit(char_exit);  
