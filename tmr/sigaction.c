#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
//signal handler function
void sight_handler(int signum)
{
	printf("caught SIGINT (%d)\n", signum);
	//custom handling for SIGINT	
	//for example, cleanup or graceful shutdown
	exit(signum);
}
int main()
{
	//define the struct for the signal action
	struct sigaction sa;
	sa.sa_handler= sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags =0;

	if (sigaction(SIGINT,&sa,NULL)== -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	printf("signal handler registred for SIGINT.press Ctrl+C to trigger.\n");
	while(1)

	{

	}
	return 0;
}
