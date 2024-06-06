// timer_module.c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/uaccess.h>
#include <linux/fs.h>

#define DEVICE_NAME "timer_device"
#define TIMER_INTERVAL_SEC 5 //setting timer for 5 seconds

static struct timer_list my_timer;
static int major_number;
static int is_open = 0;

static void timer_callback(struct timer_list *timer) { //this funct is called when time expire... it prints message and reschedules the timer
    pr_info("Timer expired and callback executed!\n");
    mod_timer(&my_timer, jiffies + TIMER_INTERVAL_SEC * HZ); //rescheduling the timer to perform at specfic time after 5 sec
}

static int device_open(struct inode *inode, struct file *file) {
    if (is_open)
        return -EBUSY;
    is_open++; //increasing isopen to say the device in use
    try_module_get(THIS_MODULE); //preventing it from unloading while open
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    is_open--; //decreasing to say the device is no longer in use
    module_put(THIS_MODULE);
    return 0;
}

static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
};

static int __init timer_module_init(void) {
    pr_info("Initializing timer module\n");

    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        pr_alert("Registering char device failed with %d\n", major_number);
        return major_number;
    }

    timer_setup(&my_timer, timer_callback, 0); //setting up the my timer with timer callback
    mod_timer(&my_timer, jiffies + TIMER_INTERVAL_SEC * HZ); //setting up the timer to fire for firsttime after TIME INTERVLA SEC jiffies(i.e 5)

    pr_info("Timer module loaded with device major number %d\n", major_number);
    return 0;
}

static void __exit timer_module_exit(void) {
    pr_info("Exiting timer module\n");
    del_timer(&my_timer); //cancelling pending timer events for my_timer
    unregister_chrdev(major_number, DEVICE_NAME);
    pr_info("Timer module unloaded\n");
}

module_init(timer_module_init);
module_exit(timer_module_exit);

MODULE_LICENSE("GPL");

MODULE_AUTHOR("MS");
MODULE_DESCRIPTION("A simple Linux driver with a kernel timer");
