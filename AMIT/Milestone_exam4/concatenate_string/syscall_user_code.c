#include <stdio.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

#define CONCAT_STRINGS_SYSCALL 440 // Use the assigned system call number

int main() {
    char inputString1[100];
    char inputString2[100];
    char concatenatedResult[200];

    // Get input strings from the user
    printf("Enter Input String 1: ");
    scanf("%s", inputString1);

    printf("Enter Input String 2: ");
    scanf("%s", inputString2);

    // Call the kernel-space system call for string concatenation
    syscall(CONCAT_STRINGS_SYSCALL, inputString1, inputString2, concatenatedResult);

    // Print the concatenated result
    printf("Concatenated Result: %s\n", concatenatedResult);

    return 0;
}


