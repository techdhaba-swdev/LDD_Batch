#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME_ADD "addition_integer"
#define DEVICE_NAME_SUB "subtraction_integer"
#define DEVICE_NAME_MUL "multiplication_integer"
#define DEVICE_NAME_DIV "division_integer"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");

static int major_add, major_sub, major_mul, major_div;
static int value_add, value_sub, value_mul, value_div;

// Addition Device
static int device_open_add(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Addition Device opened\n");
    return 0;
}

static int device_release_add(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Addition Device closed\n");
    return 0;
}

static ssize_t device_read_add(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    copy_to_user(buffer, &value_add, sizeof(int));
    printk(KERN_INFO "Addition Value sent to user space: %d\n", value_add);
    return sizeof(int);
}

static ssize_t device_write_add(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    int num1, num2;
    sscanf(buffer, "%d %d", &num1, &num2);
    value_add = num1 + num2; // Perform addition
    printk(KERN_INFO "Addition Value received from user space: %d\n", value_add);
    return sizeof(int);
}

static struct file_operations fops_add = {
    .read = device_read_add,
    .write = device_write_add,
    .open = device_open_add,
    .release = device_release_add,
};

// Subtraction Device
static int device_open_sub(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Subtraction Device opened\n");
    return 0;
}

static int device_release_sub(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Subtraction Device closed\n");
    return 0;
}

static ssize_t device_read_sub(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    copy_to_user(buffer, &value_sub, sizeof(int));
    printk(KERN_INFO "Subtraction Value sent to user space: %d\n", value_sub);
    return sizeof(int);
}

static ssize_t device_write_sub(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    int num1, num2;
    sscanf(buffer, "%d %d", &num1, &num2);
    value_sub = num1 - num2; // Perform subtraction
    printk(KERN_INFO "Subtraction Value received from user space: %d\n", value_sub);
    return sizeof(int);
}

static struct file_operations fops_sub = {
    .read = device_read_sub,
    .write = device_write_sub,
    .open = device_open_sub,
    .release = device_release_sub,
};

// Multiplication Device
static int device_open_mul(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Multiplication Device opened\n");
    return 0;
}

static int device_release_mul(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Multiplication Device closed\n");
    return 0;
}

static ssize_t device_read_mul(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    copy_to_user(buffer, &value_mul, sizeof(int));
    printk(KERN_INFO "Multiplication Value sent to user space: %d\n", value_mul);
    return sizeof(int);
}

static ssize_t device_write_mul(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    int num1, num2;
    sscanf(buffer, "%d %d", &num1, &num2);
    value_mul = num1 * num2; // Perform multiplication
    printk(KERN_INFO "Multiplication Value received from user space: %d\n", value_mul);
    return sizeof(int);
}

static struct file_operations fops_mul = {
    .read = device_read_mul,
    .write = device_write_mul,
    .open = device_open_mul,
    .release = device_release_mul,
};

// Division Device
static int device_open_div(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Division Device opened\n");
    return 0;
}

static int device_release_div(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Division Device closed\n");
    return 0;
}

static ssize_t device_read_div(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    copy_to_user(buffer, &value_div, sizeof(int));
    printk(KERN_INFO "Division Value sent to user space: %d\n", value_div);
    return sizeof(int);
}

static ssize_t device_write_div(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    int num1, num2;
    sscanf(buffer, "%d %d", &num1, &num2);
    if (num2 != 0) {
        value_div = num1 / num2; // Perform division
        printk(KERN_INFO "Division Value received from user space: %d\n", value_div);
    } else {
        printk(KERN_ALERT "Division by zero is not allowed\n");
    }
    return sizeof(int);
}

static struct file_operations fops_div = {
    .read = device_read_div,
    .write = device_write_div,
    .open = device_open_div,
    .release = device_release_div,
};

// Module Initialization and Exit
static int __init math_operations_init(void) {
    major_add = register_chrdev(0, DEVICE_NAME_ADD, &fops_add);
    if (major_add < 0) {
        printk(KERN_ALERT "Addition Device: Registering char device failed with %d\n", major_add);
        return major_add;
    }
    printk(KERN_INFO "Addition Integer: Device registered with major number %d\n", major_add);

    major_sub = register_chrdev(0, DEVICE_NAME_SUB, &fops_sub);
    if (major_sub < 0) {
        printk(KERN_ALERT "Subtraction Device: Registering char device failed with %d\n", major_sub);
        unregister_chrdev(major_add, DEVICE_NAME_ADD);
        return major_sub;
    }
    printk(KERN_INFO "Subtraction Integer: Device registered with major number %d\n", major_sub);

    major_mul = register_chrdev(0, DEVICE_NAME_MUL, &fops_mul);
    if (major_mul < 0) {
        printk(KERN_ALERT "Multiplication Device: Registering char device failed with %d\n", major_mul);
        unregister_chrdev(major_add, DEVICE_NAME_ADD);
        unregister_chrdev(major_sub, DEVICE_NAME_SUB);
        return major_mul;
    }
    printk(KERN_INFO "Multiplication Integer: Device registered with major number %d\n", major_mul);

    major_div = register_chrdev(0, DEVICE_NAME_DIV, &fops_div);
    if (major_div < 0) {
        printk(KERN_ALERT "Division Device: Registering char device failed with %d\n", major_div);
        unregister_chrdev(major_add, DEVICE_NAME_ADD);
        unregister_chrdev(major_sub, DEVICE_NAME_SUB);
        unregister_chrdev(major_mul, DEVICE_NAME_MUL);
        return major_div;
    }
    printk(KERN_INFO "Division Integer: Device registered with major number %d\n", major_div);

    return 0;
}

static void __exit math_operations_exit(void) {
    unregister_chrdev(major_add, DEVICE_NAME_ADD);
    unregister_chrdev(major_sub, DEVICE_NAME_SUB);
    unregister_chrdev(major_mul, DEVICE_NAME_MUL);
    unregister_chrdev(major_div, DEVICE_NAME_DIV);
    printk(KERN_INFO "Math Operations: Devices unregistered\n");
}

module_init(math_operations_init);
module_exit(math_operations_exit);
