#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>

#define DEVICE_NAME "calculator"

DEFINE_MUTEX(calc_mutex); // Define a mutex
static int major_number;
static char operation;
static int operand1;
static int operand2;
static int result;

static ssize_t calculator_dev_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset) {
    ssize_t bytes_read = 0;
    mutex_lock(&calc_mutex);  // Lock mutex before critical section
    // Prepare result string to be copied to user space
    char result_str[50];
    int len = snprintf(result_str, sizeof(result_str), "%d\n", result);
    // Copy result string to user space
    if (len > 0)
        bytes_read = simple_read_from_buffer(user_buffer, count, offset, result_str, len);
    mutex_unlock(&calc_mutex);  // Unlock mutex after critical section
    return bytes_read;
}

static ssize_t calculator_dev_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset) {
    ssize_t bytes_written = 0;
    mutex_lock(&calc_mutex);  // Lock mutex before critical section
    char input[20];
    if (count > sizeof(input))
        count = sizeof(input) - 1;
    if (copy_from_user(input, user_buffer, count)) {
        mutex_unlock(&calc_mutex);  // Unlock mutex on error
        return -EFAULT;  // Error copying data from user space
    }
    input[count] = '\0';  // Null-terminate the input string
    sscanf(input, "%c %d %d", &operation, &operand1, &operand2);
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
            mutex_unlock(&calc_mutex);  // Unlock mutex on error
            return -EINVAL; // Invalid operation
    }
    bytes_written = count;  // Report bytes written
    mutex_unlock(&calc_mutex);  // Unlock mutex after critical section
    return bytes_written;
}

static const struct file_operations calculator_dev_fops = {
    .owner = THIS_MODULE,
    .read = calculator_dev_read,
    .write = calculator_dev_write,
};

static int __init calculator_dev_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &calculator_dev_fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Calculator device registered, major number: %d\n", major_number);

    mutex_init(&calc_mutex);  // Initialize the mutex

    return 0;
}

static void __exit calculator_dev_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Calculator device unregistered\n");

    mutex_destroy(&calc_mutex);  // Destroy the mutex
}

module_init(calculator_dev_init);
module_exit(calculator_dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple calculator device driver with mutex");

	

