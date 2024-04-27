#include <stdio.h>
#include <signal.h>
//handler dor SIGINT, caused by Ctrl+c at keyboard
void handle_signit(int sig)
{
	printf("caught signal %d\n",sig);
}
int main(){
	signal(SIGINT, handle_signit);
	while(1);
	return 0;
}
