#include <linux/kernel.h>
#include <linux/syscalls.h>

#define MY_CUSTOM_syscall_NR 333

MODULE_LICENSE("GPL");

extern void *sys_call_table; 

static long my_custom_syscall(int arg1, char *arg2) { 
    // Implement your custom logic here
    printk(KERN_INFO "Custom syscall called with arg1: %d, arg2: %s\n", arg1, arg2);
    return 0; // Or an appropriate error code
}

static int __init my_syscall_init(void) { 
    sys_call_table[MY_CUSTOM_syscall_NR] = (void)my_custom_syscall; 
    return 0;
}

module_init(my_syscall_init);
