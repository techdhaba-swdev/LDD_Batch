#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define DEVICE_NAME "my_device"
#define DEVICE_MEMORY_SIZE 4096  // 4KB

static char *device_memory;
static int major_number;

static int my_device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "my_device: open\n");
    return 0;
}

static int my_device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "my_device: release\n");
    return 0;
}

static ssize_t my_device_read(struct file *filp, char __user *buffer, size_t len, loff_t *offset) {
    size_t bytes_to_read=0;

    if (*offset >= DEVICE_MEMORY_SIZE) //checking for the position of offset if it is at end or past the end of device memory
        return 0;

    bytes_to_read = min(len, DEVICE_MEMORY_SIZE - *offset); //calculating number of bytes to read,this is min of len and remaining space

    if (copy_to_user(buffer, device_memory + *offset, bytes_to_read)) { //copying requested data from device memory to user buffer
        return -EFAULT; //if copying to user fails it returns an error
    }

    *offset += bytes_to_read; //updating the file offset by number of bytes to read
    printk(KERN_INFO "my_device: read %zu bytes\n", bytes_to_read);

    return bytes_to_read;
}

static ssize_t my_device_write(struct file *filp, const char __user *buffer, size_t len, loff_t *offset) {
    size_t bytes_to_write=0;

    if (*offset >= DEVICE_MEMORY_SIZE) //checking similarly as read sys-call for position of offset
        return -ENOSPC;

    bytes_to_write = min(len, DEVICE_MEMORY_SIZE - *offset); //calculating number of bytes to write

    if (copy_from_user(device_memory + *offset, buffer, bytes_to_write)) { //copying data from user buffer to device memory
        return -EFAULT; //if fails returns an error
    }

    *offset += len;
    bytes_to_write=len;
    printk(KERN_INFO "my_device: wrote %zu bytes\n", bytes_to_write);

    return bytes_to_write;
}

static int my_device_mmap(struct file *filp, struct vm_area_struct *vma) { 
	//mmap taking file pointer to struct file  and vma pointer to vm_area_structure
    
    unsigned long offset = vma->vm_pgoff << PAGE_SHIFT; 
    //calculating the pagebyte offset within memory and converting pageoffset to byteoffset and PAGESHIFT represents size of memory page
    
    unsigned long physical_address = virt_to_phys(device_memory) + offset; 
    //converting virtual address of device memory to physical address and the offset is added to get particular address that is mapped
    
    unsigned long size = vma->vm_end - vma->vm_start; //calculating size of memory region for mapping in user virtual address space

    if (size > DEVICE_MEMORY_SIZE) { //checking if requested size is greater than device memory
        return -EINVAL; //if fails returns error
    }

    if (remap_pfn_range(vma, vma->vm_start, physical_address >> PAGE_SHIFT, size, vma->vm_page_prot)) 
    { //this api will do actual mapping
        return -EAGAIN;
    }

    return 0;
}
static const struct file_operations my_device_fops = {
    .owner = THIS_MODULE,
    .open = my_device_open,
    .release = my_device_release,
    .read = my_device_read,
    .write = my_device_write,
    .mmap = my_device_mmap,
};

static int __init my_device_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &my_device_fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number);
        return major_number;
    }

    device_memory = kmalloc(DEVICE_MEMORY_SIZE, GFP_KERNEL);
    if (!device_memory) {
        unregister_chrdev(major_number, DEVICE_NAME);
        return -ENOMEM;
    }

    printk(KERN_INFO "my_device: registered with major number %d\n", major_number);
    printk(KERN_INFO "my_device: memory allocated at %p\n", device_memory);
    return 0;
}

static void __exit my_device_exit(void) {
    kfree(device_memory);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "my_device: unregistered\n");
}

module_init(my_device_init);
module_exit(my_device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SARATH");
MODULE_DESCRIPTION("Example Device Driver with mmap, read, and write");
