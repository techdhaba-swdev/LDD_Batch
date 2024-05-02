#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
//signal handler function
void sigint_handler(int signum){
	//custom handling for SIGINT
	//for example cleanup or graceful shutdown
	printf("caught SIGINT(%d)\n", signum);
	exit(signum);
}

int main(){
	//define the struct for signal action
	struct sigaction sa;
	sa.sa_handler = sigint_handler;//set signal handler function
	sigemptyset(&sa.sa_mask);//clear signal mask
	sa.sa_flags = 0;//no special flag

	//register signal  handler for sigint
	if(sigaction(SIGINT, &sa, NULL) == -1){
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	printf("signal handler registered for SIGINT.press ctrl+c to trigger.\n");
	//loop indefinately
	while(1){
	}
	return 0;
}
