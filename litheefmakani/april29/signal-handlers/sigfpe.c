#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

//signal handler for SIGFPE
void sigfpe_handler(int signum){
	printf("Caught SIGFPE: floating point exception\n");
	//handle the exception , such as logging and grceful shutdown 
	exit(EXIT_FAILURE);
}
int main(){
	//registering the signal handler
	if(signal(SIGFPE,sigfpe_handler)==SIG_ERR){
		perror("unable to set up signal handler");
		exit(EXIT_FAILURE);
	}
	//perform a floating point operation that may cause an exception 
	float result = 1/0;//division by zero should trigger SIGFPE


	printf("result :%f\n",result);
	return EXIT_SUCCESS;
}
