#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>

static struct task_struct *odd_thread;

// Function to print odd numbers
static int print_odd(void *data) {
    int i = 1;
    while (!kthread_should_stop()) {
        printk(KERN_INFO "Odd number: %d\n", i);
        i += 2; // Increment by 2 to get the next odd number
        msleep(1000); // Sleep for 1 second
    }
    return 0;
}

static int __init odd_thread_init(void) {
    printk(KERN_INFO "Initializing odd number printing thread\n");

    // Create the kernel thread
    odd_thread = kthread_run(print_odd, NULL, "odd_thread");
    if (IS_ERR(odd_thread)) {
        printk(KERN_ERR "Failed to create odd number printing thread\n");
        return PTR_ERR(odd_thread);
    }

    return 0;
}

static void __exit odd_thread_exit(void) {
    printk(KERN_INFO "Stopping odd number printing thread\n");

    // Stop the kernel thread
    if (odd_thread) {
        kthread_stop(odd_thread);
    }
}

module_init(odd_thread_init);
module_exit(odd_thread_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Kernel thread to print odd numbers");
MODULE_VERSION("1.0");
