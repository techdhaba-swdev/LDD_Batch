Interface Segregation Principle (ISP) : It means creating smaller more detailed interface rather than larger ones.

example :

In ISP, we can separate the device operations (open, release, ioctl) into distinct functions, each handling a single responsibility.

static int open_device(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int release_device(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static long handle_ioctl_cmd(struct file *file, unsigned long arg) {
    int value;
    if (copy_from_user(&value, (int __user *)arg, sizeof(value))) {
        return -EFAULT;
    }
    printk(KERN_INFO "IOCTL received: %d\n", value);
    return 0;
}

static struct file_operations fops = {isp
    .owner = THIS_MODULE,
    .open = open_device,
    .release = release_device,
    .unlocked_ioctl = handle_ioctl_cmd,
};
