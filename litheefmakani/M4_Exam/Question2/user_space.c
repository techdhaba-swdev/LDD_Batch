#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH 256 // Maximum length of input strings

int main()
{
    char string1[MAX_LENGTH], string2[MAX_LENGTH], result[MAX_LENGTH * 2];
    int ret;

    // Prompt the user to enter the first string
    printf("Enter the first string: ");
    fgets(string1, MAX_LENGTH, stdin);
    string1[strcspn(string1, "\n")] = '\0'; // Remove trailing newline character

    // Prompt the user to enter the second string
    printf("Enter the second string: ");
    fgets(string2, MAX_LENGTH, stdin);
    string2[strcspn(string2, "\n")] = '\0'; // Remove trailing newline character

    // Call the system call to concatenate the strings
    ret = syscall(329, string1, string2, result); // 329 is the syscall number for our custom system call(we are declaring the kernel space)

    if (ret == -1)
    {
        perror("Error");
        return 1;
    }

    printf("Concatenated string: %s\n", result);

    return 0;
}
