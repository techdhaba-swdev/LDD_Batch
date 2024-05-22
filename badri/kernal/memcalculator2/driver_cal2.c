#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define DEVICE_NAME "my_device_cal2"
#define DEVICE_MEMORY_SIZE 4096  // 4KB

static char *device_memory;
static int major_number;
static int results[10] = {0}; // Store the results of the calculations
static int current_operation = 0; // Index to track the current operation being processed

static int my_device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "my_device: open\n");
    return 0;
}

static int my_device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "my_device: release\n");
    return 0;
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

    return 0;
}

// Handle the calculation request from user space
static ssize_t my_device_write(struct file *file, const char __user *buffer, size_t count, loff_t *ppos) {
    char input_buffer[20]; // Buffer to store the input from user space
    if (count > sizeof(input_buffer)) {
        return -EINVAL;
    }

    if (copy_from_user(input_buffer, buffer, count)) {
        return -EFAULT;
    }

    // Parse input string to extract numbers
    int num1, num2;
    if (sscanf(input_buffer, "%d+%d", &num1, &num2) != 2) {
        return -EINVAL;
    }

    // Perform the addition and store the result
    if (current_operation < 10) {
        results[current_operation++] = num1 + num2;
    }

    return count;
}

static ssize_t my_device_read(struct file *file, char __user *buffer, size_t count, loff_t *ppos) {
    char result_buffer[20]; // Buffer to store the result
    int length;

    if (current_operation == 0) {
        // No operations performed yet
        return 0;
    }

    if (*ppos >= current_operation) {
        // All operations have been read
        current_operation = 0;
        return 0;
    }

    // Convert result to string
    length = snprintf(result_buffer, sizeof(result_buffer), "%d", results[*ppos]);
    
    // Copy result to user space
    if (copy_to_user(buffer, result_buffer, length)) {
        return -EFAULT;
    }

    // Move file position to next operation
    *ppos += 1;

    return length;
}

static const struct file_operations my_device_fops = {
    .owner = THIS_MODULE,
    .open = my_device_open,
    .release = my_device_release,
    .mmap = my_device_mmap,
    .write = my_device_write,
    .read = my_device_read,
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
MODULE_DESCRIPTION("Example Device Driver with mmap and calculation");
