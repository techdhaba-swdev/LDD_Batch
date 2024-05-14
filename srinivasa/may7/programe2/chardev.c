#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "chardev"
#define BUF_LEN 80

MODULE_LICENSE("GPL");
MODULE_AUTHOR("srinivas");
MODULE_DESCRIPTION(" a simple character device driver");

static int Major;
static char msg[BUF_LEN];
static char *msg_ptr;

static int device_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "Device  opened\n");
	return 0;
}
static int device_release(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "Device closed/n");
	return 0;
}
static ssize_t device_read(struct file* file, char *buffer, size_t length, loff_t *offset)
{
	int bytes_read = 0;
	if (*msg_ptr == 0)
		return 0;

	while(length && *msg_ptr)
	{
		put_user(*(msg_ptr++), buffer++);
		length--;
		bytes_read++;
	}
	return bytes_read;
}
static ssize_t device_write(struct file *file,const char *buffer, size_t length, loff_t *offset)
{
	int bytes_written = 0;
	if (length > BUF_LEN)
		return -EINVAL;
	memset(msg, 0, BUF_LEN);
	strncpy(msg, buffer, length);
	msg_ptr = msg;
	bytes_written = length;

	return bytes_written;
}
static struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
};

static int __init chardev_init(void )
{
	Major = register_chrdev(0, DEVICE_NAME, &fops);
	if (Major < 0){
		printk(KERN_ALERT "registering char device failed with %d\n", Major);
		return Major;
	}
	printk(KERN_INFO " registed char device with major number %d\n", Major);
	return 0;
}
static void __exit chardev_exit(void )
{
	unregister_chrdev(Major, DEVICE_NAME);
	printk(KERN_INFO "unregistered char device\n");
}
module_init(chardev_init);
module_exit(chardev_exit);
