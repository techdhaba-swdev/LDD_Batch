#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/io.h>
#define DEVICE_NAME "addition"
#define ADD_COUNT 10

static int major_number;
static int *kernel_buffer;

static int device_open(struct inode *inode, struct file *file) {
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    return 0;
}

static int device_mmap(struct file *file, struct vm_area_struct *vma) {
    return remap_pfn_range(vma, vma->vm_start, virt_to_phys((void*)kernel_buffer) >> PAGE_SHIFT,
                           vma->vm_end - vma->vm_start, vma->vm_page_prot);
}

static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
    .mmap = device_mmap,
};

static int __init addition_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    kernel_buffer = kmalloc(2 * ADD_COUNT * sizeof(int), GFP_KERNEL);
    if (!kernel_buffer) {
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ALERT "Failed to allocate kernel memory\n");
        return -ENOMEM;
    }
    printk(KERN_INFO "Addition module loaded with device major number %d\n", major_number);
    return 0;
}

static void __exit addition_exit(void) {
    kfree(kernel_buffer);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Addition module unloaded\n");
}

module_init(addition_init);
module_exit(addition_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("aman");
MODULE_DESCRIPTION("A simple addition module");
