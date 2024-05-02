#include <stdio.h>

#include <stdlib.h>

#include <signal.h>

// Signal handler function

void sigint_handler(int signum) {

printf("Caught SIGINT (%d)\n", signum);

// Custom handling for SIGINT
// For example, cleanup or graceful shutdown
exit(signum);
}

int main() {

// Defide theruct for the signal action //signal(SIGINT, sigint_hanler);

struct sigaction sa;

sa.sa_handler = sigint_handler;

sigemptyset(&sa.sa_mask);
sa.sa_flags = 0;

if(sigaction(SIGINT,&sa,NULL) == -1)
{
	perror("sigaction");
	exit(EXIT_FAILURE);

}
printf("signal handler registered for SIGINT, press ctrl+c to trigger.\n");
while(1)
{ //be something...
}
return 0;
}

