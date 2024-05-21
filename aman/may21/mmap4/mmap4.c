#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#define SHARED_BUFFER_SIZE 4096 
#define DEVICE_NAME "mmap4_device"
static char *shared_buffer;
static struct page *shared_page;

static int map_fault(struct vm_fault *vmf) {
	vmf->page = shared_page;
	get page(vmf->page);
	return 0;
}
static struct vm_operations_struct vm_ops = {
	.fault = mmap_fault,
};
static int mmap_open(struct inode *inode, struct file *filp) {
	return 0;
}
static int mmap_release(struct inode *inode, struct file *filp) {
	return 0;
}
static int mmap_mmap(struct file *filp, struct vm_area_struct *vma) {
	return remap_pfn_range(vma, vma->vm_start, virt_to_phys(shared_buffer) >> PAGE_SHIFT, vma->vm_end - vma->vm_start, vma->vm_pagr_prot);
}
static const struct file_operations mmap_fops = {
	.owner = THIS_MODULE,
	.open = mmap_open,
	.release = mmap_release,
	.mmap = mmap_mmap,
};
static struct miscdevice mmap_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "mymmap",
	.fops = &mmap_fops,
};
static int __init mmap_init(void) {
	int ret;
	shared_buffer = (char *)__get_free_pages(GFP_KERNAL, 0);
	if (!shared_buffer) {
		return -ENOMEM;
	}
	shared_page = virt_to_page(shared_buffer);
	ret = misc_register(&mmap_dev);
	if (ret) {
		free_page((unsigned long)shared_buffer);
		return ret;
	}
	return 0;
}
static void __exit mmap_exit(void) {
	misc_deregister(&mmap_dev);
	free_page((unsigned long)shared_buffer);
}
module_init(mmap_init);
module_exit(mmap_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AMANRAJ");
MODULE_DESCRIPTION("SIMPLE MMAP EXAMPLE");

