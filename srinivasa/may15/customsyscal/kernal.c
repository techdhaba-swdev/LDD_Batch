#include <linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include <linux/syscalls.h>

static long my_custom_syscall(int arg1, char *arg2);

static long my_custom_syscall(int arg1, char *arg2) {
    // Implement your custom logic here
    printk(KERN_INFO "Custom syscall called with arg1: %d, arg2: %s\n", arg1, arg2);
    return 0; // Or an appropriate error code
}
static __init int my_syscall_init(void) {
    sys_call_table[MY_CUSTOM_ syscall_NR] = my_custom_syscall;
    return 0;
}

module_init(my_syscall_init);

MODULE_LICENSE("GPL");
