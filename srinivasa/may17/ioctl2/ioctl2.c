#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/ioctl.h>

#define DEVICE_NAME "my_ioctldevice"
#define IOCTL_MAGIC 'k'
#define IOCTL_CMD_WRITE _IOW(IOCTL_MAGIC, 1, int)
#define IOCTL_CMD_READ  _IOR(IOCTL_MAGIC, 2, int)

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    int value;
    int ret_value;

    switch (cmd) {
        case IOCTL_CMD_WRITE:
            if (copy_from_user(&value, (int __user *)arg, sizeof(value))) {
                return -EFAULT;
            }
            printk(KERN_INFO "IOCTL received: %d\n", value);
            break;
	case IOCTL_CMD_READ:
	    ret_value = value*10;
	    if (copy_to_user(&ret_value, (int __user *)arg, sizeof(ret_value))) {
		    return -EFAULT;
	    }
	    printk(KERN_INFO " IOCTL TRANSFERED : %d\n", ret_value );
	    break ;

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
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Linux char driver with ioctl");
MODULE_VERSION("0.1");