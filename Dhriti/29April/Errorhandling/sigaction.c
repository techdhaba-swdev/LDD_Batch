#include <stdio.h>

#include <stdlib.h>

#include <signal.h>

 void sigint_handler(int signum) {

printf("Caught SIGINT (d)\n", signum);

//Custom handling for SIGINT

//example, cleanup or graceful shutdown

exit(signum);

}

int main() {

// Define the struct for the signal action

//signal(SIGINT, sigint hanter);

struct sigaction sa;

sa.sa_handler = sigint_handler;

sigemptyset(&sa.sa_mask);

sa.sa_flags = 0;

// Set the signal handler function

// Clear the signal mask

If (sigaction(SIGINT, &sa, NULL)==-1) {

// Register the signat handler for SIGINT if (sigaction(SIGINT, &sa, NULL) = -1) {

perror("sigaction");

exit(EXIT_FAILURE);

}

printf("Signal handler registered for SIGINT. Press Ctrl+C to trigger.\n");

// Laep indefinitely

while (1) {

}// Do something...

return 0;
}
