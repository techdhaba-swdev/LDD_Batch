#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// signal handler for SIGFPE 
 
void sigfpe_handler(int signum) {
	printf("Caught SIGFPE: floating point exception\n");
	exit(EXIT_FAILURE);
}
int main() {
	if(signal(SIGFPE, sigfpe_handler) == SIG_ERR) {
		perror("unable to set up signal handler ");
		exit(EXIT_FAILURE);
	}
        // floating point exception
	float result = 1/0 ; // division by zero can trigger SIGFPE 
// the following  nerve reach is IF SIGFPE is handled properly
	printf("result :%f\n" ,result);

	return EXIT_SUCCESS;
}
