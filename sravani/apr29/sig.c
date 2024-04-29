#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

//signal handle for SIGFEP
void sigfpe_handler(int signum){
	printf("Caught SIGFPE: Floating point exception\n");
	//Handle the exception such as logging and graceful shutdoen
	exit(EXIT_FAILURE);
}
int main(){
	//register the signal handler
	if (signal(SIGFPE, sigfpe_handler) == SIG_ERR){
	   perror("Unable to set up signal handler");
	exit(EXIT_FAILURE);
}

//perform a loating pointoperation that may cause an exception
float result = 1/ 0;

printf("result: %f\n",result);
return EXIT_SUCCESS;
}
