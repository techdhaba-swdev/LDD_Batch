#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigint_handler(int signum) {
	printf("\n SIGINT recevied.Exactly gracefully \n");
	exit (signum);
}

int main() {
	//Registering the signal handler
if (signal(SIGINT,sigint_handler) == SIG_ERR) {
	perror("signal");
	exit(EXIT_FAILURE);
}
//infinite loop 
while(1) {
}
exit(EXIT_SUCCESS);
}
