#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

//signal handler function for USER1

void sigusr1_handler(int signum){
	printf("Custom signal (SIGUSR1) received!\n");

}
int main(){
	signal(SIGUSR1, sigusr1_handler);

	//periodically generating the custom signal
	while(1){
		printf("Waiting for the signal \n");
		sleep(5); //wait for 5 seconds 
	        printf("Generating custom signal(SIGUSR1) \n");
		kill(getpid(),SIGUSR1);
	}
	return 0;
}
