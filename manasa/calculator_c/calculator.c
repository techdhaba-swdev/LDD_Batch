#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "calculator"
#define MAJOR_NUMBER 240

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Calculator Module");

static int major_number;
static char calculation_result[20];
static int result_length;

static int device_open(struct inode *inode, struct file *file) {
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t device_read(struct file *file, char __user *buffer, size_t length, loff_t *offset) {
    ssize_t bytes_read = 0;

    if (*offset >= result_length) {
        return 0;
    }

    while (length && *offset < result_length) {
        put_user(calculation_result[*offset], buffer++);
        (*offset)++;
        length--;
        bytes_read++;
    }

    return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *buffer, size_t length, loff_t *offset) {
    char input[length];
    if (length > sizeof(input))
        return -EINVAL;

    if (copy_from_user(input, buffer, length))
        return -EFAULT;

    // Process the input and perform calculations
    // For simplicity, let's assume the input format is "operand1 operator operand2"

    // Perform calculation
    int operand1, operand2, result;
    char operator;
    sscanf(input, "%d %c %d", &operand1, &operator, &operand2);

    switch (operator) {
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
            if (operand2 == 0) {
                printk(KERN_ALERT "Division by zero error\n");
                return -EINVAL;
            }
            result = operand1 / operand2;
            break;
        default:
            printk(KERN_ALERT "Invalid operator\n");
            return -EINVAL;
    }

    // Convert result to string
    result_length = snprintf(calculation_result, sizeof(calculation_result), "%d\n", result);

    // Set the offset to 0 for next read
    *offset = 0;

    return length;
}

static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
};

static int __init calculator_init(void) {
    major_number = register_chrdev(MAJOR_NUMBER, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Calculator module loaded with major number %d\n", major_number);
    return 0;
}

static void __exit calculator_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Calculator module unloaded\n");
}

module_init(calculator_init);
module_exit(calculator_exit);
