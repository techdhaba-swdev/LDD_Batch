#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Global variables to hold the numbers for addition and subtraction
int n1 = 5;
int n2 = 3;

// Signal handler function for Ctrl+C (SIGINT)
void sigint_handler(int signum) {
    printf("\nCtrl+C pressed. Adding %d and %d: %d\n", n1, n2, n1 + n2);
}

// Signal handler function for Ctrl+Z (SIGTSTP)
void sigtstp_handler(int signum) {
    printf("\nCtrl+Z pressed. Subtracting %d from %d: %d\n", n1, n2, n1 - n2);
}

int main() {
	signal(SIGINT,SIG_IGN);
    // Register the signal handler for SIGINT (Ctrl+C)
    //signal(SIGINT, sigint_handler);

    // Register the signal handler for SIGTSTP (Ctrl+Z)
    signal(SIGTSTP, sigtstp_handler);


    printf("adding and sub of numbers n1=%d,n2=%d\n",n1,n2);

    // Loop indefinitely
    while (1) {
        // Do something or simply wait for signals
    }

    return 0;
}
