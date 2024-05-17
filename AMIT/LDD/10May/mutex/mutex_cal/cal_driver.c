#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Arithmetic Device Driver with Mutex");

#define DEVICE_NAME "arithmetic"

static DEFINE_MUTEX(arithmetic_mutex);

static int arithmetic_open(struct inode *inode, struct file *file)
{
    pr_info("Arithmetic device opened\n");
    return 0;
}

static int arithmetic_release(struct inode *inode, struct file *file)
{
    pr_info("Arithmetic device closed\n");
    return 0;
}

static long arithmetic_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    int a, b;
    long result = 0;

    if (mutex_lock_interruptible(&arithmetic_mutex))
        return -ERESTARTSYS;

    switch (cmd) {
        case 'S': // Sum
            if (copy_from_user(&a, (int *)arg, sizeof(int)))
                goto unlock;
            if (copy_from_user(&b, (int *)(arg + sizeof(int)), sizeof(int)))
                goto unlock;
            result = a + b;
            break;
        case 'M': // Multiplication
            if (copy_from_user(&a, (int *)arg, sizeof(int)))
                goto unlock;
            if (copy_from_user(&b, (int *)(arg + sizeof(int)), sizeof(int)))
                goto unlock;
            result = a * b;
            break;
        case 'D': // Division
            if (copy_from_user(&a, (int *)arg, sizeof(int)))
                goto unlock;
            if (copy_from_user(&b, (int *)(arg + sizeof(int)), sizeof(int)))
                goto unlock;
            if (b != 0)
                result = a / b;
            else
                result = -EINVAL; // Division by zero
            break;
        case 'R': // Subtraction
            if (copy_from_user(&a, (int *)arg, sizeof(int)))
                goto unlock;
            if (copy_from_user(&b, (int *)(arg + sizeof(int)), sizeof(int)))
                goto unlock;
            result = a - b;
            break;
        default:
            result = -EINVAL; // Invalid command
            break;
    }

unlock:
    mutex_unlock(&arithmetic_mutex);
    return result;
}

static struct file_operations arithmetic_fops = {
    .owner = THIS_MODULE,
    .open = arithmetic_open,
    .release = arithmetic_release,
    .unlocked_ioctl = arithmetic_ioctl,
};

static int __init arithmetic_init(void)
{
    int ret;
    ret = register_chrdev(0, DEVICE_NAME, &arithmetic_fops);
    if (ret < 0) {
        pr_err("Failed to register arithmetic device\n");
        return ret;
    }
    pr_info("Arithmetic device registered\n");
    return 0;
}

static void __exit arithmetic_exit(void)
{
    unregister_chrdev(0, DEVICE_NAME);
    pr_info("Arithmetic device unregistered\n");
}

module_init(arithmetic_init);
module_exit(arithmetic_exit);
