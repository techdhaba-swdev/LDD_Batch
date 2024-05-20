#include <stdio.h>

int main() {
    char buffer[10];
    printf("Enter your name: ");
    gets(buffer); // Unsafe function, no boundary check
    printf("Hello, %s!\n", buffer); // Potential buffer overflow
    return 0;
}
