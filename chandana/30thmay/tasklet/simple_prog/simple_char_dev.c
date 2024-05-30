#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

#define DEVICE_NAME "simple_char_dev"
#define MAJOR_NUM 240

static int dev_open(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int dev_release(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static struct file_operations fops = {
    .open = dev_open,
    .release = dev_release,
};

static int __init char_dev_init(void) {
    int ret = register_chrdev(MAJOR_NUM, DEVICE_NAME, &fops);
    if (ret < 0) {
        printk(KERN_ALERT "Failed to register character device\n");
        return ret;
    }
    printk(KERN_INFO "Character device registered: %s with major number %d\n", DEVICE_NAME, MAJOR_NUM);
    return 0;
}

static void __exit char_dev_exit(void) {
    unregister_chrdev(MAJOR_NUM, DEVICE_NAME);
    printk(KERN_INFO "Character device unregistered\n");
}

module_init(char_dev_init);
module_exit(char_dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Linux character device driver");
MODULE_VERSION("1.0");
