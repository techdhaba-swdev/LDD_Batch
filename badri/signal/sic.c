#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler function

void sigint_handler(int signum)
{
	printf("Caught SIGINT (%d)\n", signum);
	// custom handling for sigint
	// for example . cleanup or graceful shutdown
	exit (signal);
}
int main()
{
	// define the struct for the signal action
	// signal (sigint , sigint_handler);
	struct sigaction sa;
	sa.sa_handler = sigint_handler; // set the signal handler function
	sigemptyset(&sa.sa_mask); // clear the signal mask
	sa.sa_flags = 0; //no special flags
	
	// register the signal handler for sigint
	
	if (sigaction(SIGINT ,&sa ,NULL) == -1)
			{
				perror("sigaction");
				exit(EXIT_FAILURE);
			}
	printf("signal handler registered for SIGINT. press ctrl+c to trigger.\n");

	// Loop indefinitely
	
	while(1)
	{
		//do something
	}
	return 0;
}

