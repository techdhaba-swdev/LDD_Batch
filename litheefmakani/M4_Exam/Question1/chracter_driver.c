/*Character Device Driver for Reverse String
Question:
You are required to write a character device driver for an x86 system that reverses a string provided by the user. The driver should interact with a user-space program to perform the following tasks:
1.	Create a Character Device Driver in the Kernel Space:
o	Implement open, read, write, and release functions for the device driver.
o	When the user writes a string to the device, the driver should reverse the string and store it.
o	When the user reads from the device, the reversed string should be returned.
2.	Write a User-Space Program:
o	Accept a string input from the user.
o	Write the string to the device.
o	Read the reversed string from the device and print it.
Platform Details:
•	Operating System: Linux (Kernel version 5.x or later)
•	Architecture: x86
•	Development Tools:
o	GCC (for compiling kernel modules and user-space programs)
o	Make (for building the kernel module)
o	Vim or any other text editor*/

#include<linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include<linux/string.h>

#define DEVICE_NAME "string_dev"

static int major;//this is the major number for the device connceted to the driver
static char input_string[100];//buffer for storing input string 

//function  to reverse string
char* strrev(char* str) {
	char temp;
	int i, j;
	int len = strlen(str);//lenght of the string 
        //swap the chracter s frommmm begining and end until middle is reached.
	for (i = 0, j = len - 1; i < j; ++i, --j) {
    	temp = str[i];
    	str[i] = str[j];
    	str[j] = temp;
	}

	return str;
}


// Open the device 
static int device_open(struct inode *inode, struct file *file) {
  printk(KERN_INFO "String Device opened\n");//log device is open 
  return 0;
}
//close the device
static int device_release(struct inode *inode, struct file *file) {
	printk(KERN_INFO "String Device closed\n");//log device is close 
	return 0;
}
//device is open for the read operation 
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
	// Reverse the input string
	char reversed_string[100];//storing the reversed string 
	strcpy(reversed_string, input_string);//copy the the string 
	strrev(reversed_string);//retrieving the reversed string 

	// Copy the reversed string to user space
	copy_to_user(buffer, reversed_string, strlen(reversed_string));
	printk(KERN_INFO "Reversed string sent to user space: %s\n", reversed_string);//log reversed string sent 

	return strlen(reversed_string);//return the reversed string 
}

// open the device for writing 
static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
	// Copy the input string from user space
	strncpy(input_string, buffer, sizeof(input_string));
	input_string[sizeof(input_string) - 1] = '\0'; // Ensure null-termination

	printk(KERN_INFO "Input string received: %s\n", input_string);//log input string received 
	return length;
}

//file operatioons 
static struct file_operations fops = {
	.read = device_read,//set read operation 
	.write = device_write,//set write operation 
	.open = device_open,//set open operation
	.release = device_release,//set release operation
};
//registering the device 
static int __init string_dev_init(void) {
	major = register_chrdev(0, DEVICE_NAME, &fops);//registering for major number 
	if (major < 0) {
    	printk(KERN_ALERT "Registering char device failed with %d\n", major);//log registration failure 
    	return major;
	}
	printk(KERN_INFO "string : Device registered with major number %d\n", major);//log registration failed 
	return 0;
}
//unregistring the device 
static void __exit string_dev_exit(void) {
	unregister_chrdev(major, DEVICE_NAME);//unregister character device 
	printk(KERN_INFO "string : Device unregistered\n");
}

module_init(string_dev_init);//set module intialization function 
module_exit(string_dev_exit);//set module exit function 

MODULE_LICENSE("GPL");//set module license
MODULE_AUTHOR("Litheef");//set module author 
MODULE_DESCRIPTION("Simple character driver for reversing strings");//set module description

