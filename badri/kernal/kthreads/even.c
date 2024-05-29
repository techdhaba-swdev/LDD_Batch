#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>

static struct task_struct *even_thread;

// Function to print even numbers
static int print_even(void *data) {
    int i = 2; // Start with the first even number
    while (!kthread_should_stop()) {
        printk(KERN_INFO "Even number: %d\n", i);
        i += 2; // Increment by 2 to get the next even number
        msleep(1000); // Sleep for 1 second
    }
    return 0;
}

static int __init even_thread_init(void) {
    printk(KERN_INFO "Initializing even number printing thread\n");

    // Create the kernel thread
    even_thread = kthread_run(print_even, NULL, "even_thread");
    if (IS_ERR(even_thread)) {
        printk(KERN_ERR "Failed to create even number printing thread\n");
        return PTR_ERR(even_thread);
    }

    return 0;
}

static void __exit even_thread_exit(void) {
    printk(KERN_INFO "Stopping even number printing thread\n");

    // Stop the kernel thread
    if (even_thread) {
        kthread_stop(even_thread);
    }
}

module_init(even_thread_init);
module_exit(even_thread_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Kernel thread to print even numbers");
MODULE_VERSION("1.0");
