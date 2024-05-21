#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define DEVICE_NAME "my_device"
#define DEVICE_MEMORY_SIZE 4096

static char *device_memory;
static int major_number;

static int my_device_open(struct inode *inode, struct file *file) {
    return 0;
}

static int my_device_release(struct inode *inode, struct file *file) {
    return 0;
}

//process for below mmap
 // iam doing 3 process here
  // 1 need to identify the physical address from page/pagetable it is identified by page frame number how can i do
  // i will shift the physical address with page shift to the right here page_offset is mapped from 1 to 32 bits thi is the size
  // what it will 'do struct vm_area_struct *vma' 
  // vm_start it is beginning of the memory and vm_end is the end of the memeory 
static int my_device_mmap(struct file *filp, struct vm_area_struct *vma) { // i have here created page is vma 
    unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;  //  here the process need to identify the physcial address by diving page table
    unsigned long physical_address = virt_to_phys(device_memory) + offset;
    unsigned long size = vma->vm_end - vma->vm_start;
    printk(KERN_INFO "Offset: %lu\n",offset);
    printk(KERN_INFO "physical address: %lu\n",physical_address);
    printk(KERN_INFO "size: %lu\n",size);

    if (size > DEVICE_MEMORY_SIZE) {
        return -EINVAL;
    }

    if (remap_pfn_range(vma, vma->vm_start, physical_address >> PAGE_SHIFT, size, vma->vm_page_prot)) {
        return -EAGAIN;
    }

    return 0;
}

static ssize_t my_device_read(struct file *filp, char __user *buffer, size_t length, loff_t *offset) {
    if (*offset >= DEVICE_MEMORY_SIZE)
        return 0;
    if (*offset + length > DEVICE_MEMORY_SIZE)
        length = DEVICE_MEMORY_SIZE - *offset;
    if (copy_to_user(buffer, device_memory + *offset, length))
        return -EFAULT;
    *offset += length;
    return length;
}

static ssize_t my_device_write(struct file *filp, const char __user *buffer, size_t length, loff_t *offset) {
    int numbers[2];
    ssize_t bytes_written = 0;

    if (length != sizeof(numbers)) {
        return -EINVAL;
    }

    if (copy_from_user(numbers, buffer, length)) {
        return -EFAULT;
    }

    *((int *)device_memory) = numbers[0] + numbers[1];

    *offset += sizeof(int);
    bytes_written = sizeof(int);
    return bytes_written;
}

static const struct file_operations my_device_fops = {
    .owner = THIS_MODULE,
    .open = my_device_open,
    .release = my_device_release,
    .mmap = my_device_mmap,
    .read = my_device_read,
    .write = my_device_write,
};

static int __init my_device_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &my_device_fops);
    if (major_number < 0) {
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
MODULE_DESCRIPTION("Example Device Driver with mmap and read/write");
