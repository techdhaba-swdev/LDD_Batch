#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/uaccess.h>
#include<linux/fs.h>
#include<linux/proc_fs.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#define DEVICE_NAME "my_proc_device"

static int kernel_buff;
static int proc_open(struct inode *inode,struct file *file);
static int proc_release(struct inode *inode,struct file *file);
static ssize_t proc_read(struct file *filp,char __user *buff,size_t len,loff_t *off);
static ssize_t proc_write(struct file *filp,const char *buff,size_t len,loff_t *off);
static int __init proc_init(void);
static void __exit proc_exit(void);
	
static struct proc_dir_entry *proc_entry;

static const struct proc_ops proc_file_ops={
	.proc_open=proc_open,
	.proc_release=proc_release,
	.proc_read=proc_read,
	.proc_write=proc_write,
};

static int proc_open(struct inode *inode,struct file *file){
	pr_info("Proc Device Opened");
	return 0;
}

static int proc_release(struct inode *inode,struct file *file){
	pr_info("Proc Device Released");
	return 0;
}

static ssize_t proc_read(struct file *filp,char __user *buff,size_t len,loff_t *off){
	copy_to_user(buff,kernel_buff,sizeof(kernel_buff));
	return sizeof(kernel_buff);
}

static ssize_t proc_write(struct file *filp,const char *buff,size_t len,loff_t *off){
	copy_from_user(kernel_buff,buff,len);
	return len;
}

static int __init proc_init(void){

	proc_create(DEVICE_NAME,0644,NULL,&proc_file_ops);

	pr_info("Proc device initialized");
	return 0;

}

static void __exit proc_exit(void){
	remove_proc_entry(DEVICE_NAME,NULL);
	pr_info("Device removed successfully");
}

module_init(proc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MS");
MODULE_DESCRIPTION("A simple proc device practice");
