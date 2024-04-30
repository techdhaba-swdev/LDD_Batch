#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigusr1_handler(int signum) {
	printf("custom signal (SIGUSR1) recevied .Exiting \n");
	//exit(EXIT_SUCCESS);
}

int main() {
	//Register the signal handler
	if(signal(SIGUSR1,sigusr1_handler) == SIG_ERR) {
		perror("signal");
		exit(EXIT_FAILURE);
	}
	printf("program started.press ctrl+C to exit\n");
        
	//set up a timer to send SIGUSR1 every 3 seconds
	while(1) {
		alarm(3);
		sleep(2);

//generate SIGUSR1 signal
if(kill(getpid() , SIGUSR1)==-1) {
	perror("KILL");
	exit (EXIT_FAILURE);
}
}
exit(EXIT_SUCCESS);
}
