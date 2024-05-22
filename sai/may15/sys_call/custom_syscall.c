#include <linux/kernel.h>
#include <linux/syscalls.h>

asmlinkage long sys_custom_syscall(void) {
    printk(KERN_INFO "Custom syscall called\n");
    return 0;
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RPS");
