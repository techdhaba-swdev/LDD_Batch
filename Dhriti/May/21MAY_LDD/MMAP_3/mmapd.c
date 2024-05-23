#include <linux/module.h>       // Core header for loading LKMs into the kernel
#include <linux/fs.h>           // Header for the Linux file system support
#include <linux/mm.h>           // Header for memory management functions
#include <linux/slab.h>         // Header for kernel memory allocation
#include <linux/uaccess.h>      // Header for user space and kernel space memory copying
#include <asm/io.h>
#define DEVICE_NAME "mmap_char_device" // Device name as it appears in /proc/devices
#define BUF_SIZE 4096                 // Size of the device buffer (4KB)

static int major;                    // Stores the major number assigned to our device
static char *kernel_buffer;          // Pointer to the buffer allocated in kernel memory

// Function called when the device is opened
static int device_open(struct inode *inode, struct file *file) {
    return 0;                        // Always succeed
}

// Function called when the device is closed
static int device_release(struct inode *inode, struct file *file) {
    return 0;                        // Always succeed
}

// Function called when the device is read from
static ssize_t device_read(struct file *filp, char __user *buffer, size_t length, loff_t *offset) {
    return simple_read_from_buffer(buffer, length, offset, kernel_buffer, BUF_SIZE); // Copy data from kernel buffer to user buffer
}

// Function called when the device is written to
static ssize_t device_write(struct file *filp, const char __user *buffer, size_t length, loff_t *offset) {
    return simple_write_to_buffer(kernel_buffer, BUF_SIZE, offset, buffer, length); // Copy data from user buffer to kernel buffer
}

// Function called to map the device memory to user space
static int device_mmap(struct file *filp, struct vm_area_struct *vma) {
    // Map the physical memory of kernel_buffer to user space
    return remap_pfn_range(vma, vma->vm_start, virt_to_phys(kernel_buffer) >> PAGE_SHIFT, BUF_SIZE, vma->vm_page_prot);
}

// Structure that holds pointers to the device functions
static const struct file_operations fops = {
    .owner = THIS_MODULE,           // Owner of the module
    .open = device_open,            // Open function
    .release = device_release,      // Release function
    .read = device_read,            // Read function
    .write = device_write,          // Write function
    .mmap = device_mmap,            // Mmap function
};

// Initialization function that is called when the module is loaded
static int __init device_init(void) {
    // Register the character device and get a dynamically assigned major number
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {                // If registration failed
        printk(KERN_ALERT "Registering char device failed with %d\n", major); // Print an alert message
        return major;               // Return the error code
    }

    // Allocate memory for the device buffer
    kernel_buffer = kmalloc(BUF_SIZE, GFP_KERNEL);
    if (!kernel_buffer) {           // If allocation failed
        unregister_chrdev(major, DEVICE_NAME); // Unregister the device
        return -ENOMEM;             // Return an out of memory error
    }

    // Print the major number assigned to the device
    printk(KERN_INFO "Registered a device with dynamic major number %d\n", major);
    return 0;                       // Initialization successful
}

// Cleanup function that is called when the module is unloaded
static void __exit device_exit(void) {
    kfree(kernel_buffer);           // Free the allocated buffer
    unregister_chrdev(major, DEVICE_NAME); // Unregister the device
    printk(KERN_INFO "Unregistered the device\n"); // Print a message
}

// Macro to indicate the initialization function
module_init(device_init);
// Macro to indicate the cleanup function
module_exit(device_exit);

// Metadata about the module
MODULE_LICENSE("GPL");              // License type
MODULE_AUTHOR("Your Name");         // Author name
MODULE_DESCRIPTION("A simple mmap character device driver"); // Description of the module
