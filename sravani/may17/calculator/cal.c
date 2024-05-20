#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>

#define DEVICE_NAME "calculator_device"
#define IOCTL_MAGIC 'k'
#define IOCTL_CALCULATE _IOWR(IOCTL_MAGIC, 1, struct calc_data)

struct calc_data {
    int operand1;
    int operand2;
    char operator;
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
        case IOCTL_CALCULATE:
            if (copy_from_user(&data, (struct calc_data *)arg, sizeof(struct calc_data))) {
                return -EFAULT;
            }

            switch (data.operator) {
                case '+':
                    data.result = data.operand1 + data.operand2;
                    break;
                case '-':
                    data.result = data.operand1 - data.operand2;
                    break;
                case '*':
                    data.result = data.operand1 * data.operand2;
                    break;
                case '/':
                    if (data.operand2 != 0)
                        data.result = data.operand1 / data.operand2;
                    else
                        data.result = -1; // Error code for division by zero
                    break;
                default:
                    return -EINVAL; // Invalid operator
            }

            if (copy_to_user((struct calc_data *)arg, &data, sizeof(struct calc_data))) {
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

    printk(KERN_INFO "Device registered with major number %d\n", major_number);
    return 0;
}

static void __exit calculator_exit(void) {
    printk(KERN_INFO "Calculator module unloaded\n");
}

module_init(calculator_init);
module_exit(calculator_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Calculator Kernel Module");
	

