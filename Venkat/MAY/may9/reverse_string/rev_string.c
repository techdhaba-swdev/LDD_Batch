#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "revstr_drive"

static dev_t dev_number;
static struct cdev cdev;

static char message[100] = {0};
static int message_len = 0;

static void reverse_string(char *str, int len) {
    int start = 0;
    int end = len - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

static int reverse_dev_open(struct inode *inode, struct file *filp) {
    printk(KERN_INFO "reverse_dev: Device opened\n");
    return 0;
}

static ssize_t reverse_dev_write(struct file *filp, const char __user *user_buf,
                                 size_t count, loff_t *f_pos) {
    if (count >= sizeof(message)) {
        printk(KERN_WARNING "reverse_dev: String too long\n");
        return -EINVAL;
    }

    memset(message, 0, sizeof(message));

    if (copy_from_user(message, user_buf, count)) {
        return -EFAULT;
    }

    message_len = strlen(message);
    reverse_string(message, message_len);

    printk(KERN_INFO "reverse_dev: Received and reversed string: %s\n", message);
    return count;
}

static ssize_t reverse_dev_read(struct file *filp, char __user *user_buf,
                                size_t count, loff_t *f_pos) {
    int bytes_read = 0;

    if (*f_pos >= message_len) {
        return 0;
    }

    if (count > message_len - *f_pos) {
        count = message_len - *f_pos;
    }

    if (copy_to_user(user_buf, message + *f_pos, count)) {
        return -EFAULT;
    }

    *f_pos += count;
    bytes_read = count;
    return bytes_read;
}

static int reverse_dev_release(struct inode *inode, struct file *filp) {
    printk(KERN_INFO "reverse_dev: Device closed\n");
    return 0;
}

static const struct file_operations reverse_dev_fops = {
    .owner = THIS_MODULE,
    .open = reverse_dev_open,
    .write = reverse_dev_write,
    .read = reverse_dev_read,
    .release = reverse_dev_release,
};

static int __init reverse_dev_init(void) {
    int ret;

    ret = alloc_chrdev_region(&dev_number, 0, 1, DEVICE_NAME);
    if (ret < 0) {
        printk(KERN_ALERT "reverse_dev: Failed to allocate device number\n");
        return ret;
    }

    cdev_init(&cdev, &reverse_dev_fops);

    ret = cdev_add(&cdev, dev_number, 1);
    if (ret < 0) {
        printk(KERN_ALERT "reverse_dev: Failed to add device\n");
        unregister_chrdev_region(dev_number, 1);
        return ret;
    }

    printk(KERN_INFO "reverse_dev: Device registered with major number %d\n", MAJOR(dev_number));
    return 0;
}

static void __exit reverse_dev_exit(void) {
    cdev_del(&cdev);
    unregister_chrdev_region(dev_number, 1);
    printk(KERN_INFO "reverse_dev: Device unregistered\n");
}

module_init(reverse_dev_init);
module_exit(reverse_dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Character device driver for reversing strings");
