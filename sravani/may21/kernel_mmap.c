#include <linux/module.h>   // Header file for Linux kernel modules
#include <linux/fs.h>       // Header file for file system operations
#include <linux/mm.h>       // Header file for memory management operations
#include <linux/io.h>       // Header file for I/O operations
#include <linux/uaccess.h>  // Header file for user-space access
#include <linux/slab.h>     // Header file for dynamic memory allocation

#define DEVICE_NAME "mmap_device"        // Name of the device
#define DEVICE_MEMORY_SIZE 4096        // Size of the device's memory region (4KB)

static char *device_memory;            // Pointer to the allocated device memory
static int major_number;               // Major number assigned to the device

//function to perform add operation
static void addition_on_memory(char *addr,size_t size) {
	for(size_t i=0; i<size;i++) {
		addr[i] += 5;
	}
}
// Function called when the device file is opened
static int my_device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "my_device: open\n");  // opening of the device
    return 0;
}

// Function called when the device file is closed
static int my_device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "my_device: release\n");  // release of the device
    return 0;
}

// Function called when a process tries to memory map the device file
static int my_device_mmap(struct file *filp, struct vm_area_struct *vma) {
    unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;  // Calculate the offset
    unsigned long physical_address = virt_to_phys(device_memory) + offset;  // Calculate physical address
    unsigned long size = vma->vm_end - vma->vm_start;  // Calculate the size

    // Check if the size exceeds the device memory size
    if (size > DEVICE_MEMORY_SIZE) {
        return -EINVAL;  // Return error if size is invalid
    }

    // Map the memory region into the process's address space
    if (remap_pfn_range(vma, vma->vm_start, physical_address >> PAGE_SHIFT, size, vma->vm_page_prot)) {
        return -EAGAIN;  // Return error if mapping fails
    }

    addition_on_memory(device_memory, size);

    return 0;  // Return success
}

// File operations structure defining operations on the device file
static const struct file_operations my_device_fops = {
    .owner = THIS_MODULE,               // Owner of the file operations
    .open = my_device_open,             // Function to open the device file
    .release = my_device_release,       // Function to release the device file
    .mmap = my_device_mmap              // Function to memory map the device file
};

// Module initialization function
static int __init my_device_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &my_device_fops);  // Register the character device
    if (major_number < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number);  // Log registration failure
        return major_number;  // Return error code
    }

    device_memory = kmalloc(DEVICE_MEMORY_SIZE, GFP_KERNEL);  // Allocate memory for the device
    if (!device_memory) {
        unregister_chrdev(major_number, DEVICE_NAME);  // Unregister the character device
        return -ENOMEM;  // Return out-of-memory error
    }

    printk(KERN_INFO "my_device: registered with major number %d\n", major_number);  // Log registration success
    printk(KERN_INFO "my_device: memory allocated at %p\n", device_memory);  // Log memory allocation
    return 0;  // Return success
}

// Module exit function
static void __exit my_device_exit(void) {
    kfree(device_memory);  // Free allocated memory for the device
    unregister_chrdev(major_number, DEVICE_NAME);  // Unregister the character device
    printk(KERN_INFO "my_device: unregistered\n");  // Log unregistering
}

module_init(my_device_init);  // Specify the module initialization function
module_exit(my_device_exit);  // Specify the module exit function

MODULE_LICENSE("GPL");          // Specify the license for the module
