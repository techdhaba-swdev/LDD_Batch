#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "calc"
#define BUF_LEN 80

static int major_num;
static int result;
static char operation;
static char number[BUF_LEN];
static int num_len;
static int calc_open(struct inode *inode, struct file *file);
static int calc_release(struct inode *inode, struct file *file);
static ssize_t calc_read(struct file *file, char *buffer, size_t length, loff_t *offset);
static ssize_t calc_write(struct file *file, const char *buffer, size_t length, loff_t *offset);

static struct file_operations fops = {
    .open = calc_open,
    .read = calc_read,
    .write = calc_write,
    .release = calc_release
};

static int __init calc_init(void) {
    major_num = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_num < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_num;
    }
    printk(KERN_INFO "Calculator module loaded with major number %d\n", major_num);
    return 0;
}

static void __exit calc_exit(void) {
    unregister_chrdev(major_num, DEVICE_NAME);
    printk(KERN_INFO "Calculator module unloaded\n");
}

static int calc_open(struct inode *inode, struct file *file) {
    result = 0;
    num_len = 0;
    return 0;
}

static int calc_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t calc_read(struct file *file, char *buffer, size_t length, loff_t *offset) {
    int bytes_read = 0;
    if (result != 0) {
        bytes_read = sprintf(buffer, "%d\n", result);
        result = 0;
    }
    return bytes_read;
}

static ssize_t calc_write(struct file *file, const char *buffer, size_t length, loff_t *offset) {
    char operation;
    int operand;
    if (buffer == '+' || *buffer == '-' || *buffer == '*' || *buffer == '/') {
        operation = *buffer;
        num_len = 0;
    } else if (*buffer >= '0' && *buffer <= '9') {
        number[num_len++] = *buffer;
        if (num_len >= BUF_LEN) {
            num_len = 0;
            printk(KERN_ALERT "Input buffer full. Please provide a smaller number.\n");
        }
        return length;
    } else if (*buffer == '\n' && num_len > 0) {
        number[num_len] = '\0';
        operand = simple_strtol(number, NULL, 10);
        switch (operation) {
            case '+':
                result += operand;
                break;
            case '-':
                result -= operand;
                break;
            case '*':
                result *= operand;
                break;
            case '/':
                if (operand == 0) {
                    printk(KERN_ALERT "Division by zero is not allowed.\n");
                } else {
                    result /= operand;
                }
                break;
            default:
                printk(KERN_ALERT "Invalid operation\n");
                break;
        }
        num_len = 0;
    }
    return length;
}

module_init(calc_init);
module_exit(calc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("aman raj");
MODULE_DESCRIPTION("Simple Calculator Kernel Module");
