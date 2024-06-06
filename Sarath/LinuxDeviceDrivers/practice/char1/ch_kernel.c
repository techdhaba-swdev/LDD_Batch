#include<linux/module.h>
#include<linux/fs.h>
#include<linux/init.h>
#include<linux/uaccess.h>
#define DEVICE_NAME "ch_device"
#define MEM_SIZE 4096
static int major;
static int *kernel_mem;
static char kernel_buffer[MEM_SIZE];

static int char_open(struct inode *inode,struct file *file){
	kernel_mem=kmalloc(MEM_SIZE,GFP_KERNEL);
	if(kernel_mem==0){
		printk(KERN_INFO"Cant allocate memory\n");
		return -1;
	}
	printk(KERN_INFO"Memory allocated and device opened");
	return 0;
}

static int char_release(struct inode *inode,struct file *file){
	kfree(kernel_mem);
	printk(KERN_INFO"Memory is free and device is released");
	return 0;
}

static ssize_t char_read(struct file *filp,char *buff,size_t len,loff_t *offset){
		copy_to_user(buff,kernel_buffer,MEM_SIZE);
		printk(KERN_INFO"Read from kernel space : %s\n",kernel_buffer);
		return MEM_SIZE;
}

static ssize_t char_write(struct file *filp,const char *buff,size_t len,loff_t *offset){
	copy_from_user(kernel_buffer,buff,len);
	printk(KERN_INFO"Device write successfull");
	return len;
}

static struct file_operations fops={
	.read=char_read,
	.write=char_write,
	.open=char_open,
	.release=char_release,
};

static int __init device_init(void){
	major=register_chrdev(0,DEVICE_NAME,&fops);
	if(major<0){
		printk(KERN_INFO"Cannot register device");
		return -1;
	}
	printk(KERN_INFO"Registration Succesfull with major %d\n",major);
	return 0;
}

static void __exit device_exit(void){
	unregister_chrdev(major,DEVICE_NAME);
	printk(KERN_INFO"Device unregistered\n");
}

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sarath Chandra");
MODULE_DESCRIPTION("JUST A PRACTICE OF CHAR DRIVER");
