#include <stdio.h>        
#include <unistd.h>       
#include <sys/syscall.h>  

#define SYSCALL_NUM 222 // Define the syscall number

int main() {
    char str1[] = "Hello, ";    
    char str2[] = "world!";     
    char result[1000];           

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

    return 0; 
}
