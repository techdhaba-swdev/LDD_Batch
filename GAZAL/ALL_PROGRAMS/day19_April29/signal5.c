#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//signal handler function for SIGUSR1

void sigusr1_handler(int signum){
	printf("caught SIGUSR1\n");
	//custom handling for SIGUSR1
}
//signal handler function for SIGUSR2

void sigusr2_handler(int signum){
        printf("caught SIGUSR2\n");
        //custom handling for SIGUSR2
}
int main(){
	//register signal handle for SIGUSR1
	signal(SIGUSR1, sigusr1_handler);
	 //register signal handle for SIGUSR2
        signal(SIGUSR2, sigusr2_handler);
	printf("PID:%d\n",getpid());
	printf("send sigusr1 or gigusr2 to this process to trigger signal handlers\n");

	while(1){
		sleep(1);
	}
	return 0;
}


