#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/uaccess.h>


#define DEVICE_NAME "char_driver"
#define MAX_SIZE 100 // Buffer Size


static int major;
static int buffer[MAX_SIZE];
static int buffer_size; //tracks size of the data stored in the buffer

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char __user *, size_t, loff_t *);


static int device_open(struct inode *inodep, struct file *filep) {
	return 0; //success
}

static int device_release(struct inode *inodep, struct file *filep) {
	return 0; //success
}

static ssize_t device_read(struct file *filep, char __user *user_buffer, size_t len, loff_t *offset) 
{
	int bytes_to_copy = buffer_size; //Determines the no of bytes to copy

	if(bytes_to_copy > len) {
		bytes_to_copy = len; //Ensuring the length to copy does  exceed the user buffer length
				    
	}
        
	//Api to copy data from kernel space to user space
	if(copy_to_user(user_buffer, buffer, bytes_to_copy)){
		return -EFAULT; //Returns error when copying fails
       }
	buffer_size = 0; //Clear the buffer after reading
        printk(KERN_INFO "Read %d bytes from device\n", bytes_to_copy);
	return bytes_to_copy; //Return number of bytes read
}

static ssize_t device_write(struct file *filep,const char __user *user_buffer, size_t len, loff_t *offset)
{
	int bytes_to_copy = len;
        //Ensuring I do not write more data than the buffer can hold
	if(bytes_to_copy > MAX_SIZE) {
		bytes_to_copy = MAX_SIZE;
     	}
           
	if(copy_from_user(buffer, user_buffer, bytes_to_copy)){
                return -EFAULT; //Returns error when copying fails
	}

	buffer_size = bytes_to_copy; //Update the buffer size
        printk(KERN_INFO "Wrote %d bytes to the device\n", bytes_to_copy);
	return bytes_to_copy; //Return no. of bytes written
}

static struct file_operations fops = {
	.open = device_open,
	.release = device_release,
	.read = device_read,
	.write = device_write,
};

static int __init char_driver_init(void) {
	major = register_chrdev(0, DEVICE_NAME, &fops);
	if(major <0 ) {
		printk(KERN_ALERT "FAILED TO REGISTER THE MAJOR NUMBER\n");
		return major;
	}

	printk(KERN_INFO "REGISTERED CORRECTLY WITH THE MAJOR NUMBER %d\n", major);
	return 0;
}

static void __exit char_driver_exit(void) {
	unregister_chrdev(major, DEVICE_NAME);
	printk(KERN_INFO "UNREGISTERED THE DEVICE\n");
}


module_init(char_driver_init);
module_exit(char_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DHRITI");
MODULE_DESCRIPTION("A simple char device driver");
