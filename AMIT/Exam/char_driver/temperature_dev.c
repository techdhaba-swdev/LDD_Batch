#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/random.h>
#include <asm/uaccess.h>

#define DEVICE_NAME "virtual_temp"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("A");
MODULE_DESCRIPTION("Virtual Temperature Sensor Driver");

static int major_number;

// Generate a random temperature value (0 to 100)
static int get_random_temperature(void) {
	unsigned int temp;
	get_random_bytes(&temp,sizeof(temp));
    return temp % 101;
}


static ssize_t virtual_temp_read(struct file *file, char __user *buf, size_t len, loff_t *offset)
{
    int temperature = get_random_temperature();
    char temp_str[10];
    snprintf(temp_str, sizeof(temp_str), "%d\n", temperature);

    if (copy_to_user(buf, temp_str, strlen(temp_str)))
        return -EFAULT;

    return strlen(temp_str);
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read = virtual_temp_read,
};

static int __init virtual_temp_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Virtual temperature sensor loaded with major number %d\n", major_number);
    return 0;
}

static void __exit virtual_temp_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Virtual temperature sensor unloaded\n");
}

module_init(virtual_temp_init);
module_exit(virtual_temp_exit);


