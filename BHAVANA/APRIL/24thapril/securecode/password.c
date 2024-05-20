#include <stdio.h>
#include <string.h>

int main(void) {
    char Password[9]; // Including space for the null terminator

    printf("Enter 8-character password: ");
    fgets(Password, sizeof(Password), stdin);

    Password[strcspn(Password, "\n")] = '\0';

    printf("Entered password: %s\n", Password);

    return 0;
}
