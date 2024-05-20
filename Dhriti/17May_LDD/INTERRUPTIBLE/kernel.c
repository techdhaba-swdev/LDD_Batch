#include <linux/init.h> // Needed for module initialization macros
#include <linux/module.h> // Needed by all modules
#include <linux/fs.h> // Needed for file operations
#include <linux/uaccess.h> // Needed for copy_to_user and copy_from_user
#include <linux/cdev.h> // Needed for character device structure
#include <linux/wait.h> // Needed for wait queues
#include <linux/sched.h> // Needed for task states (TASK_INTERRUPTIBLE)
#include <linux/mutex.h> // Needed for mutexes

#define DEVICE_NAME "my_ioctl_device" // The device will appear as /dev/my_ioctl_device
#define IOCTL_MAGIC 'k' // Magic number for ioctl commands
#define IOCTL_CMD _IOW(IOCTL_MAGIC, 1, int) // Ioctl command definition

static int major_number; // Major number for the device
static struct cdev my_cdev; // Character device structure
static wait_queue_head_t my_queue; // Wait queue for blocking I/O
static int flag = 0; // Flag for synchronization
static DEFINE_MUTEX(my_mutex); // Mutex for protecting the flag

// Called when a process opens the device file
static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0; // Success
}

// Called when a process closes the device file
static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0; // Success
}

// Called when a process reads from the device file
static ssize_t device_read(struct file *file, char __user *buffer, size_t len, loff_t *offset) {
    int ret;

    // Wait for the flag to be set
    wait_event_interruptible(my_queue, flag != 0);
    
    // Acquire the mutex to safely read and reset the flag
    mutex_lock(&my_mutex);
    flag = 0; // Reset the flag
    mutex_unlock(&my_mutex);

    // Copy the flag value to user space
    ret = copy_to_user(buffer, &flag, sizeof(flag));
    if (ret) {
        return -EFAULT; // Return error if copy_to_user fails
    }

    printk(KERN_INFO "Data read from device\n");
    return sizeof(flag); // Return the number of bytes read
}

// Called when a process writes to the device file
static ssize_t device_write(struct file *file, const char __user *buffer, size_t len, loff_t *offset) {
    int value;
    int ret = copy_from_user(&value, buffer, sizeof(value));
    if (ret) {
        return -EFAULT; // Return error if copy_from_user fails
    }

    // Acquire the mutex to safely set the flag
    mutex_lock(&my_mutex);
    flag = value;
    mutex_unlock(&my_mutex);

    // Wake up any process waiting on the wait queue
    wake_up_interruptible(&my_queue);

    printk(KERN_INFO "Data written to device\n");
    return sizeof(value); // Return the number of bytes written
}

// Called when a process performs an ioctl on the device file
static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    int value;

    switch (cmd) {
        case IOCTL_CMD:
            // Copy the value from user space
            if (copy_from_user(&value, (int __user *)arg, sizeof(value))) {
                return -EFAULT; // Return error if copy_from_user fails
            }
            printk(KERN_INFO "IOCTL received: %d\n", value);
            break;
        default:
            return -ENOTTY; // Return error for unsupported ioctl commands
    }
    return 0; // Success
}

// File operations structure
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
    .unlocked_ioctl = device_ioctl,
};

// Module initialization function
static int __init my_ioctl_init(void) {
    // Register the character device with a dynamic major number
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number);
        return major_number;
    }

    // Initialize the character device structure
    cdev_init(&my_cdev, &fops);
    my_cdev.owner = THIS_MODULE;

    // Add the character device to the system
    if (cdev_add(&my_cdev, MKDEV(major_number, 0), 1)) {
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ALERT "Adding cdev failed\n");
        return -1;
    }

    // Initialize the wait queue
    init_waitqueue_head(&my_queue);

    printk(KERN_INFO "Device registered with major number %d\n", major_number);
    return 0; // Success
}

// Module cleanup function
static void __exit my_ioctl_exit(void) {
    // Remove the character device from the system
    cdev_del(&my_cdev);

    // Unregister the character device
    unregister_chrdev(major_number, DEVICE_NAME);

    printk(KERN_INFO "Device unregistered\n");
}

module_init(my_ioctl_init); // Register module initialization function
module_exit(my_ioctl_exit); // Register module cleanup function

MODULE_LICENSE("GPL"); // Specify the license
MODULE_AUTHOR("TECHDHABA"); // Specify the author
MODULE_DESCRIPTION("A simple Linux char driver with ioctl and blocking I/O"); // Description of the module
MODULE_VERSION("0.1"); // Version of the module
