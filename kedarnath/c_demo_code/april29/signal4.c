#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sigint_handler(int signum){
	printf("caught sigint %d \n",signum);
	exit(signum);
}

int main(){

	struct sigaction sa;
	sa.sa_handler=sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;

	if(sigaction(SIGINT,&sa,NULL)==-1){
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	printf("signal handler registred for sigint press cltl+c trigger\n");

	while(1){

	}

	return 0;
}

