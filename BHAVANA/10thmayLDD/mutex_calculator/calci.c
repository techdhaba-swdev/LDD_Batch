#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>

#define DEVICE_NAME "calculator_dev"

static int major_number;
static char operation;
static int operand1;
static int operand2;
static int result;
static DEFINE_MUTEX(calculator_mutex); // Mutex definition

static int calculator_dev_open(struct inode *inode, struct file *file) {
    return 0;
}

static int calculator_dev_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t calculator_dev_write(struct file *file, const char *buf, size_t count, loff_t *ppos) {
    mutex_lock(&calculator_mutex); // Lock mutex before accessing shared variables
    sscanf(buf, "%c %d %d", &operation, &operand1, &operand2);
    switch (operation) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 != 0)
                result = operand1 / operand2;
            else
                result = -1; // Division by zero error
            break;
        default:
            mutex_unlock(&calculator_mutex); // Unlock mutex before returning
            return -EINVAL; // Invalid operation
    }
    mutex_unlock(&calculator_mutex); // Unlock mutex before returning
    return count;
}

static ssize_t calculator_dev_read(struct file *file, char *buf, size_t count, loff_t *ppos) {
    int len = 0;
    mutex_lock(&calculator_mutex); // Lock mutex before accessing shared variables
    if (result >= 0) {
        len = snprintf(buf, count, "%d\n", result);
        result = -1; // Reset result
    }
    mutex_unlock(&calculator_mutex); // Unlock mutex before returning
    return len;
}

static struct file_operations calculator_dev_fops = {
    .open = calculator_dev_open,
    .release = calculator_dev_release,
    .write = calculator_dev_write,
    .read = calculator_dev_read,
};

static int __init calculator_dev_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &calculator_dev_fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Calculator device registered, major number: %d\n", major_number);
    return 0;
}

static void __exit calculator_dev_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Calculator device unregistered\n");
}

module_init(calculator_dev_init);
module_exit(calculator_dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple calculator device driver");
