#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "calcdev"
#define CALC_IO_MAGIC 'k'
#define CALC_ADD _IOWR(CALC_IO_MAGIC, 1, struct calc_data)
#define CALC_SUB _IOWR(CALC_IO_MAGIC, 2, struct calc_data)
#define CALC_MUL _IOWR(CALC_IO_MAGIC, 3, struct calc_data)
#define CALC_DIV _IOWR(CALC_IO_MAGIC, 4, struct calc_data)

struct calc_data {
    int operand1;
    int operand2;
    int result;
};

static long calc_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    struct calc_data data;

    if (copy_from_user(&data, (struct calc_data __user *)arg, sizeof(data))) {
        return -EFAULT;
    }

    switch (cmd) {
        case CALC_ADD:
            data.result = data.operand1 + data.operand2;
            break;
        case CALC_SUB:
            data.result = data.operand1 - data.operand2;
            break;
        case CALC_MUL:
            data.result = data.operand1 * data.operand2;
            break;
        case CALC_DIV:
            if (data.operand2 == 0) {
                return -EINVAL;
            }
            data.result = data.operand1 / data.operand2;
            break;
        default:
            return -EINVAL;
    }

    if (copy_to_user((struct calc_data __user *)arg, &data, sizeof(data))) {
        return -EFAULT;
    }

    return 0;
}

static int calc_open(struct inode *inode, struct file *file) {
    return 0;
}

static int calc_release(struct inode *inode, struct file *file) {
    return 0;
}

static struct file_operations fops = {
    .unlocked_ioctl = calc_ioctl,
    .open = calc_open,
    .release = calc_release,
};

static int __init calc_init(void) {
    int ret = register_chrdev(0, DEVICE_NAME, &fops);
    if (ret < 0) {
        printk(KERN_ALERT "calcdev: Failed to register char device\n");
        return ret;
    }
    printk(KERN_INFO "calcdev: Registered with major number %d\n", ret);
    return 0;
}

static void __exit calc_exit(void) {
    unregister_chrdev(0, DEVICE_NAME);
    printk(KERN_INFO "calcdev: Unregistered char device\n");
}

module_init(calc_init);
module_exit(calc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tech Dhaba");
MODULE_DESCRIPTION("A simple kernel space calculator");
