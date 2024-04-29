#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//signal handler for SIGFPE
void sigfpe_handler(int signum) {
	printf("Caught SIGFPE: Floating point exception\n");
	//handle the exception, such as logging and graceful shutdown
	//exit(EXIT_FAILURE); //-1//0
}
int main() {
	//register the signal handler
	if(signal(SIGFPE, sigfpe_handler) == SIG_ERR) {
		perror("unable to set up signal handler");
		exit(EXIT_FAILURE);
	} 
	//perform a floating-point operation that may cause an exception
	float result = 1 / 0;

	//the following line should never be reached if SIGFPE is properly handled
	printf("result: %f\n", result);

	return EXIT_SUCCESS;
}

