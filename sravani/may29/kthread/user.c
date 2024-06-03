#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

static struct task_struct *odd_thread; // Declaring a pointer to hold the odd thread task_struct
static struct task_struct *even_thread; // Declaring a pointer to hold the even thread task_struct

// Function to handle the odd numbers thread
int odd_thread_function(void *data) {
    int i;
    // Infinite loop to print odd numbers
    for (i = 1; ; i += 2) {
        printk(KERN_INFO "Odd Thread: %d\n", i); // Print odd number
        msleep(1000); // Sleep for 1 second
    }
    return 0;
}

// Function to handle the even numbers thread
int even_thread_function(void *data) {
    int i;
    // Infinite loop to print even numbers
    for (i = 2; ; i += 2) {
        printk(KERN_INFO "Even Thread: %d\n", i); // Print even number
        msleep(1000); // Sleep for 1 second
    }
    return 0;
}

// Module initialization function
static int __init my_module_init(void) {
    // Create the odd thread
    odd_thread = kthread_run(odd_thread_function, NULL, "odd_thread");
    if (IS_ERR(odd_thread)) {
        printk(KERN_ERR "Failed to create odd thread\n");
        return PTR_ERR(odd_thread);
    }

    // Create the even thread
    even_thread = kthread_run(even_thread_function, NULL, "even_thread");
    if (IS_ERR(even_thread)) {
        printk(KERN_ERR "Failed to create even thread\n");
        kthread_stop(odd_thread); // Stop the previously created thread if failed to create even thread
        return PTR_ERR(even_thread);
    }

    printk(KERN_INFO "Threads created successfully\n");
    return 0;
}

// Module exit function
static void __exit my_module_exit(void) {
    // Stop the odd thread if it exists
    if (odd_thread) {
        kthread_stop(odd_thread);
        printk(KERN_INFO "Odd thread stopped\n");
    }
    // Stop the even thread if it exists
    if (even_thread) {
        kthread_stop(even_thread);
        printk(KERN_INFO "Even thread stopped\n");
    }
}

// Register module initialization and exit functions
module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");

