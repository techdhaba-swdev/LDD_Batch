#include <stdio.h>

int main() {
    char buffer[50];
    printf("Enter your name: ");
    scanf("%s", buffer); // Unsafe, no format specifier
    printf(buffer); // Format string vulnerability
    return 0;
}
