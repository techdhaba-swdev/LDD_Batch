#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig)
{
	printf("signal terminated\n");
	exit(0);
}
int main()
{
	signal(SIGTSTP , handler);
	printf("enter ctrl z to terminte \n");
	while(1);

}

