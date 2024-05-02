#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//signal handler function
void sigint_handler(int signum)
{
	printf("caught SIGINT (%d)", signum);
	//custom handling for SIGINT
	//for exmaple ,cleanup
	exit(signum);
}
int main()
{
	//define the struct for signal action
	//signal(SIGINT, sigint_handler);
	struct sigaction sa;
	sa.sa_handler = sigint_handler; //set the signal handler function
	sigemptyset(&sa.sa_mask);       // clear the signal mask
	sa.sa_flags = 0;

	// register the signal handler for SIGINT
	if (sigaction(SIGINT,&sa, NULL) == -1)
	{
		perror("signation");
		exit(EXIT_FAILURE);
	}
	printf("signal handler registered for SIGINT. press CTRL + C to trigger.\n");
	// loop indefinatly
	while(1)
	return 0;
}

