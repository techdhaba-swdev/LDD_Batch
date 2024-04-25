#include <stdio.h>

int main() {
    char password[20];
    printf("Enter password: ");
    gets(password);
    // Processing sensitive information without encryption or hashing
    return 0;
}
