#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "integer_add"
#define CLASS_NAME "add"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple kernel module for adding two numbers");

static int majorNumber;
static char message[256] = {0};
static short size_of_message;
static int number1;
static int number2;
static int result;

static int dev_open(struct inode *, struct file *);
static int dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fops =
{
	.open = dev_open,
	.read = dev_read,
	.write = dev_write,
	.release = dev_release,
};

static int __init add_init(void)
{
	printk(KERN_INFO "Add: Initializing the Add module\n");

	majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
	if (majorNumber < 0)
	{
		printk(KERN_ALERT "Add failed to register a major number\n");
		return majorNumber;
	}

	printk(KERN_INFO "Add: registered correctly with major number %d\n", majorNumber);

	return 0;
}

static void __exit add_exit(void)
{
	unregister_chrdev(majorNumber, DEVICE_NAME);
	printk(KERN_INFO "Add: Goodbye from the Add module\n");
}

static int dev_open(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "Add: Device has been opened\n");
	return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset)
{
	sprintf(message, "%d\n", result);
	size_of_message = strlen(message);
	copy_to_user(buffer, message, size_of_message);
	return size_of_message;
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset)
{
	sscanf(buffer, "%d %d", &number1, &number2);
	result = number1 + number2;
	printk(KERN_INFO "Add: Received %d and %d, result = %d\n", number1, number2, result);
	return len;
}

static int dev_release(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "Add: Device successfully closed\n");
	return 0;
}

module_init(add_init);
module_exit(add_exit);
