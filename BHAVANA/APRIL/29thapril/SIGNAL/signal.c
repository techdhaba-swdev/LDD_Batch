#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler function
void sigint_handler(int signum) {
	printf("Caught SIGINT (%d)\n", signum);
	// Custom handling for SIGINT
	// For example, cleanup or graceful shutdown
	exit(signum);
}
int main() {
	// Define the struct for the signal action
	//signal(SIGINT, sigint_hanler);
struct sigaction sa;
sa.sa_handler = sigint_handler;
sigemptyset(&sa.sa_mask);
sa.sa_flags = 0;

// Set the signal handler function
// Clear the signal mask
// No special flags

// Register the signal handler for SIGINT
if (sigaction (SIGINT, &sa, NULL) == -1) {
	perror("sigaction");
	exit(EXIT_FAILURE);
}
printf("Signal handler registered for SIGINT. Press Ctrl+C to trigger.\n");
// Loop indefinitely
while (1) {
// Do something...
}
return 0;
}
