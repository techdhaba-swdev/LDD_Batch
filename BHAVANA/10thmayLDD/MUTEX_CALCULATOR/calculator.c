#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>
#include <linux/string.h>

#define DEVICE_NAME "calculator"

DEFINE_MUTEX(driver_mutex); // Define a mutex
static int major_number;
static dev_t dev_num;
static struct cdev my_cdev;

static ssize_t driver_read(struct file *f, char __user *user_buffer, size_t count, loff_t *offset) {
    char result[100]; // Buffer to hold the result
    int result_len;
    mutex_lock(&driver_mutex);

    // Read the result from the user space buffer
    result_len = strlen(result);
    if (copy_to_user(user_buffer, result, result_len) != 0) {
        mutex_unlock(&driver_mutex);
        return -EFAULT; // Error copying data to user space
    }

    mutex_unlock(&driver_mutex);
    return result_len; // Return the number of bytes read
}

static ssize_t driver_write(struct file *f, const char __user *user_buffer, size_t count, loff_t *offset) {
    char expression[100]; // Buffer to hold the expression
    int expression_len;
    mutex_lock(&driver_mutex);

    // Read the expression from the user space buffer
    expression_len = min(count, sizeof(expression) - 1); // Limit the expression length to avoid buffer overflow
    if (copy_from_user(expression, user_buffer, expression_len) != 0) {
        mutex_unlock(&driver_mutex);
        return -EFAULT; // Error copying data from user space
    }
    expression[expression_len] = '\0'; // Null-terminate the string

    // Calculate the result (for simplicity, assuming the expression is in the form "num1+num2")
    int num1, num2;
    char operator;
    if (sscanf(expression, "%d%c%d", &num1, &operator, &num2) != 3) {
        mutex_unlock(&driver_mutex);
        return -EINVAL; // Invalid expression format
    }

    int result;
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                mutex_unlock(&driver_mutex);
                return -EINVAL; // Division by zero
            }
            result = num1 / num2;
            break;
        default:
            mutex_unlock(&driver_mutex);
            return -EINVAL; // Invalid operator
    }

    // Convert the result to a string
    snprintf(result, sizeof(result), "%d", result);

    mutex_unlock(&driver_mutex);
    return count; // Return the number of bytes written
}

static const struct file_operations driver_fops = {
    .owner = THIS_MODULE,
    .read = driver_read,
    .write = driver_write,
};

static int __init my_driver_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &driver_fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }

    printk(KERN_INFO "Calculator device registered, major number: %d\n", major_number);
    return 0;
}

static void __exit my_driver_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Calculator device unregistered\n");
}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple calculator device driver");
