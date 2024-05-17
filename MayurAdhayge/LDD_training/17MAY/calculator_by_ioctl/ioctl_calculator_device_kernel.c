#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>

#define DEVICE_NAME "ioctl_calculator_device"
#define IOCTL_CMD_ADD _IOWR('+', 1, struct calculation_info)
#define IOCTL_CMD_MINUS _IOWR('-', 2, struct calculation_info)
#define IOCTL_CMD_MUL _IOWR('*', 3, struct calculation_info)
#define IOCTL_CMD_DIV _IOWR('/', 4, struct calculation_info)


struct calculation_info
{
int value1;
int value2;
char ops;
float result;
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
    struct calculation_info info;

    switch (cmd) {
        case IOCTL_CMD_ADD:
            if (copy_from_user(&info, (struct calculation_info __user *)arg, sizeof(struct calculation_info))){
                return -EFAULT;
            }
            info.result = info.value2 + info.value2;
             printk(KERN_INFO "IOCTL opration :- %d %c %d= %.2f\n", info.value1,info.value2,info.ops,info.result);
           if (copy_to_user((struct calculation_info __user *)arg, &info,  sizeof(struct calculation_info)) ){
                return -EFAULT;
            }
           
            break;
       case IOCTL_CMD_MINUS:
            if (copy_from_user(&info, (struct calculation_info __user *)arg, sizeof(struct calculation_info))){
                return -EFAULT;
            }
            info.result = info.value2 - info.value2;
             printk(KERN_INFO "IOCTL opration :- %d %c %d= %.2f\n", info.value1,info.value2,info.ops,info.result);
            if (copy_to_user((struct calculation_info __user *)arg, &info,  sizeof(struct calculation_info)) ) {
                return -EFAULT;
            }
           
            break;
            
        case IOCTL_CMD_MUL:
            if (copy_from_user(&info, (struct calculation_info __user *)arg, sizeof(struct calculation_info))) {
                return -EFAULT;
            }
            info.result = info.value2 * info.value2;
             printk(KERN_INFO "IOCTL opration :- %d %c %d= %.2f\n", info.value1,info.value2,info.ops,info.result);
            if(copy_to_user((struct calculation_info __user *)arg, &info,  sizeof(struct calculation_info)))  {
                return -EFAULT;
            }
           
            break;
            
        case IOCTL_CMD_DIV:
            if (copy_from_user(&info, (struct calculation_info  __user *)arg, sizeof(struct calculation_info)) ){
                return -EFAULT;
            }
            info.result = info.value2 / (float)info.value2;
             printk(KERN_INFO "IOCTL opration :- %d %c %d= %.2f\n", info.value1,info.value2,info.ops,info.result);
            if (copy_to_user((struct calculation_info __user *)arg, &info,  sizeof(struct calculation_info)) ) {
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
MODULE_AUTHOR("mayur adhayge");
MODULE_DESCRIPTION("A simple Linux char driver with ioctl");


