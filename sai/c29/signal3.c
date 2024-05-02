#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sigint_handler(int signum)
{
	printf("Hello world\n");
	exit(signum);
}

int main()
{
	if(signal(SIGINT,sigint_handler) == SIG_ERR)
	{
		perror("Unbale to set up SIGINT signal handle");
		exit(EXIT_FAILURE);
	}

	printf("Waiting for SIGINT signal..\n");

	while(1)
	{
	}
	return 0;
}
	
