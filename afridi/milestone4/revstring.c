#include<linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include<linux/string.h>

#define DEVICE_NAME "string_dev"

static int major;
static char input_string[100];

//fn to reverse string
char* strrev(char* str) {
	char temp;
	int i, j;
	int len = strlen(str);

	for (i = 0, j = len - 1; i < j; ++i, --j) {
    	temp = str[i];
    	str[i] = str[j];
    	str[j] = temp;
	}

	return str;
}


// Open operation
static int device_open(struct inode *inode, struct file *file) {
  printk(KERN_INFO "String Device opened\n");
  return 0;
}
static int device_release(struct inode *inode, struct file *file) {
	printk(KERN_INFO "String Device closed\n");
	return 0;
}
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
	// Reverse the input string
	char reversed_string[100];
	strcpy(reversed_string, input_string);
	strrev(reversed_string);

	// Copy the reversed string to user space
	copy_to_user(buffer, reversed_string, strlen(reversed_string));
	printk(KERN_INFO "Reversed string sent to user space: %s\n", reversed_string);

	return strlen(reversed_string);
}

// Write operation
static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
	// Copy the input string from user space
	strncpy(input_string, buffer, sizeof(input_string));
	input_string[sizeof(input_string) - 1] = '\0'; // Ensure null-termination

	printk(KERN_INFO "Input string received: %s\n", input_string);
	return length;
}


static struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
};

static int __init string_dev_init(void) {
	major = register_chrdev(0, DEVICE_NAME, &fops);
	if (major < 0) {
    	printk(KERN_ALERT "Registering char device failed with %d\n", major);
    	return major;
	}
	printk(KERN_INFO "string : Device registered with major number %d\n", major);
	return 0;
}

static void __exit string_dev_exit(void) {
	unregister_chrdev(major, DEVICE_NAME);
	printk(KERN_INFO "string : Device unregistered\n");
}

module_init(string_dev_init);
module_exit(string_dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AMIT");
MODULE_DESCRIPTION("Simple character driver for reversing strings");
