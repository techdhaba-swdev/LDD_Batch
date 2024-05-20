#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>

#define DEVICE_NAME "calculator_device"

struct calculator_data {
    struct cdev cdev;
    dev_t dev_num;
    int operand1;
    int operand2;
    char operator;
    int result;
    struct task_struct *thread;
};

static struct calculator_data calc_data;

static int calculator_open(struct inode *inode, struct file *file) {
    pr_info("Calculator device opened\n");
    return 0;
}

static int calculator_release(struct inode *inode, struct file *file) {
    pr_info("Calculator device closed\n");
    return 0;
}

static ssize_t calculator_read(struct file *file, char __user *buffer, size_t length, loff_t *offset) {
    int bytes_read = 0;
    if (*offset != 0)
        return 0; // Reading is allowed only once

    if (copy_to_user(buffer, &calc_data.result, sizeof(int))) {
        pr_err("Failed to copy result to user\n");
        return -EFAULT;
    }

    bytes_read += sizeof(int);
    *offset += bytes_read;

    return bytes_read;
}

static int calculator_thread(void *data) {
    pr_info("Calculator thread started\n");

    // Perform the calculation
    switch (calc_data.operator) {
        case '+':
            calc_data.result = calc_data.operand1 + calc_data.operand2;
            break;
        case '-':
            calc_data.result = calc_data.operand1 - calc_data.operand2;
            break;
        case '*':
            calc_data.result = calc_data.operand1 * calc_data.operand2;
            break;
        case '/':
            if (calc_data.operand2 != 0)
                calc_data.result = calc_data.operand1 / calc_data.operand2;
            else
                calc_data.result = -1; // Error code for division by zero
            break;
        default:
            pr_err("Invalid operator\n");
            break;
    }

    pr_info("Calculator thread finished\n");
    return 0;
}

static ssize_t calculator_write(struct file *file, const char __user *buffer, size_t length, loff_t *offset) {
    struct calculator_data data;

    if (length != sizeof(struct calculator_data)) {
        pr_err("Invalid data size\n");
        return -EINVAL;
    }

    if (copy_from_user(&data, buffer, sizeof(struct calculator_data))) {
        pr_err("Failed to copy data from user\n");
        return -EFAULT;
    }

    calc_data.operand1 = data.operand1;
    calc_data.operand2 = data.operand2;
    calc_data.operator = data.operator;

    // Create a new thread to perform the calculation
    calc_data.thread = kthread_run(calculator_thread, NULL, "calculator_thread");
    if (IS_ERR(calc_data.thread)) {
        pr_err("Failed to create thread\n");
        return PTR_ERR(calc_data.thread);
    }

    return length;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = calculator_open,
    .release = calculator_release,
    .read = calculator_read,
    .write = calculator_write,
};

static int __init calculator_init(void) {
    int ret;

    // Allocate dynamically a major number
    ret = alloc_chrdev_region(&calc_data.dev_num, 0, 1, DEVICE_NAME);
    if (ret < 0) {
        pr_err("Failed to allocate character device region\n");
        return ret;
    }

    // Print the major number
    pr_info("Calculator module loaded, major number: %d\n", MAJOR(calc_data.dev_num));

    cdev_init(&calc_data.cdev, &fops);
    calc_data.cdev.owner = THIS_MODULE;

    ret = cdev_add(&calc_data.cdev, calc_data.dev_num, 1);
    if (ret < 0) {
        unregister_chrdev_region(calc_data.dev_num, 1);
        pr_err("Failed to add character device\n");
        return ret;
    }

    return 0;
}

static void __exit calculator_exit(void) {
    if (calc_data.thread) {
        kthread_stop(calc_data.thread);
    }

    cdev_del(&calc_data.cdev);
    unregister_chrdev_region(calc_data.dev_num, 1);
    pr_info("Calculator module unloaded\n");
}


module_init(calculator_init);
module_exit(calculator_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Calculator Kernel Module");
