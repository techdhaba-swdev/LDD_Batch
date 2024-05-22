#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "calculator"
#define BUF_LEN 80

static int major_num;
static int result;
static char operation;
static char operand[BUF_LEN];

static int calc_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Calculator device opened\n");
    return 0;
}

static int calc_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Calculator device closed\n");
    return 0;
}

static ssize_t calc_read(struct file *file, char *buffer, size_t length, loff_t *offset)
{
    int bytes_read = 0;

    if (*offset > 0)
        return 0;

    bytes_read = sprintf(buffer, "Result: %d\n", result);
    *offset += bytes_read;

    return bytes_read;
}

static ssize_t calc_write(struct file *file, const char *buffer, size_t length, loff_t *offset)
{
    int bytes_written = 0;

    if (length > BUF_LEN)
        return -EINVAL;

    if (copy_from_user(operand, buffer, length))
        return -EFAULT;

    operand[length - 1] = '\0'; // null terminate the string

    // Parse the input
    sscanf(operand, "%d %c", &result, &operation);

    switch (operation)
    {
    case '+':
        printk(KERN_INFO "Addition operation\n");
        break;
    case '-':
        printk(KERN_INFO "Subtraction operation\n");
        break;
    case '*':
        printk(KERN_INFO "Multiplication operation\n");
        break;
    case '/':
        printk(KERN_INFO "Division operation\n");
        break;
    default:
        printk(KERN_ERR "Invalid operation\n");
        return -EINVAL;
    }

    return length;
}

static struct file_operations fops = {
    .open = calc_open,
    .release = calc_release,
    .read = calc_read,
    .write = calc_write,
};

static int __init calc_init(void)
{
    major_num = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_num < 0)
    {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_num;
    }
    printk(KERN_INFO "Calculator device registered with major number %d\n", major_num);
    return 0;
}

static void __exit calc_exit(void)
{
    unregister_chrdev(major_num, DEVICE_NAME);
    printk(KERN_INFO "Calculator device unregistered\n");
}

module_init(calc_init);
module_exit(calc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple Calculator Device Driver");
