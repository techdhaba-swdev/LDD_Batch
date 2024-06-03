#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define LED_DEV_MAJOR 170
#define LED_DEV_MINOR 0

static dev_t led_dev;
static struct cdev led_cdev;
static spinlock_t led_lock;
static int led_state = 0;

static int led_open(struct inode *inode, struct file *filp) {
    return 0;
}

static int led_release(struct inode *inode, struct file *filp) {
    return 0;
}

static ssize_t led_write(struct file *filp, const char __user *user_buf, size_t count, loff_t *f_pos) {
    char value;

    if (count != sizeof(value))
        return -EINVAL;

    if (copy_from_user(&value, user_buf, count))
        return -EFAULT;

    spin_lock(&led_lock);
    led_state = (value == '1') ? 1 : 0;
    spin_unlock(&led_lock);

    printk(KERN_INFO "LED state: %d\n", led_state);
    return count;
}

static ssize_t led_read(struct file *filp, char __user *user_buf, size_t count, loff_t *f_pos) {
    char state = (led_state == 1) ? '1' : '0';

    if (count < sizeof(state))
        return -EINVAL;

    if (copy_to_user(user_buf, &state, sizeof(state)))
        return -EFAULT;

    return sizeof(state);
}

static struct file_operations led_fops = {
    .owner = THIS_MODULE,
    .open = led_open,
    .release = led_release,
    .read = led_read,
    .write = led_write,
};

static int __init led_driver_init(void) {
    int ret;

    ret = alloc_chrdev_region(&led_dev, LED_DEV_MINOR, 1, "led_dev");
    if (ret < 0)
        return ret;

    cdev_init(&led_cdev, &led_fops);

    ret = cdev_add(&led_cdev, led_dev, 1);
    if (ret < 0)
        goto free_dev;

    spin_lock_init(&led_lock);

    printk(KERN_INFO "LED driver initialized\n");
    return 0;

free_dev:
    unregister_chrdev_region(led_dev, 1);
    return ret;
}

static void __exit led_driver_exit(void) {
    cdev_del(&led_cdev);
    unregister_chrdev_region(led_dev, 1);
    printk(KERN_INFO "LED driver exited\n");
}

module_init(led_driver_init);
module_exit(led_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kiruthiga");
MODULE_DESCRIPTION("Virtual LED Driver");



