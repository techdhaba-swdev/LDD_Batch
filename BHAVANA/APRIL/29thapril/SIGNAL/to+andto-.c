#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int num1, num2;
int result;

// Signal handler function for SIGINT (Ctrl+C)
void sigint_handler(int signum) {
    printf("Caught SIGINT (Ctrl+C)\n");
    printf("Enter two numbers to add: ");
    scanf("%d %d", &num1, &num2);
    result = num1 + num2;
    printf("Result of addition: %d + %d = %d\n", num1, num2, result);
}

// Signal handler function for SIGTSTP (Ctrl+Z)
void sigtstp_handler(int signum) {
    printf("Caught SIGTSTP (Ctrl+Z)\n");
    printf("Enter two numbers to subtract: ");
    scanf("%d %d", &num1, &num2);
    result = num1 - num2;
    printf("Result of subtraction: %d - %d = %d\n", num1, num2, result);
}

int main() {
    // Register the signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, sigint_handler);

    // Register the signal handler for SIGTSTP (Ctrl+Z)
    signal(SIGTSTP, sigtstp_handler);

    printf("Press Ctrl+C to add two numbers.\n");
    printf("Press Ctrl+Z to subtract two numbers.\n");

    // Loop indefinitely
    while (1) {
        // Do something...
    }

    return 0;
}
