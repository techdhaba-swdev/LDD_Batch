#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>
#include <linux/string.h>

#define DEVICE_NAME "/dev/string_reverse" 
#define IOCTL_REVERSE_STRING _IOWR('q', 1, char *)

static char reversed_string[100];
static int reversed_len;
static int major;

static long device_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param) {
    switch (ioctl_num) {
        case IOCTL_REVERSE_STRING:
            {
                char *input_string = (char *)ioctl_param;
                int length = strlen(input_string);
                int i;
                // Reverse the input string
                for (i = 0; i < length; i++) {
                    reversed_string[length - i - 1] = input_string[i];
                }
                reversed_string[length] = '\0';
                reversed_len = length;
                printk(KERN_INFO "Reversed string: %s\n", reversed_string);
                copy_to_user((char *)ioctl_param, reversed_string, length + 1);
            }
            break;
        default:
            return -EINVAL;
    }
    return 0;
}

static struct file_operations fops = {
    .unlocked_ioctl = device_ioctl,
};

static int __init string_reverse_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major;
    }
    printk(KERN_INFO "Reverse string device registered, major number: %d\n", major);
    return 0;



}

static void __exit string_reverse_exit(void) {
    unregister_chrdev(0, DEVICE_NAME);
    printk(KERN_INFO "String reverse device unregistered\n");
}

module_init(string_reverse_init);
module_exit(string_reverse_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Kernel module for reversing a string");




