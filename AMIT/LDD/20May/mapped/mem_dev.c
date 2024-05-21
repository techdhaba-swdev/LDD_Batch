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
static ssize_t my_device_read(struct file *filp, char __user *buf, size_t len, loff_t *offset) {
 
    printk(KERN_INFO "my_devic: read\n");
    
    return 0;
}

static ssize_t my_device_write(struct file *filp, const char __user *buf, size_t len, loff_t *offset) {
    ssize_t bytes_written = 0;

 
    if (!buf || len == 0) {
        return -EINVAL; // Invalid argument
    }


    if (*offset + len > DEVICE_MEMORY_SIZE) {
        return -EFBIG; // File too large
    }

    // Copy data from user buffer (buf) to device_memory
    if (copy_from_user(device_memory + *offset, buf, len)) {
        return -EFAULT; // Error copying data
    }

  
    *offset += len;
    bytes_written = len;

    printk(KERN_INFO "my_device: %zu bytes written\n", bytes_written);
    return bytes_written;
}


static int my_device_mmap(struct file *filp, struct vm_area_struct *vma) {
    unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;
    unsigned long physical_address = virt_to_phys(device_memory) + offset;
    unsigned long size = vma->vm_end - vma->vm_start;

    if (size > DEVICE_MEMORY_SIZE) {
        return -EINVAL;
    }

    if (remap_pfn_range(vma, vma->vm_start, physical_address >> PAGE_SHIFT, size, vma->vm_page_prot)) {
        return -EAGAIN;
    }

    //print data in mmap memory
   
    printk(KERN_INFO "my_device: Data in the device memory : %s\n", device_memory);
    return 0;
}

static const struct file_operations my_device_fops = {
    .owner = THIS_MODULE,
    .open = my_device_open,
    .release = my_device_release,
    .read= my_device_read,
    .write= my_device_write,
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
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Example Device Driver with mmap");
