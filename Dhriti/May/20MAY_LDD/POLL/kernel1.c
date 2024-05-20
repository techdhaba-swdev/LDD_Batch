#include <linux/module.h> // Kernel module functions and macros
#include <linux/fs.h> // File system operations
#include <linux/poll.h> // Polling support
#include <linux/uaccess.h> // User-space memory access functions
#include <linux/slab.h> // Memory allocation functions

#define DEVICE_NAME "example_char_device" // Name of the device file
#define BUF_LEN 80 // Buffer length for data storage

static int major; // Major number assigned to the device
static char *device_buffer; // Buffer to store data
static int buffer_pointer = 0; // Pointer to current position in buffer
static wait_queue_head_t queue; // Wait queue for sleeping processes
static int is_open = 0; // Flag to track device open status

// Open function called when the device file is opened
static int device_open(struct inode *inode, struct file *file) {
    if (is_open) return -EBUSY; // Return error if device is already open
    is_open++;
    try_module_get(THIS_MODULE); // Increment module reference count
    return 0;
}

// Release function called when the device file is closed
static int device_release(struct inode *inode, struct file *file) {
    is_open--;
    module_put(THIS_MODULE); // Decrement module reference count
    return 0;
}

// Read function to read data from the device
static ssize_t device_read(struct file *file, char __user *buffer, size_t length, loff_t *offset) {
    int bytes_read = 0;

    if (*offset >= BUF_LEN) return 0; // Return if offset exceeds buffer length
    if (*offset + length > BUF_LEN) length = BUF_LEN - *offset; // Adjust length if exceeds buffer length

    if (copy_to_user(buffer, device_buffer + *offset, length)) return -EFAULT; // Copy data to user space

    *offset += length;
    bytes_read = length;

    return bytes_read;
}

// Write function to write data to the device
static ssize_t device_write(struct file *file, const char __user *buffer, size_t length, loff_t *offset) {
    if (*offset >= BUF_LEN) return 0; // Return if offset exceeds buffer length
    if (*offset + length > BUF_LEN) length = BUF_LEN - *offset; // Adjust length if exceeds buffer length

    if (copy_from_user(device_buffer + *offset, buffer, length)) return -EFAULT; // Copy data from user space

    *offset += length;
    buffer_pointer += length;

    wake_up_interruptible(&queue); // Wake up any sleeping processes waiting for data

    return length;
}

// Poll function to check device status for read and write operations
static unsigned int device_poll(struct file *file, poll_table *wait) {
    unsigned int mask = 0;

    poll_wait(file, &queue, wait); // Add current process to the wait queue

    if (buffer_pointer > 0) mask |= POLLIN | POLLRDNORM; // Set mask if data is available to read
    if (buffer_pointer < BUF_LEN) mask |= POLLOUT | POLLWRNORM; // Set mask if space is available to write

    return mask;
}

// Define file operations structure
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
    .poll = device_poll,
};

// Initialization function called when the module is loaded
static int __init device_init(void) {
    // Register the character device
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }

    // Allocate memory for the device buffer
    device_buffer = kmalloc(BUF_LEN, GFP_KERNEL);
    if (!device_buffer) {
        unregister_chrdev(major, DEVICE_NAME);
        return -ENOMEM;
    }

    // Initialize the wait queue
    init_waitqueue_head(&queue);

    // Print information about the registered device
    printk(KERN_INFO "I was assigned major number %d. To talk to\n", major);
    printk(KERN_INFO "the driver, create a dev file with\n");
    printk(KERN_INFO "'mknod /dev/%s c %d 0'.\n", DEVICE_NAME, major);
    return 0;
}

// Cleanup function called when the module is unloaded
static void __exit device_exit(void) {
    // Free allocated memory and unregister the character device
    kfree(device_buffer);
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Device unregistered\n");
}

// Specify initialization and cleanup functions
module_init(device_init);
module_exit(device_exit);

// Module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("techdhaba");
MODULE_DESCRIPTION("A simple example character device driver");


