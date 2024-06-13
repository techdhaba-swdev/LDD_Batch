#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>

SYSCALL_DEFINE3(concat_strings, const char __user *, str1, const char __user *, str2, char __user *, result) {
    char kernelConcatenatedResult[200];
    int len1, len2;

    // Copy input strings from user space to kernel space
    len1 = strncpy_from_user(kernelConcatenatedResult, str1, sizeof(kernelConcatenatedResult));
    len2 = strncpy_from_user(kernelConcatenatedResult + len1, str2, sizeof(kernelConcatenatedResult) - len1);

    // Null-terminate the concatenated result
    kernelConcatenatedResult[len1 + len2] = '\0';

    // Copy the concatenated result back to user space
    if (copy_to_user(result, kernelConcatenatedResult, len1 + len2 + 1) != 0)
        return -EFAULT;

    return 0;
}

//write system call in kernel before compiling the kernel  usr/src/concatenate_string/conc_string.c
