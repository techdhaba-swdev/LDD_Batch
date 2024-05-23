// Include the necessary header files for kernel modules and access to kernel functionalities.
#include <linux/module.h>    // Core header for loading LKMs into the kernel
#include <linux/kernel.h>    // Contains types, macros, functions for the kernel
#include <linux/init.h>      // Macros for module initialization and cleanup
#include <linux/cred.h>      // Access to credentials (UID, GID, etc.)
#include <linux/sched.h>     // Access to the current task (process) structure

// Function that runs when the module is loaded into the kernel
static int __init my_module_init(void) {
    // Retrieve the credentials of the current process
    const struct cred *cred = current_cred();

    // Print the current UID (User ID) to the kernel log
    printk(KERN_INFO "Current UID: %u\n", from_kuid(&init_user_ns, cred->uid));
    // Print the current EUID (Effective User ID) to the kernel log
    printk(KERN_INFO "Current EUID: %u\n", from_kuid(&init_user_ns, cred->euid));

    // Check if the current process has the CAP_SYS_ADMIN capability
    if (capable(CAP_SYS_ADMIN)) {
        // Print a message indicating the process has CAP_SYS_ADMIN capability
        printk(KERN_INFO "Process has CAP_SYS_ADMIN capability\n");
    } else {
        // Print a message indicating the process does not have CAP_SYS_ADMIN capability
        printk(KERN_INFO "Process does not have CAP_SYS_ADMIN capability\n");
    }

    // Check if the UID is equal to the EUID
    if (uid_eq(cred->uid, cred->euid)) {
        // Print a message indicating the UID is equal to the EUID
        printk(KERN_INFO "UID is equal to EUID\n");
    } else {
        // Print a message indicating the UID is not equal to the EUID
        printk(KERN_INFO "UID is not equal to EUID\n");
    }

    // Return 0 to indicate successful initialization
    return 0;
}

// Function that runs when the module is removed from the kernel
static void __exit my_module_exit(void) {
    // Print a message to the kernel log indicating the module is exiting
    printk(KERN_INFO "Kernel module exiting\n");
}


module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");                
MODULE_AUTHOR("Your Name");            
MODULE_DESCRIPTION("A module to check capabilities and UID equality");  
