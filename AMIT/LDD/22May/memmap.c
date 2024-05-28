#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/io.h>

#define DEVICE_NAME "mmap_char_device"
#define BUF_SIZE 4096

struct Expression {
    int num1;
    int num2;
    char operation;
};

static int major;
static char *kernel_buffer;

// Perform the requested operation
static int perform_operation(int num1, int num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '%':
            return num1 % num2;

        default:
            return 0; // Invalid operation
    }
}


static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char __user *buffer, size_t length, loff_t *offset) {
    return simple_read_from_buffer(buffer, length, offset, kernel_buffer, BUF_SIZE);
}

static ssize_t device_write(struct file *filp, const char __user *buffer, size_t length, loff_t *offset) {
    ssize_t written = simple_write_to_buffer(kernel_buffer, BUF_SIZE, offset, buffer, length);
    if (written > 0) {
        printk(KERN_INFO "Kernel received from user: %s\n", kernel_buffer);

         // Parse the expression
        struct Expression expr;
        sscanf(kernel_buffer, "%d%c%d",&expr.num1, &expr.operation,&expr.num2);
        
        // Calculate the result
        int result =perform_operation(expr.num1, expr.num2,expr.operation);


        // Convert the result back to a string
        snprintf(kernel_buffer, BUF_SIZE, "Result: %d", result);
//	copy_to_user(buffer, kernel_buffer, strlen(kernel_buffer) + 1);
//	printk(KERN_INFO "Kernel result: %d\n", result);
    }
    return written;
}

static int device_mmap(struct file *filp, struct vm_area_struct *vma) {
    return remap_pfn_range(vma, vma->vm_start, virt_to_phys(kernel_buffer) >> PAGE_SHIFT, BUF_SIZE, vma->vm_page_prot);
}

static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
    .mmap = device_mmap,
};

static int __init device_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }

    kernel_buffer = kmalloc(BUF_SIZE, GFP_KERNEL);
    if (!kernel_buffer) {
        unregister_chrdev(major, DEVICE_NAME);
        return -ENOMEM;
    }

    printk(KERN_INFO "Registered a device with dynamic major number %d\n", major);
    return 0;
}

static void __exit device_exit(void) {
    kfree(kernel_buffer);
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Unregistered the device\n");
}

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple mmap character device driver");
