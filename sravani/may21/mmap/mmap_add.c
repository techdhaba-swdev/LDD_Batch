#include <linux/module.h>      // Include the necessary header files
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define DEVICE_NAME "my_device"    // Define constants for device name and memory size
#define DEVICE_MEMORY_SIZE 4096  // 4KB

static char *device_memory;    // Declare a pointer to hold device memory
static int major_number;    // Declare a variable to hold the major number

static int my_device_open(struct inode *inode, struct file *file) {    // Define function for opening the device
    printk(KERN_INFO "my_device: open\n");    // Print message indicating the device is opened
    return 0;    // Return success
}

static int my_device_release(struct inode *inode, struct file *file) {    // Define function for releasing the device
    printk(KERN_INFO "my_device: release\n");    // Print message indicating the device is released
    return 0;    // Return success
}

static ssize_t my_device_write(struct file *file, const char __user *buffer, size_t len, loff_t *ppos) {    // Define function for writing to the device
    int num1, num2, result;    // Declare variables for storing numbers and result
    char operation;    // Declare variable for storing operation

    if (len < sizeof(int) * 2 + sizeof(char)) {    // Check if the length of the data is valid
        return -EINVAL;    // Return error if invalid
    }

    if (copy_from_user(device_memory, buffer, len)) {    // Copy data from user space to kernel space
        return -EFAULT;    // Return error if copying fails
    }

    memcpy(&num1, device_memory, sizeof(int));    // Copy first number from device memory
    memcpy(&num2, device_memory + sizeof(int), sizeof(int));    // Copy second number from device memory
    memcpy(&operation, device_memory + sizeof(int) * 2, sizeof(char));    // Copy operation from device memory

    printk(KERN_INFO "Received operation: %c, num1: %d, num2: %d\n", operation, num1, num2);    // Print received operation and numbers

    if (operation == '+') {    // Check the operation
        result = num1 + num2;    // Perform addition
    } else if (operation == '-') {
        result = num1 - num2;    // Perform subtraction
    } else {
        return -EINVAL;    // Return error for invalid operation
    }

    memcpy(device_memory, &result, sizeof(int));    // Copy result to device memory
    printk(KERN_INFO "Processed result: %d\n", result);    // Print processed result

    return len;    // Return the length of the data
}

static int my_device_mmap(struct file *filp, struct vm_area_struct *vma) {    // Define function for memory mapping
    unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;    // Calculate offset
    unsigned long physical_address = virt_to_phys(device_memory) + offset;    // Calculate physical address
    unsigned long size = vma->vm_end - vma->vm_start;    // Calculate size

    if (size > DEVICE_MEMORY_SIZE) {    // Check if size is valid
        return -EINVAL;    // Return error if invalid
    }

    if (remap_pfn_range(vma, vma->vm_start, physical_address >> PAGE_SHIFT, size, vma->vm_page_prot)) {    // Map memory to user space
        return -EAGAIN;    // Return error if mapping fails
    }

    return 0;    // Return success
}

static const struct file_operations my_device_fops = {    // Define file operations structure
    .owner = THIS_MODULE,    // Set owner
    .open = my_device_open,    // Set open function
    .release = my_device_release,    // Set release function
    .write = my_device_write,    // Set write function
    .mmap = my_device_mmap,    // Set mmap function
};

static int __init my_device_init(void) {    // Define initialization function
    major_number = register_chrdev(0, DEVICE_NAME, &my_device_fops);    // Register character device
    if (major_number < 0) {    // Check if registration fails
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number);    // Print error message
        return major_number;    // Return error code
    }

    device_memory = kmalloc(DEVICE_MEMORY_SIZE, GFP_KERNEL);    // Allocate memory for device
    if (!device_memory) {    // Check if allocation fails
        unregister_chrdev(major_number, DEVICE_NAME);    // Unregister character device
        return -ENOMEM;    // Return out-of-memory error
    }

    printk(KERN_INFO "my_device: registered with major number %d\n", major_number);    // Print registration message
    printk(KERN_INFO "my_device: memory allocated at %p\n", device_memory);    // Print memory allocation message
    return 0;    // Return success
}

static void __exit my_device_exit(void) {    // Define exit function
    kfree(device_memory);    // Free allocated memory
    unregister_chrdev(major_number, DEVICE_NAME);    // Unregister character device
    printk(KERN_INFO "my_device: unregistered\n");    // Print unregistration message
}

module_init(my_device_init);    // Specify initialization function
module_exit(my_device_exit);    // Specify exit function

MODULE_LICENSE("GPL");    // Specify module license
MODULE_AUTHOR("Your Name");    // Specify module author
MODULE_DESCRIPTION("Example Device Driver with mmap");    // Specify module description

