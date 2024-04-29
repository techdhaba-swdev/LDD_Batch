#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>//operating system api
		   
// Signal handler function for SIGUSR1
void sigusr1_handler(int signum){
	printf("received signal\n");
}
int main(){
	// Register the signal handler
	signal(SIGUSR1,sigusr1_handler);
	printf("periodically running.....\n");
	while (1) {
        // Do something or simply wait for signals	
	sleep(3);//pause the program execution for 3 seconds
	kill(getpid(),SIGUSR1);//generates the SIGUSR1 signal by sending to the current proceeess getpid() this is done using kill function
    }

    return 0;
}

