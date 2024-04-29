#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//signal handler for SIGFPE	
void sigfpe_handler(int signum){
	printf("Caught SIGFPE : Floating point exception\n");
	}
int main()
{
	//Register the signal handler
	if (signal(SIGFPE , sigfpe_handler) == SIG_ERR)
	{
		perror("Unable to set up signal handler");
		exit(EXIT_FAILURE);
	}
	//perform a floating-point operation that may couse an exception
	float result = 1/0; //Division by zero should trigger SIGFPE

	//the following line should never be reached if SIGFPE is properly handled
	printf("Result: %f\n",result);
	return EXIT_SUCCESS;
}
