#include<linux/init.h>          // Include header file for kernel module initialization
#include<linux/module.h>        // Include header file for kernel modules
#include<linux/printk.h>        // Include header file for kernel printing functions

MODULE_LICENSE("GPL");          // Set the license of the module to GPL
MODULE_AUTHOR("DHRITI");        // Set the author of the module

static int __init hello_init(void)
{
        printk(KERN_INFO "Hello_world\n");     // Print "Hello_world" to kernel log
        return 0;                               // Return success status
}

static void __exit hello_exit(void)
{
        printk(KERN_INFO "GoodBye, cruel world.");   // Print "GoodBye, cruel world." to kernel log
}

module_init(hello_init);        // Define the function to be called when the module is loaded
module_exit(hello_exit);        // Define the function to be called when the module is unloaded

