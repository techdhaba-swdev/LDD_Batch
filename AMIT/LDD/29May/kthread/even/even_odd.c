#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AMIT");
MODULE_DESCRIPTION("Even and Odd Number Printing Kernel Module");

static struct task_struct *even_thread;
static struct task_struct *odd_thread;

int even_numbers(void *data) {
    int i;
    for (i = 0; i <= 20; i += 2) {
        printk(KERN_INFO "Even: %d\n", i);
        msleep(1000); // Sleep for 1 second
    }
    return 0;
}

int odd_numbers(void *data) {
    int i;
    for (i = 1; i <= 20; i += 2) {
        printk(KERN_INFO "Odd: %d\n", i);
        msleep(1000); // Sleep for 1 second
    }
    return 0;
}

static int __init mymodule_init(void) {
    printk(KERN_INFO "Even and Odd Number Printing Module Loaded\n");

    even_thread = kthread_run(even_numbers, NULL, "even_thread");
    odd_thread = kthread_run(odd_numbers, NULL, "odd_thread");

    return 0;
}

static void __exit mymodule_exit(void) {
    kthread_stop(even_thread);
    kthread_stop(odd_thread);
    printk(KERN_INFO "Even and Odd Number Printing Module Unloaded\n");
}

module_init(mymodule_init);
module_exit(mymodule_exit);


