You need to write a new system call in the Linux kernel that concatenates two strings provided by the user and returns the concatenated result. The task involves:
1.	Writing the Kernel Module to Implement the New System Call:
o	Implement the system call handler that takes two strings as input and returns their concatenation.
2.	Writing a User-Space Program:
o	Utilize this new system call to concatenate two user-provided strings and print the result.

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>

#define MAX_LENGTH 256 // Maximum length of input strings

SYSCALL_CONCATSTR(concat_strings, const char __user *, str1, const char __user *, str2, char __user *, result)//This is the syste call 
{
    char string1[MAX_LENGTH], string2[MAX_LENGTH], concat[MAX_LENGTH * 2];
    int len1, len2;

    // Copy string1 from user space to kernel space
    if (copy_from_user(string1, str1, MAX_LENGTH))
        return -EFAULT;

    // Copy string2 from user space to kernel space
    if (copy_from_user(string2, str2, MAX_LENGTH))
        return -EFAULT;

    // Find the lengths of the input strings
    len1 = strnlen_user(string1, MAX_LENGTH);
    len2 = strnlen_user(string2, MAX_LENGTH);

    // Concatenate the strings
    if (len1 + len2 > MAX_LENGTH)
        return -EINVAL; // Result would exceed maximum length
    snprintf(concat, sizeof(concat), "%s%s", string1, string2);

    // Copy the concatenated string from kernel space to user space
    if (copy_to_user(result, concat, len1 + len2 + 1))
        return -EFAULT;

    return 0; // Success
}

static int __init concat_strings_init(void)
{
    printk(KERN_INFO "Concatenate Strings System Call Loaded\n");
    return 0;
}

static void __exit concat_strings_exit(void)
{
    printk(KERN_INFO "Concatenate Strings System Call Unloaded\n");
}

module_init(concat_strings_init);
module_exit(concat_strings_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("System call to concatenate two strings");
