#include <linux/module.h>
#include<linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "my_device"
static char kernel_buffer[50]; // Define a static buffer in kernel space to store data

// Read function for device attribute
static ssize_t my_device_read(struct device *dev, struct device_attribute *attr,
                             char *user_buf, size_t count) {
  int ret;

  // Check if user space buffer is accessible for writing
  if (!access_ok(VERIFY_WRITE, user_buf, count)) {
    return -EFAULT; // User space buffer is invalid
  }

  // Copy data from kernel to user space (up to count bytes)
  ret = copy_to_user(user_buf, kernel_buffer, min(count, strlen(kernel_buffer)));

  if (ret) {
    return -EFAULT; // Error during copy
  }

  return strlen(kernel_buffer); // Return the size of data copied
}

// Write function for device attribute
static ssize_t my_device_write(struct device *dev, struct device_attribute *attr,
                              const char *user_buf, size_t count) {
  int ret;

  // Check if user space buffer is accessible for reading
  if (!access_ok(VERIFY_READ, user_buf, count)) {
    return -EFAULT; // User space buffer is invalid
  }

  // Copy data from user space to kernel (up to count bytes)
  ret = copy_from_user(kernel_buffer, user_buf, min(count, sizeof(kernel_buffer) - 1));

  if (ret) {
    return -EFAULT; // Error during copy
  }

  // Ensure the buffer is null-terminated
  kernel_buffer[ret] = '\0';

  return ret; // Return the size of data copied
}

static const struct device_attribute files[] = {
  __ATTR(data, S_IRUGO | S_IWUGO, my_device_read, my_device_write), // Define a device attribute named "data" with read and write permissions
};

// Device driver initialization function
static int __init my_device_init(void) {
    int ret;

    // Register a character device driver
    ret = register_chrdev(0, "my_device", &my_device_fops);
    if (ret < 0) {
        printk(KERN_ERR "Failed to register device driver\n");
        return ret;
    }

    // Create sysfs entries for the device attributes
    for (int i = 0; i < ARRAY_SIZE(files); i++) {
        ret = device_create_file(my_device_class, &files[i]);
        if (ret) {
            printk(KERN_ERR "Failed to create sysfs entry for device attribute\n");
            goto unregister;
        }
    }

    printk(KERN_INFO "Device driver registered\n");
    return 0;

unregister:
    // Unregister the character device driver if creation of sysfs entries fails
    unregister_chrdev(0, "my_device");
    return ret;
}

// Device driver exit function
static void __exit my_device_exit(void) {
    // Remove sysfs entries for the device attributes
    for (int i = 0; i < ARRAY_SIZE(files); i++) {
        device_remove_file(my_device_class, &files[i]);
    }

    // Unregister the character device driver
    unregister_chrdev(0, "my_device");
    printk(KERN_INFO "Device driver unregistered\n");
}

module_init(my_device_init); // Register device driver initialization function
module_exit(my_device_exit); // Register device driver exit function
MODULE_LICENSE("GPL"); // License of the module
MODULE_AUTHOR("Your Name"); // Author of the module
MODULE_DESCRIPTION("A simple device driver example"); // Description of the module
