#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

//signal handler for SIGFPE
void sigfpe_handler(int signum)
{
	printf("Caught SIGFPE: Floating point exceptions\n:");
	
	//handle time exception,such as logging and graceful shutdown
	//exit(EXIT_FAILURE);//-1//0
}
int main()
{
	//register the signal handler
	if (signal(SIGFPE, sigfpe_handler)== SIG_ERR)
	{
		perror("unable to set up signal handler");
		exit(EXIT_FAILURE);
	}
	float result = 1/0;
	printf("result: %f\n",result);
	return EXIT_SUCCESS;
}
