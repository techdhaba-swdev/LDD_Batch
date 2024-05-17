#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>

#define DEVICE_NAME "calculator"
#define CALC_IOC_MAGIC 'k'
#define CALC_IOC_OPER _IOWR(CALC_IOC_MAGIC, 1, struct calc_data)

struct calc_data {
    int num1;
    int num2;
    char operation[10];
    int result;
};

static int major;
static struct cdev calc_cdev;

static long calc_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    struct calc_data data;

    if (cmd == CALC_IOC_OPER) {
        if (copy_from_user(&data, (struct calc_data *)arg, sizeof(data))) {
            return -EFAULT;
        }

        // Perform the calculation based on the operation
        if (strcmp(data.operation, "add") == 0) {
            data.result = data.num1 + data.num2;
        } else if (strcmp(data.operation, "sub") == 0) {
            data.result = data.num1 - data.num2;
        } else if (strcmp(data.operation, "mul") == 0) {
            data.result = data.num1 * data.num2;
        } else if (strcmp(data.operation, "div") == 0) {
            if (data.num2 == 0) {
                return -EINVAL; // Division by zero
            }
            data.result = data.num1 / data.num2;
        } else {
            return -EINVAL; // Unknown operation
        }

        if (copy_to_user((struct calc_data *)arg, &data, sizeof(data))) {
            return -EFAULT;
        }
        return 0;
    }
    return -EINVAL;
}

static int calc_open(struct inode *inode, struct file *file) {
    return 0;
}

static int calc_release(struct inode *inode, struct file *file) {
    return 0;
}

static const struct file_operations calc_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = calc_ioctl,
    .open = calc_open,
    .release = calc_release,
};

static int __init calc_init(void) {
    dev_t dev;

    // Allocate a major number
    if (alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME) < 0) {
        return -1;
    }
    major = MAJOR(dev);

    // Initialize the cdev structure and add it to the kernel
    cdev_init(&calc_cdev, &calc_fops);
    if (cdev_add(&calc_cdev, dev, 1) == -1) {
        unregister_chrdev_region(dev, 1);
        return -1;
    }

    printk(KERN_INFO "Calculator module loaded with device major number %d\n", major);
    return 0;
}

static void __exit calc_exit(void) {
    cdev_del(&calc_cdev);
    unregister_chrdev_region(MKDEV(major, 0), 1);
    printk(KERN_INFO "Calculator module unloaded\n");
}

module_init(calc_init);
module_exit(calc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("OpenAI");
MODULE_DESCRIPTION("A simple calculator kernel module");
