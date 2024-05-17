#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/spinlock.h>
#include <linux/slab.h> // for kmalloc and kfree
#include <pthread.h>

#define DEVICE_NAME "data_transfer"
#define DATA_SIZE sizeof(struct user_data)

struct user_data {
    int value;
    char message[20];
};

static dev_t dev_num;
static struct cdev my_cdev;
static spinlock_t my_lock;

// Global variable to hold received data
static struct user_data global_data;

// pthread variables
static pthread_t thread;
static int thread_running = 0;

static int my_open(struct inode *inode, struct file *filp) {
    pr_info("Device opened\n");
    return 0;
}

static int my_release(struct inode *inode, struct file *filp) {
    pr_info("Device closed\n");
    return 0;
}

static ssize_t my_write(struct file *filp, const char __user *user_buf,
                       size_t count, loff_t *f_pos) {
    struct user_data data;
    unsigned long flags;

    // Ensure data size matches expected structure
    if (count != DATA_SIZE) {
        pr_err("Invalid data size: %zu, expected %zu\n", count, DATA_SIZE);
        return -EINVAL;
    }

    // Acquire spinlock to protect critical section
    spin_lock_irqsave(&my_lock, flags);

    // Check if user provided a valid buffer
    if (copy_from_user(&data, user_buf, count)) {
        spin_unlock_irqrestore(&my_lock, flags);
        pr_err("Error copying data from user\n");
        return -EFAULT;
    }

    // Process data from user space (replace with your actual logic)
    pr_info("Received data: value = %d, message = %s\n", data.value, data.message);

    // Store data globally
    global_data = data;

    // Release spinlock after critical section
    spin_unlock_irqrestore(&my_lock, flags);

    return count;
}

static ssize_t my_read(struct file *filp, char __user *user_buf,
                      size_t count, loff_t *f_pos) {
    unsigned long flags;

    // Acquire spinlock to protect critical section
    spin_lock_irqsave(&my_lock, flags);

    // Check if user provided a valid buffer
    if (copy_to_user(user_buf, &global_data, DATA_SIZE)) {
        spin_unlock_irqrestore(&my_lock, flags);
        pr_err("Error copying data to user\n");
        return -EFAULT;
    }

    // Release spinlock after critical section
    spin_unlock_irqrestore(&my_lock, flags);

    return DATA_SIZE;
}

static void *thread_function(void *data) {
    while (thread_running) {
        // Your thread logic here
        // For example, continuously processing data from global_data
        // pr_info("Thread running...\n");

        // Add your logic here
        
        // Sleep for some time to avoid busy-waiting
        msleep(1000); // Sleep for 1 second
    }
    return NULL;
}

static const struct file_operations my_fops = {
    .owner = THIS_MODULE,
    .open = my_open,
    .release = my_release,
    .write = my_write,
    .read = my_read,
};

static int __init data_transfer_init(void) {
    int ret;

    // Allocate a dynamic major number for the character device
    ret = alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
    if (ret < 0) {
        pr_err("Failed to allocate character device region\n");
        return ret;
    }

    // Initialize the spinlock
    spin_lock_init(&my_lock);

    // Initialize the cdev structure
    cdev_init(&my_cdev, &my_fops);

    // Add the character device to the kernel
    ret = cdev_add(&my_cdev, dev_num, 1);
    if (ret < 0) {
        goto free_chrdev;
    }

    // Create and start the pthread
    thread_running = 1;
    ret = pthread_create(&thread, NULL, thread_function, NULL);
    if (ret) {
        pr_err("Failed to create thread\n");
        goto remove_cdev;
    }

    pr_info("Device %s created with major number: %u\n", DEVICE_NAME, MAJOR(dev_num));
    return 0;

remove_cdev:
    cdev_del(&my_cdev);
free_chrdev:
    unregister_chrdev_region(dev_num, 1);
    return ret;
}

static void __exit data_transfer_exit(void) {
    // Stop the pthread
    thread_running = 0;
    pthread_join(thread, NULL);

    cdev_del(&my_cdev);
    unregister_chrdev_region(dev_num, 1);
    pr_info("Device %s removed\n", DEVICE_NAME);
}

module_init(data_transfer_init);
module_exit(data_transfer_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Character device for data transfer with spinlock and pthread");
