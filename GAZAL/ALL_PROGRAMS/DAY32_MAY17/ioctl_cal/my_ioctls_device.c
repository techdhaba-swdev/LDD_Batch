#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>

#define DEVICE_NAME "my_ioctls_device"
#define IOCTL_MAGIC 'k'
#define IOCTL_ADD _IOWR(IOCTL_MAGIC, 1, int[3])
#define IOCTL_SUB _IOWR(IOCTL_MAGIC, 2, int[3])
#define IOCTL_MUL _IOWR(IOCTL_MAGIC, 3, int[3])
#define IOCTL_DIV _IOWR(IOCTL_MAGIC, 4, int[3])

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    int values[3]; // [operand1, operand2, result]

    if (copy_from_user(values, (int __user *)arg, sizeof(values))) {
        return -EFAULT;
    }

    switch (cmd) {
        case IOCTL_ADD:
            values[2] = values[0] + values[1];
            printk(KERN_INFO "Add %d + %d = %d\n", values[0], values[1], values[2]);
            break;
        case IOCTL_SUB:
            values[2] = values[0] - values[1];
            printk(KERN_INFO "Subtract: %d - %d = %d\n", values[0], values[1], values[2]);
            break;
        case IOCTL_MUL:
            values[2] = values[0] * values[1];
            printk(KERN_INFO "Multiply: %d * %d = %d\n", values[0], values[1], values[2]);
            break;
        case IOCTL_DIV:
            if (values[1] == 0) {
                printk(KERN_ALERT "Division by zero error\n");
                return -EINVAL;
            }
            values[2] = values[0] / values[1];
            printk(KERN_INFO "Divide: %d / %d = %d\n", values[0], values[1], values[2]);
            break;
        default:
            return -ENOTTY;
    }

    if (copy_to_user((int __user *)arg, values, sizeof(values))) {
        return -EFAULT;
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
MODULE_DESCRIPTION("A simple Linux char driver with ioctl for calculator operations");

