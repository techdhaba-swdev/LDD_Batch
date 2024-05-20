#include <linux/module.h>
#include <linux/fs.h>

#define DEVICE_NAME "my_device"

static int my_device_open(struct inode *inode, struct file *file) {
    return 0;
}

static int my_device_release(struct inode *inode, struct file *file) {
    return 0;
}

static const struct file_operations my_device_fops = {
    .owner = THIS_MODULE,
    .open = my_device_open,
    .release = my_device_release,
    .mmap = my_device_mmap,
};

static int __init my_device_init(void) {
    int major = register_chrdev(0, DEVICE_NAME, &my_device_fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Registered a device with dynamic major number of %d\n", major);
    return 0;
}

static void __exit my_device_exit(void) {
    unregister_chrdev(0, DEVICE_NAME);
}

module_init(my_device_init);
module_exit(my_device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Example Device Driver");
