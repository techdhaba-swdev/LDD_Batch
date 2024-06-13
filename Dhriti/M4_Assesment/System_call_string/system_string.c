#include <linux/kernel.h>       
#include <linux/module.h>       
#include <linux/syscalls.h>     
#include <linux/uaccess.h>      
#include <linux/unistd.h>
#include <linux/init.h>
// Define the system call with asmlinkage 
asmlinkage long sys_concat_strings(const char __user *str1, const char __user *str2, char __user *result) {
    char kernel_str1[500];    // Buffer to hold the first string from user space
    char kernel_str2[500];    // Buffer to hold the second string from user space
    char kernel_result[1000];  // Buffer to hold the concatenated result

    // Check if any of the pointers are NULL
    if (str1 == NULL || str2 == NULL || result == NULL) {
        return -EINVAL; // Return an invalid argument error
    }

    // Copy the first string from user space to kernel space
    if (copy_from_user(kernel_str1, str1,500 )) {
        return -EFAULT; // Return a fault error if copy fails
    }

    // Copy the second string from user space to kernel space
    if (copy_from_user(kernel_str2, str2, 500)) {
        return -EFAULT; 
    }

    // Concatenate the two strings and store in kernel_result
    snprintf(kernel_result, 1000, "%s%s", kernel_str1, kernel_str2);

    // Copy the concatenated result back to user space
    if (copy_to_user(result, kernel_result, strlen(kernel_result) + 1)) {
        return -EFAULT;
    }

    return 0;
}


