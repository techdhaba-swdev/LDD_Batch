#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/uaccess.h>

#define DEVICE_NAME "swap"

static int major_number;
static int a;
static int b;

static int swap_open(struct inode *inode, struct file *file){
	printk(KERN_INFO "Device open \n");
	return 0;
	}
static int swap_release(struct inode *inode, struct file *file){
	printk(KERN_INFO "Device closed\n");
	return 0;
}
static ssize_t swap_write(struct file *file, const char *buffer, size_t length, loff_t *offset){
	if (sscanf(buffer,"%d %d",&a,&b)!= 2){
		printk(KERN_ALERT "Invalid input\n");
		return -EINVAL;
	}
	 a=a+b;
	 b=a-b;
	 a=a-b;
	printk(KERN_INFO "Swapped values a=%d and b=%d \n",a,b);

	return length;
}
static ssize_t swap_read(struct file *file,char *buffer,size_t length,loff_t *offset){
	if(copy_to_user(buffer,&a,sizeof(int))){
		return -EFAULT;
	}
	return sizeof(int);
}
static struct file_operations swap_fops = {
    .open = swap_open,
    .release = swap_release,
    .write = swap_write,
    .read = swap_read,
};

static int __init swap_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &swap_fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Swap device registered, major number: %d\n", major_number);
    return 0;
}

static void __exit swap_exit(void) {
    unregister_chrdev(0, DEVICE_NAME);
    printk(KERN_INFO "Swap values: device unregistered\n");
}

module_init(swap_init);
module_exit(swap_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BTS");
MODULE_DESCRIPTION("Simple swap device driver");
