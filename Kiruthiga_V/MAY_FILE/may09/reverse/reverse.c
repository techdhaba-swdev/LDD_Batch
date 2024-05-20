#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "reverse"
#define BUFFER_SIZE 100

static int major_number;
static char input_buffer[BUFFER_SIZE];
static char output_buffer[BUFFER_SIZE];
static int buffer_position;

static int reverse_string_dev_open(struct inode *inode, struct file *file) {
    buffer_position = 0;
    return 0;
}

static int reverse_string_dev_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t reverse_string_dev_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos) {
    int bytes_written;

    // Check if the buffer is large enough to hold the input string
    if (count > BUFFER_SIZE - buffer_position) {
        return -ENOMEM;
    }

    // Use copy_from_user to safely copy data from user space
    bytes_written = copy_from_user(input_buffer + buffer_position, buf, count);
    if (bytes_written < 0) {
        return -EFAULT;
    }

    // Reverse the input string and store it in the output buffer
    int i, j;
    for (i = 0, j = count - 1; i < count; i++, j--) {
        output_buffer[i] = input_buffer[j];
        output_buffer[j] = input_buffer[i];
    }

    // Write the reversed string to user space
    bytes_written = copy_to_user(buf, output_buffer, count);
    if (bytes_written < 0) {
        return -EFAULT;
    }

    buffer_position += count;
    return count;
}

static ssize_t reverse_string_dev_read(struct file *file, char __user *buf, size_t count, loff_t *ppos) {
    int bytes_read;

    // Check if there is any data to read
    if (buffer_position == 0) {
        return 0;
    }

    // Use copy_to_user to safely copy data to user space
    bytes_read = copy_to_user(buf, input_buffer, buffer_position);
    if (bytes_read < 0) {
        return -EFAULT;
    }

    buffer_position = 0;
    return buffer_position;
}

static struct file_operations reverse_string_dev_fops = {
   .open = reverse_string_dev_open,
   .release = reverse_string_dev_release,
   .write = reverse_string_dev_write,
   .read = reverse_string_dev_read,
};

static int __init reverse_string_dev_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &reverse_string_dev_fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Reverse string device registered, major number: %d\n", major_number);
    return 0;
}

static void __exit reverse_string_dev_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Reverse string device unregistered\n");
}

module_init(reverse_string_dev_init);
module_exit(reverse_string_dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("your name");
MODULE_DESCRIPTION("Simple reverse string device driver");


