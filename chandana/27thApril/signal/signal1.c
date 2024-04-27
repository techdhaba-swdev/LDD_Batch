//cpp program to illustarte
//user-defined signal handler


#include <stdio.h>
#include <signal.h>

//handler for SIGINT ,caused by
//ctrl-C at keyboard

void handle_sigint(int sig) 
{
	printf("caught signal %d\n", sig);
}
void handle_sigkill(int sig) {
	printf("received SIGKILL signal\n");
	//exit(0);
}
int main() 
{
	signal(SIGINT,handle_sigint);
	//signal(SIGKILL,handle_sigkill);
	return 0;
}
