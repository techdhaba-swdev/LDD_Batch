#include <stdio.h>        // Include standard input-output header file for printf function.
#include <unistd.h>       // Include POSIX operating system API header file for syscall function.
#include <sys/syscall.h>  // Include system call numbers header file.

#define SYSCALL_NUM 222   // Define the syscall number

int main() {
    char str1[] = "Hello, ";    // Define the first string.
    char str2[] = "world!";     // Define the second string.
    char result[1000];           // Define a buffer to store the concatenated result.

    // Invoke the custom system call with the defined syscall number
    int ret = syscall(SYSCALL_NUM, str1, str2, result);

    // Check if the syscall was successful
    if (ret == 0) {
        // Print the concatenated string if successful
        printf("Concatenated String: %s\n", result);
    } else {
        // Print the error return value if syscall failed
        printf("Syscall failed with return value: %d\n", ret);
    }

    return 0; // Return 0 to indicate successful execution
}
