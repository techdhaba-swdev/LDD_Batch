#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>
#include <linux/slab.h>

#define DEVICE_NAME "rev_dev"
#define IOCTL_REVERSE_STRING _IOWR('R', 1, char *)

static int major_num;
static char *msg = NULL;
static size_t msg_size = 0;

static long reverse_string_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    switch (cmd) {
        case IOCTL_REVERSE_STRING:
            if (copy_from_user(msg, (char *)arg, msg_size)) {
                printk(KERN_ERR "Failed to copy data from user space.\n");
                return -EFAULT;
            }
            int len = strlen(msg);
            for (int i = 0; i < len / 2; i++) {
                char temp = msg[i];
                msg[i] = msg[len - i - 1];
                msg[len - i - 1] = temp;
            }
            if (copy_to_user((char *)arg, msg, msg_size)) {
                printk(KERN_ERR "Failed to copy data to user space.\n");
                return -EFAULT;
            }
            break;
        default:
            return -ENOTTY;
    }
    return 0;
}

static int reverse_string_open(struct inode *inode, struct file *file) {
    msg_size = PAGE_SIZE;
    msg = kmalloc(msg_size, GFP_KERNEL);
    if (!msg) {
        printk(KERN_ALERT "Failed to allocate memory.\n");
        return -ENOMEM;
    }
    return 0;
}

static int reverse_string_release(struct inode *inode, struct file *file) {
    kfree(msg);
    return 0;
}

static struct file_operations fops = {
    .unlocked_ioctl = reverse_string_ioctl,
    .open = reverse_string_open,
    .release = reverse_string_release,
};

static int __init reverse_string_init(void) {
    major_num = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_num < 0) {
        printk(KERN_ALERT "Failed to register a major number.\n");
        return major_num;
    }
    printk(KERN_INFO "Reverse device registered with major number %d\n", major_num);
    return 0;
}

static void __exit reverse_string_exit(void) {
    unregister_chrdev(major_num, DEVICE_NAME);
    printk(KERN_INFO "Reverse device unregistered.\n");
}

module_init(reverse_string_init);
module_exit(reverse_string_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple module to reverse a string");
