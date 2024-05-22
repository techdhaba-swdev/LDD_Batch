#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include<linux/io.h>
#include<linux/device.h> 

#define DEVICE_NAME "mmap_char_device"
#define BUF_SIZE 4096
#define NUM_EXPRESSIONS 10

static int major;
static char *kernel_buffer;

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char __user *buffer, size_t length, loff_t *offset) {
    return simple_read_from_buffer(buffer, length, offset, kernel_buffer, BUF_SIZE);
}

static ssize_t device_write(struct file *filp, const char __user *buffer, size_t length, loff_t *offset) {
    ssize_t written = simple_write_to_buffer(kernel_buffer, BUF_SIZE, offset, buffer, length);
    if (written > 0) {
        printk(KERN_INFO "Kernel received from user: %s\n", kernel_buffer);

        // Parse the expressions (e.g., "1+2;3-4;...")
        int results[NUM_EXPRESSIONS];
        char *expression;
        char *saveptr;
        int i = 0;
        char *buffer_copy = kstrdup(kernel_buffer, GFP_KERNEL); // Make a copy to avoid modifying the original buffer
        if (!buffer_copy) {
            return -ENOMEM;
        }
        expression = buffer_copy;
        while ((expression = strsep(&buffer_copy, ";")) != NULL && i < NUM_EXPRESSIONS) {
            // Parse the expression and operation (e.g., "1+2")
            int num1, num2, result;
            char op;
            sscanf(expression, "%d%c%d", &num1, &op, &num2);

            // Perform the operation
            switch(op) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2; // Assuming num2 is not zero
                    break;
                default:
                    result = 0; // Invalid operation
            }

            results[i] = result;

            i++;
        }
        kfree(buffer_copy);

        // Convert the results back to a string
        char result_string[BUF_SIZE];
        result_string[0] = '\0'; // Ensure the string is initially empty
        for (int j = 0; j < NUM_EXPRESSIONS; j++) {
            char temp[20]; // Assuming each result can be represented in less than 20 characters
            snprintf(temp, sizeof(temp), "%d", results[j]);
            strcat(result_string, temp);
            if (j != NUM_EXPRESSIONS - 1) {
                strcat(result_string, ";"); // Delimiter between results
            }
        }

        // Copy the result string back to the kernel buffer
        strncpy(kernel_buffer, result_string, BUF_SIZE);
    }
    return written;
}

static int device_mmap(struct file *filp, struct vm_area_struct *vma) {
    return remap_pfn_range(vma, vma->vm_start, virt_to_phys(kernel_buffer) >> PAGE_SHIFT, BUF_SIZE, vma->vm_page_prot);
}

static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
    .mmap = device_mmap,
};

static int __init device_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }

    kernel_buffer = kmalloc(BUF_SIZE, GFP_KERNEL);
    if (!kernel_buffer) {
        unregister_chrdev(major, DEVICE_NAME);
        return -ENOMEM;
    }

    printk(KERN_INFO "Registered a device with dynamic major number %d\n", major);
    return 0;
}

static void __exit device_exit(void) {
    kfree(kernel_buffer);
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Unregistered the device\n");
}

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple mmap character device driver with multiple arithmetic expressions support");



