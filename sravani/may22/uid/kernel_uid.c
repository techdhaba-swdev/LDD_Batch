// kernel_module.c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/cred.h>
#include <linux/sched.h>
//Function to be called when module is loaded
static int __init my_module_init(void) {
    const struct cred *cred = current_cred();//get credintial of the current process
//Printing the current uid and euid
    printk(KERN_INFO "Current UID: %u\n", from_kuid(&init_user_ns, cred->uid));
    printk(KERN_INFO "Current EUID: %u\n", from_kuid(&init_user_ns, cred->euid));
    //check if the process has CAP_SYS_ADMIN capability
    if (capable(CAP_SYS_ADMIN)) {
        printk(KERN_INFO "Process has CAP_SYS_ADMIN capability\n");
    } else {
        printk(KERN_INFO "Process does not have CAP_SYS_ADMIN capability\n");
    }
//Check if uid is equal to euid
    if (uid_eq(cred->uid, cred->euid)) {
        printk(KERN_INFO "UID is equal to EUID\n");
    } else {
        printk(KERN_INFO "UID is not equal to EUID\n");
    }

    return 0;
}
//Function to be called when module is unloaded
static void __exit my_module_exit(void) {
    printk(KERN_INFO "Kernel module exiting\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A module to check capabilities and UID equality");
