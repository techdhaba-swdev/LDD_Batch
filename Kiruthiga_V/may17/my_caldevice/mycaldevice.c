#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>

#define DEVICE_NAME "mycaldevice"
#define IOCTL_MAGIC 'c'
#define IOCTL_CALCULATE _IOWR(IOCTL_MAGIC, 1, struct operation_data)

struct operation_data {
    int num1;
    int num2;
    char operation;
    int result;
};

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    struct operation_data data;

    switch (cmd) {
        case IOCTL_CALCULATE:
            if (copy_from_user(&data, (struct operation_data *)arg, sizeof(data))) {
                return -EFAULT;
            }

            switch (data.operation) {
                case '+':
                    data.result = data.num1 + data.num2;
                    break;
                case '-':
                    data.result = data.num1 - data.num2;
                    break;
                case '*':
                    data.result = data.num1 * data.num2;
                    break;
                case '/':
                    if (data.num2 == 0) {
                        printk(KERN_ERR "Division by zero error\n");
                        return -EINVAL;
                    }
                    data.result = data.num1 / data.num2;
                    break;
                default:
                    printk(KERN_ERR "Invalid operation\n");
                    return -EINVAL;
            }

            if (copy_to_user((struct operation_data *)arg, &data, sizeof(data))) {
                return -EFAULT;
            }
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

static int __init calculator_init(void) {
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

    printk(KERN_INFO "Calculator device registered with major number %d\n", major_number);
    return 0;
}

static void __exit calculator_exit(void) {
    cdev_del(&my_cdev);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Calculator device unregistered\n");
}

module_init(calculator_init);
module_exit(calculator_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kiruthiga");
MODULE_DESCRIPTION("A simple calculator device driver");
MODULE_VERSION("0.1");




