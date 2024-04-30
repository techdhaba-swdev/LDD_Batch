#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sig_handler(int signum){
	printf("Caught SIGFPE: Floating point exception\n");
	exit(EXIT_FAILURE);
}
int main(){
	if(signal(SIGFPE, sig_hndler) == SIG_ERR){
		perror("Unable to set up signal handler");
		exit(EXIT_FAILURE);
	}
	float result = 10 / 0;
	printf("Result: %f\n", result);
	return(EXIT_SUCCESS);
}
