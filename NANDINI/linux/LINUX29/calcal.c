#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/mm.h>
#include<linux/slab.h>
#include<linux/uaccess.h>
#include<linux/types.h>
#include<linux/io.h>
#include<linux/device.h>
#define DEVICE_NAME "mmap_char_device"
#define BUF_SIZE 4096
#define NUM 10

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
        //1.pointer to dest buffer 2.max length to cp 3,offset 4.srcbuffer 5.size available in kernel buffer
    return simple_read_from_buffer(buffer, length, offset, kernel_buffer, BUF_SIZE); //copying data from kernelbuffer  to user buffer
}

static ssize_t device_write(struct file *filp, const char __user *buffer, size_t length, loff_t *offset) {
        //1.pointer to dest 2.size available  3.offset 4.pointer to src buffer 4.max length to cp
    ssize_t written = simple_write_to_buffer(kernel_buffer, BUF_SIZE, offset, buffer, length); //copying data from userbuffer to kernelbuffer
    if (written > 0) {
        printk(KERN_INFO "Kernel received from user: %s\n", kernel_buffer);

        // Parsing the expressions (e.g., "1+2;3-4;...")
        int results[NUM];
        char *expression;
        char *saveptr;
        int i = 0;
        char *buffer_copy = kstrdup(kernel_buffer, GFP_KERNEL); // Making a duplicate copy to avoid modifying the original buffer
        if (!buffer_copy) {
            return -ENOMEM;
        }
        expression = buffer_copy; //storing buffer_copy pointer in expression pointer
        while ((expression = strsep(&buffer_copy, ";")) != NULL && i < NUM) { //separating the string using strsep inbuilt api
            // Parsing the expression and operation (e.g., "1+2")
            int num1, num2, result;
            char op;
            sscanf(expression, "%d%c%d", &num1, &op, &num2); //scanning string using sscanf
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
                    result = num1 / num2;
                    break;
                default:
                    result = 0;
            }

            results[i] = result;
            i++;
        }
        kfree(buffer_copy);

        // Converting the results back to a string
        char result_string[BUF_SIZE];
        result_string[0] = '\0'; // making the string empty initially
        for (int j = 0; j < NUM; j++) {
            char temp[20]; // Assuming each result can be represented in less than 20 characters
            snprintf(temp, sizeof(temp), "%d", results[j]);//printf prints to screen but snprintf prints to required destination
            strcat(result_string, temp); //concatinating two strings 1st is dest and 2nd is src
            if (j != NUM - 1) {
                strcat(result_string, ";"); // Delimiter between results
            }
        }

        // Copying the result string back to the kernel buffer
        strncpy(kernel_buffer, result_string, BUF_SIZE);
    }
    return written;
}

static int device_mmap(struct file *filp, struct vm_area_struct *vma) {
        //memory remapping...1.pointer to vm_area_struct 2.mapping physical add to virtual add 3.size of mem region 4.protection flags that defines permissions(read,write,execute) for mapped memory
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
//init system call api
static int __init network_device_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops); //regstering the device
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }

    kernel_buffer = kmalloc(BUF_SIZE, GFP_KERNEL); //allocated memory dynamically using kmalloc
    if (!kernel_buffer) {
        unregister_chrdev(major, DEVICE_NAME);
        return -ENOMEM;
    }

    printk(KERN_INFO "Registered a device with dynamic major number %d\n", major);
    return 0;
}
//exit system call api
static void __exit network_device_exit(void) {
    kfree(kernel_buffer); //freeing up the memory which i allocated
    unregister_chrdev(major, DEVICE_NAME); //unregistering the device
    printk(KERN_INFO "Unregistered the device\n");
}

module_init(network_device_init);
module_exit(network_device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NANDINI");
MODULE_DESCRIPTION("A simple mmap character device driver with multiple arithmetic expressions support");
