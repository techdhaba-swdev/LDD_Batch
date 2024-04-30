#include <stdio.h>
 #include <stdlib.h>
 #include <signal.h>
 #include<time.h>
 
// Signal handler for SIGFPE
 void sigfpe_handler(int signum) {
 	printf("Caught SIGFPE: Floating point exception\n");
 	// Handle the exception, such as logging and graceful shutdown
    // exit(EXIT_FAILURE);//-1//0
 }
 
int main() {
 	// Register the signal handler
 	clock_t start=clock();
 	if (signal(SIGFPE, sigfpe_handler) == SIG_ERR) {
     	perror("Unable to set up signal handler");
     	exit(EXIT_FAILURE);
 	}
 
	// Perform a floating-point operation that may cause an exception
 	float result = 1 / 0; // Division by zero should trigger SIGFPE
 
	// The following line should never be reached if SIGFPE is properly handled
	clock_t end=clock();
	double time_taken=((double)(end-start));
	printf("time taken is %f\n",time_taken);
 	printf("Result: %f\n", result);
 	
 
	return EXIT_SUCCESS;
 }



