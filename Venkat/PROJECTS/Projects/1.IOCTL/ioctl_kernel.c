#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>

#define DEVICE_NAME "my_ioctl_device"
#define IOCTL_SET_STRING _IOW('k', 1, char *)
#define IOCTL_GET_STRING _IOR('k', 2, char *)

static int major_number;
static struct cdev my_cdev;
static char kernel_string[100] = {0}; // Buffer to store string from user space

// Forward declarations
static int my_ioctl_set_string(char __user *user_string);
static int my_ioctl_get_string(char __user *user_string);
static int device_open(struct inode *inode, struct file *file);
static int device_release(struct inode *inode, struct file *file);
static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

// Interface for ioctl operations
struct ioctl_ops {
    int (*set_string)(char __user *user_string);
    int (*get_string)(char __user *user_string);
};

// Concrete implementation of ioctl operations
static struct ioctl_ops my_ioctl_ops = {
    .set_string = my_ioctl_set_string,
    .get_string = my_ioctl_get_string,
};

static int my_ioctl_set_string(char __user *user_string) {
    if (copy_from_user(kernel_string, user_string, sizeof(kernel_string) - 1)) {
        return -EFAULT;
    }
    kernel_string[sizeof(kernel_string) - 1] = '\0'; // Ensure null termination
    printk(KERN_INFO "String received: %s\n", kernel_string);
    return 0;
}

static int my_ioctl_get_string(char __user *user_string) {
    if (copy_to_user(user_string, kernel_string, strlen(kernel_string) + 1)) {
        return -EFAULT;
    }
    printk(KERN_INFO "String sent to user: %s\n", kernel_string);
    return 0;
}

// Device operations
static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .unlocked_ioctl = device_ioctl,
};

static int device_open(struct inode *inode, struct file *file) {
    file->private_data = &my_ioctl_ops;
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    file->private_data = NULL;
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    struct ioctl_ops *ops = (struct ioctl_ops *)file->private_data;
    if (!ops) {
        return -ENOTTY;
    }

    switch (cmd) {
        case IOCTL_SET_STRING:
            return ops->set_string((char __user *)arg);
        case IOCTL_GET_STRING:
            return ops->get_string((char __user *)arg);
        default:
            return -ENOTTY;
    }
}

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
