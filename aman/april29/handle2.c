#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void signal_handler(int signum){
	if (signum == SIGINT){
		printf("Caught SIGINT: Interrupt signal\n");
	}
	else if(signum == SIGTERM){
	printf("Caught SIGTERM: Termination signal\n");
	}
}
int main(){
	if(signal(SIGINT, signal_handler) == SIG_ERR){
		perror("Unable to set up SIGINT signal handler");
		exit(EXIT_FAILURE);
	}
	if(signal(SIGTERM, signal_handler) == SIG_ERR){
		perror("Unable to set up SIGTERM signal handler");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for signals...\n");
	while(1){
	}
	return(EXIT_SUCCESS);
}
