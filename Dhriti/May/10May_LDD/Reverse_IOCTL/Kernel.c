#include <linux/module.h> // Required for all kernel modules
#include <linux/kernel.h> // Kernel-specific functions and macros
#include <linux/fs.h> // File system operations
#include <linux/uaccess.h> // User space memory access
#include <linux/ioctl.h>
#define DEVICE_NAME "reverse" // Device name
#define IOCTL_REVERSE_STRING _IOW('R', 1, char *) // IOCTL command to reverse a string

int Major;
static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n"); // Log device open event
    return 0; // Return success
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device released\n"); // Log device release event
    return 0; // Return success
}

static long reverse_string(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param) {
    char *string = (char *)ioctl_param; // Get the string from user space
    int length = strlen(string);                   

    // Reverse the string
    for (int i = 0; i < length / 2; i++) {
        char temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }

}

static long device_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param) {
	char *string;
	switch (ioctl_num) {
		case IOCTL_REVERSE_STRING:
		string = (char*)ioctl_param;
		reverse_string(string);
		break;
		default -EINVAL;
	}
	return 0;
}

static struct file_operations fops = {
    .unlocked_ioctl = device_ioctl, // IOCTL handler function
    .open = device_open, // Open handler function
    .release = device_release, // Release handler function
};


static int __init reverse_init(void) {
    printk(KERN_INFO "Reverse device loaded\n"); //  device initialization
    register_chrdev(Major, DEVICE_NAME, &fops); // Register the character device
    return 0; // Return success
}

static void __exit reverse_exit(void) {
    printk(KERN_INFO "Reverse device unloaded\n"); //  device unloading
    unregister_chrdev(Major, DEVICE_NAME); // Unregister the character device
}

module_init(reverse_init); // Specify the initialization function
module_exit(reverse_exit); // Specify the exit function

MODULE_LICENSE("GPL"); // License of the module
MODULE_AUTHOR("Dhriti"); // Author of the module
MODULE_DESCRIPTION("A device driver to reverse a string"); // Description of the module


