//cpp programe to illustrate
//user -defined siganl handler
#include<stdio.h>
#include<signal.h>

//handler for SIGINT,caused by 
//ctrl -c at keyboard
void handle_sigint(int sig)
{
	printf("caught signal %d\n", sig);
}
int main()
{
	signal(SIGINT, handle_sigint);
	while(1);
	return 0;
}
