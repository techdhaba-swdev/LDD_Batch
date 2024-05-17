



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
static int major;

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

static int __init calculator_init(void) {
major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "Double Integer: Device registered with major number %d\n", major);

    printk(KERN_INFO "Calculator module loaded\n");
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





