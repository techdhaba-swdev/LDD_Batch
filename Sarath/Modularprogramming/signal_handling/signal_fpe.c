#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sigfpe_handler(int signum)
{
	printf("Caught SIGFPE : Floating point exception\n");
	exit(EXIT_FAILURE);
}
int main()
{
	if(signal(SIGFPE,sigfpe_handler)==SIG_ERR)
	{
		perror("Unable to set up signal handler");
		exit(EXIT_FAILURE);
	}
	float result =1/0;
	printf("Result : %d\n",result);
	return EXIT_SUCCESS;
}
