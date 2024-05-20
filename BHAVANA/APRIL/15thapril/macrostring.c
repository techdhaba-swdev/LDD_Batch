#include <stdio.h>
#include <string.h>

#define CONCAT(a, b) strcat(a, b)

int main() {
    char str1[50] = "Hello, ";
    char str2[] = "world!";
    
    CONCAT(str1, str2);
    
    printf("Concatenated string: %s\n", str1);
    
    return 0;
}
