#include<stdio.h>
#include<stdlib.h>
#include<signal.h>


void sigint_handler(int signum){
	printf("Caught SIGINT (%d)\n",signum);

// Custom handling for SIGINT

exit(signum);
}

int main() {

	// Defide theruct for the signal action
	 //signal(SIGINT, sigint_hanler);
	struct sigaction sa; // Set the signal handler function 
	sa.sa_handler = sigint_handler;// Clear the signal mask
	sigemptyset(&sa.sa_mask);// No special flags
	sa.sa_flags = 0;

	//register the signal handler for SIGINT
	if(sigaction(SIGINT, &sa, NULL) == -1){
	   perror("sigaction");
	   exit(EXIT_FAILURE);

}	
	printf("Signal handler registered for SIGINT. Press Ctrl+C to trigger. \n");

	// Loop indefinitely

	while (1) {

	// Do something.

	}

	return 0;

}
