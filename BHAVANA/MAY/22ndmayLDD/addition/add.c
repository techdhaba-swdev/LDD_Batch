#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define DEVICE_NAME "my_device_addition"
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

static ssize_t my_device_write(struct file *file, const char __user *buffer, size_t len, loff_t *ppos) {
    int numbers[10];
    int result = 0;

    // Check if the length of the input buffer is sufficient
    if (len < sizeof(numbers)) {
        return -EINVAL;
    }

    // Copy the user input from the user space buffer to kernel space device memory
    if (copy_from_user(device_memory, buffer, len)) {
        return -EFAULT;
    }

    // Copy the input numbers from device memory to the numbers array
    memcpy(numbers, device_memory, sizeof(numbers));

    // Calculate the sum of the 10 numbers
    for (int i = 0; i < 10; i++) {
        result += numbers[i];
    }

    // Store the result back in device memory
    memcpy(device_memory, &result, sizeof(int));
    printk(KERN_INFO "Processed result: %d\n", result);

    return len;
}

static ssize_t my_device_read(struct file *file, char __user *buffer, size_t len, loff_t *ppos) {
    // Copy the result from the kernel space device memory to the user space buffer
    if (copy_to_user(buffer, device_memory, sizeof(int))) {
        return -EFAULT;
    }
    return sizeof(int);
}

static const struct file_operations my_device_fops = {
    .owner = THIS_MODULE,
    .open = my_device_open,
    .release = my_device_release,
    .write = my_device_write,
    .read = my_device_read,
};

static int __init my_device_init(void) {
    // Register the character device and allocate memory for device operations
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
    // Free allocated memory and unregister the character device
    kfree(device_memory);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "my_device: unregistered\n");
}

module_init(my_device_init);
module_exit(my_device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BHAVANA");
MODULE_DESCRIPTION("Example Device Driver for Adding 10 Numbers");
