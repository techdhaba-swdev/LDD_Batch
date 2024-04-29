#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int a =10;
int b =20;
 
void sigint_handler(int sig)
{
	int sum = a+b;
	printf("sum: %d\n",sum);
}
void sigtstp_handler(int sig)
{
	printf("exit the program\n");
	exit (0);
}

int main()
	{
		signal(SIGINT , sigint_handler);
		printf("press ctrl+c to add two numbers\n");
		signal(SIGTSTP , sigtstp_handler);
			printf("press ctrl+z to stop program\n");
		while (1)
		{
			

		}
		return 0;
	}
