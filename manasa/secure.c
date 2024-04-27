#include <stdio.h>

int main() {
    int pin = 1234;
    int enteredPin;
    
    printf("Enter your PIN: ");
    scanf("%d", &enteredPin); // No input validation
    if (enteredPin == pin) {
        printf("Access granted!\n");
    } else {
        printf("Access denied!\n");
    }
    
    return 0;
}
