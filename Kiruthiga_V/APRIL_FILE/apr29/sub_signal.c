#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Global variables to store the numbers
int num1 = 0, num2 = 0;

// Signal handler function
void signal_handler(int signum) {
    if (signum == SIGTSTP) {
        printf("\nDifference of %d and %d is: %d\n", num1, num2, num1 - num2);
        exit(EXIT_SUCCESS);
    }
}

int main() {
    // Register signal handler for SIGTSTP (Ctrl+Z)
    if (signal(SIGTSTP, signal_handler) == SIG_ERR) {
        perror("Unable to set up signal handler");
        exit(EXIT_FAILURE);
    }

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Keep the program running until Ctrl+Z is pressed
    while (1) {}

    return 0;
}


