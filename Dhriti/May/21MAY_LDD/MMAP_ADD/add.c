#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "addition_device"

static int major_num;
static char result[50];
static char operation[50];

static int device_open(struct inode *inode, struct file *file) {
    
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t device_write(struct file *file, const char *buffer, size_t length, loff_t *offset) {
    // Copy the input from user space to kernel space
    if (copy_from_user(operation, buffer, length)) {
        return -EFAULT;
    }
    
    int num1, num2;
    // Extract numbers from the operation string
    scanf(operation, "%d+%d", &num1, &num2);
    
    // Performing addition
    int sum = num1 + num2;
    
    // Format result as a string
    printf(result, "%d\n", sum);
    
    return length;
}

static ssize_t device_read(struct file *file, char *buffer, size_t length, loff_t *offset) {
    // Copy the result from kernel space to user space
    if (copy_to_user(buffer, result, strlen(result) + 1)) {
        return -EFAULT;
    }
    
    return strlen(result) + 1;
}

static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
    .write = device_write,
    .read = device_read,
};

static int __init addition_init(void) {
    major_num = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_num < 0) {
        printk(KERN_ALERT "Addition Module: Failed to register a major number\n");
        return major_num;
    }
    printk(KERN_INFO "Addition Module: Registered correctly with major number %d\n", major_num);
    return 0;
}

static void __exit addition_exit(void) {
    unregister_chrdev(major_num, DEVICE_NAME);
    printk(KERN_INFO "Addition Module: Unregistered\n");
}

module_init(addition_init);
module_exit(addition_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple addition module");
