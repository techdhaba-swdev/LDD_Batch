#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/device.h>
#define DEVICE_NAME "chardriver"
#define BUFFER_SIZE 4096 //4kb
static int majorNumber;
static char message[BUFFER_SIZE] = {0};
static short size_of_message;
static struct class* charClass = NULL;
static struct device* charDevice = NULL;
static struct cdev charCdev;

//open function
static int dev_open(struct inode *inodep, struct file *filp) {

	printk(KERN_INFO "chardriver: Device has been opened\n");
	return 0;
}

//close-release function
static int dev_release(struct inode *inodep, struct file *filp) {
	printk(KERN_INFO "chardriver: Device closed successfully\n");
	return 0;
}

//read function
static ssize_t dev_read(struct file *filp, char *buffer, size_t len, loff_t *offset) {
	int error_count = 0;
	error_count = copy_to_user(buffer, message, size_of_message);
	if (error_count == 0) {
		printk(KERN_INFO "chardriver: Sent %d characters to user\n", size_of_message);
		return (size_of_message = 0);
	}
	else{
		printk(KERN_INFO "chardriver: Failed to Send %d characters to user\n", error_count);
		return -EFAULT;
	}
}

//write function
static ssize_t dev_write(struct file *filp, const char *buffer, size_t len, loff_t *offset) {
	sprintf(message, "%s(%zu letters)", buffer, len);
	size_of_message = strlen(message);
	printk(KERN_INFO "chardriver: Received %zu characters from user\n", len);
	return len;
}

//file ops structure
static struct file_operations fops = {
	.open = dev_open,
	.read = dev_read,
	.write = dev_write,
	.release = dev_release,
};

//init function
static int __init chardriver_init(void) {
	printk(KERN_INFO "chardriver: Initializing the chardriver\n");
	majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
	if (majorNumber < 0) {
		printk(KERN_ALERT "chardriver: failed to register major number\n");
		return majorNumber;
	}
	printk(KERN_INFO "chardriver: registered with major number %d\n", majorNumber);

	//device driver registration
	charClass = class_create(THIS_MODULE, DEVICE_NAME);
	if (IS_ERR(charClass)) {
		unregister_chrdev(majorNumber, DEVICE_NAME);
		printk(KERN_ALERT "Failed to register device class\n");
		return PTR_ERR(charClass);
	}
	printk(KERN_INFO "chardriver: device class registered\n");

	charDevice = device_create(charClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);
	if (IS_ERR(charDevice)) {
		class_destroy(charClass);
		unregister_chrdev(majorNumber, DEVICE_NAME);
		printk(KERN_ALERT "Failed to create device\n");
		return PTR_ERR(charDevice);
	}
	printk(KERN_INFO "chardriver: device class created\n");

	cdev_init(&charCdev, &fops);
	charCdev.owner = THIS_MODULE;
	if (cdev_add(&charCdev, MKDEV(majorNumber, 0), 1) == -1) {
		device_destroy(charClass, MKDEV(majorNumber, 0));
		class_destroy(charClass);
		unregister_chrdev(majorNumber, DEVICE_NAME);
		printk(KERN_ALERT "Failed to add cdev\n");
		return -1;
	}
	return 0;
}

//exit function
static void __exit chardriver_exit(void) {
	cdev_del(&charCdev);
	device_destroy(charClass, MKDEV(majorNumber, 0));
	class_unregister(charClass);
	class_destroy(charClass);
	unregister_chrdev(majorNumber, DEVICE_NAME);
	printk(KERN_INFO "chardriver: goodbye!\n");
}

module_init(chardriver_init);
module_exit(chardriver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AMAN");
MODULE_DESCRIPTION(" A SIMPLE LINUX CHARACTER DRIVER CODE");
