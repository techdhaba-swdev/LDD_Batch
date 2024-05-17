#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>

#define DEVICE_NAME "my_calculator_device"
#define IOCTL_MAGIC 'c'
#define IOCTL_CALC _IOWR(IOCTL_MAGIC, 1, struct calc_data)

struct calc_data {
    int num1;
    int num2;
    char operation;
    int result;
};

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Calculator device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Calculator device closed\n");
    return 0;
}

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    struct calc_data data;

    switch (cmd) {
        case IOCTL_CALC:
            if (copy_from_user(&data, (struct calc_data __user *)arg, sizeof(data))) {
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
                        return -EINVAL; // Invalid argument
                    }
                    data.result = data.num1 / data.num2;
                    break;
                default:
                    return -EINVAL; 
            }

            if (copy_to_user((struct calc_data __user *)arg, &data, sizeof(data))) {
                return -EFAULT;
            }

            printk(KERN_INFO "Operation %c: %d %c %d = %d\n", data.operation, data.num1, data.operation, data.num2, data.result);
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

static int __init my_calculator_init(void) {
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

static void __exit my_calculator_exit(void) {
    cdev_del(&my_cdev);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Calculator device unregistered\n");
}

module_init(my_calculator_init);
module_exit(my_calculator_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple calculator char driver with ioctl");
MODULE_VERSION("0.1");
