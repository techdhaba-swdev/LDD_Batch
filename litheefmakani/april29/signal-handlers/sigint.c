#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

//signal handler function 
void sigint_handler(int signum){
	printf("Caught SIGINT (%d)\n",signum);
	//custom handling for SIGINT 
	//foe example, cleanup or graceful shutdown 
	exit(signum);
}
int main(){
	//define the struct for the signal action 
	//signal(SIGINT,sigint_handler);
	struct sigaction sa;
	sa.sa_handler = sigint_handler; //set the signal handler function
	sigemptyset(&sa.sa_handler);
	sa.sa_flags = 0;

	//register the signal handler for SIGINT 
	if(sigaction(SIGINT, &sa, NULL) ==-1){
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	printf("signal handler registered for SIGINT. press CTRL+C to trigger.\n");
	
	//long indefinitely 
	while(1){
		//do something......
	}

	return 0;
}
