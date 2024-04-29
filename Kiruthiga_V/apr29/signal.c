#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void sigfpe_handler(int signum)
{
	printf("caught SIGFPE: Floating point exception\n");
	//exit(EXIT_FAILURE);//-1//0
}
int main()
{
	if(signal(SIGFPE,sigfpe_handler)== SIG_ERR)
	{
		perror("unable to set up signal handler");
		exit(EXIT_FAILURE);
	}
	float result = 1 / 0;
	printf("Result: %f\n", result);
	return EXIT_SUCCESS;
}
