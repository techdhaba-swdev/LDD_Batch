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
    printk(KERN_INFO "mmap_char_device: Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "mmap_char_device: Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char __user *buffer, size_t length, loff_t *offset) {
    printk(KERN_INFO "mmap_char_device: Reading from device\n");
    return simple_read_from_buffer(buffer, length, offset, kernel_buffer, BUF_SIZE);
}

static ssize_t device_write(struct file *filp, const char __user *buffer, size_t length, loff_t *offset) {
    printk(KERN_INFO "mmap_char_device: Writing to device\n");
    return simple_write_to_buffer(kernel_buffer, BUF_SIZE, offset, buffer, length);
}

static int device_mmap(struct file *filp, struct vm_area_struct *vma) {
    unsigned long pfn = virt_to_phys(kernel_buffer) >> PAGE_SHIFT;
    unsigned long size = vma->vm_end - vma->vm_start;

    if (size > BUF_SIZE) {
        printk(KERN_ERR "mmap_char_device: Requested size exceeds buffer size\n");
        return -EINVAL;
    }

    if (remap_pfn_range(vma, vma->vm_start, pfn, size, vma->vm_page_prot)) {
        printk(KERN_ERR "mmap_char_device: remap_pfn_range failed\n");
        return -EAGAIN;
    }

    printk(KERN_INFO "mmap_char_device: Memory mapped successfully\n");
    return 0;
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
        printk(KERN_ALERT "mmap_char_device: Registering char device failed with %d\n", major);
        return major;
    }

    kernel_buffer = kmalloc(BUF_SIZE, GFP_KERNEL);
    if (!kernel_buffer) {
        unregister_chrdev(major, DEVICE_NAME);
        return -ENOMEM;
    }

    printk(KERN_INFO "mmap_char_device: Registered with major number %d\n", major);
    return 0;
}

static void __exit device_exit(void) {
    kfree(kernel_buffer);
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "mmap_char_device: Unregistered\n");
}

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple mmap character device driver");
