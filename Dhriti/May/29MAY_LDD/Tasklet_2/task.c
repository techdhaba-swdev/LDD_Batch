#include <linux/module.h>        // Header file for loading kernel modules
#include <linux/kernel.h>        // Header file for kernel functions
#include <linux/interrupt.h>     // Header file for interrupt handling

void my_tasklet_handler(unsigned long data)
{
    printk(KERN_INFO "Tasklet handler called with data: %lu\n", data);  // Print message when tasklet is executed
}

DECLARE_TASKLET(my_tasklet,0);  // Declare a tasklet named my_tasklet

void my_interrupt_handler(void)
{
    // Schedule the tasklet
    tasklet_schedule(&my_tasklet);  // Schedule the tasklet when the interrupt occurs
}

static int __init my_module_init(void)
{
    printk(KERN_INFO "Loading tasklet module\n");   // Print loading message when module initializes
    // Simulate scheduling the tasklet
    my_interrupt_handler();    // Simulate an interrupt to trigger the tasklet
    return 0;   // Return 0 to indicate successful initialization
}

static void __exit my_module_exit(void)
{
    // Ensure the tasklet is killed before module exit
    tasklet_kill(&my_tasklet); // Kill the tasklet before unloading the module
    printk(KERN_INFO "Unloading tasklet module\n"); // Print unloading message when module exits
}

module_init(my_module_init);   // Set initialization function for the module
module_exit(my_module_exit);   // Set cleanup function for the module

MODULE_LICENSE("GPL");      
MODULE_AUTHOR("techdhaba"); 
MODULE_DESCRIPTION("A simple tasklet example");  
