#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h> // Include ioctl header

#define DEVICE_NAME "calculator_dev"

#define CALCULATOR_IOC_MAGIC 'k'
#define CALCULATOR_IOC_SET_OPERATION _IOW(CALCULATOR_IOC_MAGIC, 1, char)
#define CALCULATOR_IOC_SET_OPERANDS _IOW(CALCULATOR_IOC_MAGIC, 2, int[2])
#define CALCULATOR_IOC_GET_RESULT _IOR(CALCULATOR_IOC_MAGIC, 3, int)

static int major_number;
static char operation;
static int operands[2];
static int result;

static int calculator_dev_open(struct inode *inode, struct file *file) {
    return 0;
}

static int calculator_dev_release(struct inode *inode, struct file *file) {
    return 0;
}

static long calculator_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    switch (cmd) {
        case CALCULATOR_IOC_SET_OPERATION:
            copy_from_user(&operation, (char *)arg, sizeof(char));
            break;
        case CALCULATOR_IOC_SET_OPERANDS:
            copy_from_user(operands, (int *)arg, sizeof(int[2]));
            break;
        case CALCULATOR_IOC_GET_RESULT:
            switch (operation) {
                case '+':
                    result = operands[0] + operands[1];
                    break;
                case '-':
                    result = operands[0] - operands[1];
                    break;
                case '*':
                    result = operands[0] * operands[1];
                    break;
                case '/':
                    if (operands[1] != 0)
                        result = operands[0] / operands[1];
                    else
                        result = -1; // Division by zero error
                    break;
                default:
                    return -EINVAL; // Invalid operation
            }
            copy_to_user((int *)arg, &result, sizeof(int));
            break;
        default:
            return -ENOTTY; // Not a valid IOCTL command
    }
    return 0;
}

static struct file_operations calculator_dev_fops = {
    .open = calculator_dev_open,
    .release = calculator_dev_release,
    .unlocked_ioctl = calculator_dev_ioctl, // Use unlocked_ioctl for newer kernels
};

static int __init calculator_dev_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &calculator_dev_fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Calculator device registered, major number: %d\n", major_number);
    return 0;
}

static void __exit calculator_dev_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Calculator device unregistered\n");
}

module_init(calculator_dev_init);
module_exit(calculator_dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple calculator device driver with IOCTL support");
