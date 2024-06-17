#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>

#define DEVICE_NAME "my_ioctl_device"
#define IOCTL_MAGIC 'k'
#define IOCTL_SET_STRING _IOW(IOCTL_MAGIC, 2, char *)
#define IOCTL_GET_STRING _IOR(IOCTL_MAGIC, 3, char *)

static char kernel_string[100] = {0}; // Buffer to store string from user space

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    switch (cmd) {
        case IOCTL_SET_STRING:
            if (copy_from_user(kernel_string, (char __user *)arg, sizeof(kernel_string))) {
                return -EFAULT;
            }
            printk(KERN_INFO "String received: %s\n", kernel_string);
            break;
        case IOCTL_GET_STRING:
            if (copy_to_user((char __user *)arg, kernel_string, sizeof(kernel_string))) {
                return -EFAULT;
            }
            printk(KERN_INFO "String sent to user: %s\n", kernel_string);
            break;
        default:
            return -ENOTTY;
    }
    return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .unlocked_ioctl = device_ioctl,
};

static int major_number;
static struct cdev my_cdev;

static int __init my_ioctl_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number);
        return major_number;
    }

    cdev_init(&my_cdev, &fops);
    my_cdev.owner = THIS_MODULE;
    if (cdev_add(&my_cdev, MKDEV(major_number, 0), 1)) {
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ALERT "Adding cdev failed\n");
        return -1;
    }

    printk(KERN_INFO "Device registered with major number %d\n", major_number);
    return 0;
}

static void __exit my_ioctl_exit(void) {
    cdev_del(&my_cdev);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Device unregistered\n");
}

module_init(my_ioctl_init);
module_exit(my_ioctl_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit");
MODULE_DESCRIPTION("A simple Linux char driver with ioctl for string set/get");
MODULE_VERSION("0.1");

