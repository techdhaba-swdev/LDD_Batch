#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include<linux/io.h>
#define DEVICE_NAME "mmap_char_device"
#define BUF_SIZE sizeof(struct Expression)

struct Expression {
    int operand1;
    int operand2;
    char operator;
    long result;
};

static int major;
static struct Expression *kernel_data;

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}
static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char __user *buffer, size_t length, loff_t *offset) {
    // Copy data from kernel structure to user space buffer
    return simple_read_from_buffer(buffer, length, offset, kernel_data, sizeof(struct Expression));
}

static ssize_t device_write(struct file *filp, const char __user *buffer, size_t length, loff_t *offset) {
    // Copy data from user space buffer to kernel structure
    int len = length;
    if (len >= BUF_SIZE)
        len = BUF_SIZE - 1;
    if (copy_from_user(kernel_data, buffer, len))
        return -EFAULT;
    kernel_data->operand1 = 0;
    kernel_data->operand2 = 0;
    kernel_data->operator = 0;
    kernel_data->result = 0;
    sscanf(buffer, "%d%c%d", &(kernel_data->operand1), &(kernel_data->operator), &(kernel_data->operand2));
    switch (kernel_data->operator) {
        case '+':
            kernel_data->result = kernel_data->operand1 + kernel_data->operand2;
            break;case '-':
            kernel_data->result = kernel_data->operand1 - kernel_data->operand2;
            break;
        default:
            printk(KERN_ERR "Invalid operator\n");
            break;
    }
    return len;
}

static int device_mmap(struct file *filp, struct vm_area_struct *vma) {
    return remap_pfn_range(vma, vma->vm_start, virt_to_phys(kernel_data) >> PAGE_SHIFT, BUF_SIZE, vma->vm_page_prot);
}

static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,.mmap = device_mmap,
};

static int __init device_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }

    kernel_data = kmalloc(sizeof(struct Expression), GFP_KERNEL);
    if (!kernel_data) {
        unregister_chrdev(major, DEVICE_NAME);
        return -ENOMEM;
    }

    printk(KERN_INFO "Registered a device with dynamic major number %d\n", major);
    return 0;
}

static void __exit device_exit(void) {
    kfree(kernel_data);
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Unregistered the device\n");
}
module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple mmap character device driver");
