// custom_syscall.c

#include <linux/kernel.h>
#include <linux/syscalls.h>
#include<stdio.h>
asmlinkage long sys_custom_syscall(void) {
    printk(KERN_INFO "Custom syscall called\n");
    return 0;
}


