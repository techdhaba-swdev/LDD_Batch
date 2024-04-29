#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
int a = 20;
int b = 30;
void handler()
{
int sub = a - b;
printf("enter ctrl+z to print sub %d\n",sub);
}
void handler2()
{
	printf("press ctrl+c to stop");
	exit(0);
	}
int main()
{
	signal(SIGTSTP , handler);
	printf("enter ctrl+z to print sub \n");
	signal(SIGINT , handler2);
	printf("press ctrl+c to stop\n");
	while(1)
	{
	
	}


}


