#include<linux/uaccess.h>
#include<linux/fs.h>
#include<linux/module.h>
#include<linux/init.h>

#define DEVICE_NAME "thread_add_sub"
MODULE_LICENSE("GPL");
MODULE_AUTHOR("SARATH");

static int major;
static int val1,val2,res1,res2;
static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}
static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    copy_to_user(buffer, &res2, sizeof(int));

    printk(KERN_INFO "Result sent to user space: %d\n", res2);
    return sizeof(int);
}
static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    copy_from_user(&val1, buffer, sizeof(int));
    copy_from_user(&val2, buffer+sizeof(int), sizeof(int));
    printk(KERN_INFO "Result received from user space: %d and %d \n", val1,val2);
    res1= val1 + val2; // Add the value
    res2=val1-val2;
    return sizeof(int);
}
static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};
static int __init adding_integer_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops); //(count,name of device,structure)
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Adding and Subtracting Integer: Device registered with major number %d\n", major);
    return 0;
}
static void __exit adding_integer_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Adding and Subtracting Integer: Device unregistered\n");
}

module_init(adding_integer_init);
module_exit(adding_integer_exit);
