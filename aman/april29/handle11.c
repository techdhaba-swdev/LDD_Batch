#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void sigusr1_handler(int signum){
	printf("caught SIGUSR1 signal.\n");
}
int main(){
	signal(SIGUSR1, sigusr1_handler);
	printf("PID: %d\n", getpid());
	while(1){
	}
	return(EXIT_SUCCESS);
}

