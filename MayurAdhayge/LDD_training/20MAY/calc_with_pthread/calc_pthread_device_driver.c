#include<linux/init.h>
#include<linux/modules.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#define DEVICE_NAME "calc_pthread_device"

static  dev_t device_num;
static struct class *chrdev_class;
static struct device *chrdev_device;
struct cdev my_chrdev;

struct file_operations fops;

struct file_operations
{
.owner=THIS_MODULE;
.open=device_open;
.release=device_close;
.read=device_read;
.write=device_write;
};

int __init device_init()
{
	kprintf(KERN_INFO " WELL TO MY %S DEVICE DRIVER;",DEVICE_NAME);
	kpprintf(KERN_INFO "INITIALIZING THE IMPORTANT RESOURCES";)
	alloc_chrdev_region(&device_num);
	chdev_class=class_create(THIS_MODULE,DEVICE_NAME);
	chdev_device=device_create(chdev_class,NULL,device_num,NULL,DEVICE_NAME);
        cdev_init(&my_chrdev,&fops);
	my_chardev.owner=THIS_MODULE;
	cdev_add(&my_chrdev,device_num,0);
	
}

void __exit device_exit(void)
{
cdev_del(&my_chrdev);
device_destroy(chardev_device,device_number);
class_destroy(chardev_class);
unregister_chrdev_region(device_num,1);
}
