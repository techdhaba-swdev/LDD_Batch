Dependency Inversion Principle (DIP) :definition of the Dependency Inversion Principle consists of two parts:

1.High-level modules should not depend on low-level modules. Both should depend on abstractions.
2.Abstractions should not depend on details. Details should depend on abstractions.

example :

// Abstract device interface
typedef struct {
    int (*open)(struct inode *inode, struct file *file);
    int (*release)(struct inode *inode, struct file *file);
    long (*ioctl)(struct file *file, unsigned int cmd, unsigned long arg);
} DeviceOperations;

// Concrete device implementation
static int my_device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int my_device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static long my_device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    int value;
    switch (cmd) {
        case IOCTL_CMD:
            if (copy_from_user(&value, (int __user *)arg, sizeof(value))) {
                return -EFAULT;
            }
            printk(KERN_INFO "IOCTL received: %d\n", value);
            break;
        default:
            return -ENOTTY;
    }
    return 0;
}

// Register concrete device operations
static DeviceOperations my_device_ops = {
    .open = my_device_open,
    .release = my_device_release,
    .ioctl = my_device_ioctl,
};

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = my_device_ops.open,
    .release = my_device_ops.release,
    .unlocked_ioctl = my_device_ops.ioctl,
};
