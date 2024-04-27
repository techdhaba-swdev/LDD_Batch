#include <stdio.h>
#include <string.h>

int main() {
    // Declaring and initializing a string
    char str[] = "Hello, world!";
    
    // Printing the string
    printf("String: %s\n", str);
    
    // Getting the length of the string
    int length = strlen(str);
    printf("Length of the string: %d\n", length);
    
    // Accessing individual characters in the string
    printf("First character: %c\n", str[0]);
    printf("Last character: %c\n", str[length - 1]);
    
    // Modifying the string
    str[7] = 'W';
    printf("Modified string: %s\n", str);
    
    return 0;
}
