#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#define DEVICE_NAME "mmap_char_device"
#define BUF_SIZE 4096

static int major;
static char *kernel_buffer;

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
    ssize_t written;

    if (length > BUF_SIZE) {
        printk(KERN_ERR "Data too large for buffer\n");
        return -EINVAL;
    }

    // Copy data from user space buffer to kernel buffer
    written = copy_from_user(kernel_buffer, buffer, length);
    if (written != 0) {
        printk(KERN_ERR "Failed to copy data from user space\n");
        return -EFAULT;
    }

    printk(KERN_INFO "Kernel received from user: %s\n", kernel_buffer);

    return length;
}

static int device_mmap(struct file *filp, struct vm_area_struct *vma) {
    return remap_pfn_range(vma, vma->vm_start, virt_to_phys(kernel_buffer) >> PAGE_SHIFT, BUF_SIZE, vma->vm_page_prot);
}

static long perform_operation(char *data) {
    int result = 0;
    char operation;
    int num;

    // Use sscanf to tokenize the input string
    if (sscanf(data, "%d %c", &num, &operation) != 2) {
        printk(KERN_WARN "Invalid input format\n");
        return 0;
    }

    switch (operation) {
        case '+':
            result = num;
            break;
        case '-':
            result = num;
     break;
        default:
            printk(KERN_WARN "Invalid operation\n");
            return 0;
    }

    return result;
}

static long calculate_result(void) {
    int result = 0;
    char *data;

    // Allocate memory for a copy of the kernel buffer
    data = kmalloc(BUF_SIZE, GFP_KERNEL);
    if (!data)
        return -ENOMEM;

    // Copy data from kernel buffer to the allocated memory using memcpy
    memcpy(data, kernel_buffer, BUF_SIZE);

    // Perform the arithmetic operation result = perform_operation(data_copy);

    // Free allocated memory
    kfree(data_copy);

    return result;
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
    if (!kernel_buffer) { unregister_chrdev(major, DEVICE_NAME);
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
