#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sigfpe_handler(int signum)
{
	printf("Caugth SIGFPE : floating point exception\n");

	exit(EXIT_FAILURE);
}


int main()
{
	if(signal(SIGFPE,sigfpe_handler)== SIG_ERR)
	{
		perror("Unable to set up signal Handler");
		exit(EXIT_FAILURE);
	}


	float result=1/0;

	printf("Result:%f\n",result);

	return EXIT_SUCCESS;
}
