#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler function for SIGINT
void sigint_handler(int signum) {
    printf("\nCaught Ctrl+C (SIGINT)\n");
    exit(EXIT_SUCCESS); // Exit the program gracefully
}

int main() {
    // Register signal handler for SIGINT
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("Unable to set signal handler for SIGINT");
        return EXIT_FAILURE;
    }

    printf("HELLO GUYS NOW Press Ctrl+C (SIGINT) to exit .\n");

    // Infinite loop to keep the program running
    while (1) {
        
    }

    return EXIT_FAILURE; 
}
