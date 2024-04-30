#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sigint_handler(int signum){
	printf("Caught SIGINT (%d)\n", signum);
	exit(signum);
}
int main(){
	struct sigaction sa;
	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	if(sigaction(SIGINT, &sa, NULL) == -1){
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	printf("Signal handler registered for SIGINT. pRESS Ctrl+c to trigger.\n");
	while(1){
	}
	return (EXIT_SUCCESS);
}

