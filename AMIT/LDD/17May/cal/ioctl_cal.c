#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "calculator_ioctl"
#define IOCTL_MAGIC 'k'
#define IOCTL_CALCULATE _IOWR(IOCTL_MAGIC, 1, struct calc_request)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Custom IOCTL Calculator Device");

struct calc_request {
    int num1;
    int num2;
    char operation;
    int result;
};

static long my_ioctl_device_ioctl(struct file *filp, unsigned int cmd, unsigned long arg) {
    struct calc_request request;

    switch (cmd) {
        case IOCTL_CALCULATE:
            if (copy_from_user(&request, (struct calc_request *)arg, sizeof(struct calc_request)))
                return -EFAULT;

            switch (request.operation) {
                case 'a':
                    request.result = request.num1 + request.num2;
                    break;
                case 's':
                    request.result = request.num1 - request.num2;
                    break;
                case 'm':
                    request.result = request.num1 * request.num2;
                    break;
                case 'd':
                    if (request.num2 != 0)
                        request.result = request.num1 / request.num2;
                    else
                        return -EINVAL; // Division by zero
                    break;
                default:
                    return -EINVAL; // Invalid operation
            }

            if (copy_to_user((struct calc_request *)arg, &request, sizeof(struct calc_request)))
                return -EFAULT;
            break;

        default:
            return -ENOTTY; // Invalid command
    }

    return 0;
}

static int my_ioctl_device_open(struct inode *inode, struct file *filp) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int my_ioctl_device_release(struct inode *inode, struct file *filp) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = my_ioctl_device_open,
    .release = my_ioctl_device_release,
    .unlocked_ioctl = my_ioctl_device_ioctl,
    // Other file operations (read, write, etc.) go here
};

static int __init my_ioctl_device_init(void) {
    int result;

    result = register_chrdev(0, DEVICE_NAME, &fops);
    if (result < 0) {
        printk(KERN_ALERT "Failed to register the device\n");
        return result;
    }

    printk(KERN_INFO "Custom IOCTL device initialized\n");
    return 0;
}

static void __exit my_ioctl_device_exit(void) {
    unregister_chrdev(0, DEVICE_NAME);
    printk(KERN_INFO "Custom IOCTL device unloaded\n");
}

module_init(my_ioctl_device_init);
module_exit(my_ioctl_device_exit);
