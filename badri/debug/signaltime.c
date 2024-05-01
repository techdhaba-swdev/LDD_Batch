#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig)
{
	int i , sum = 0;

	for(i = 0 ; i<30 ; i++)
	{
		sum = sum + i;
		printf("sum is %d\n" , sum);
	}
}
void handler2(int sig)
{
	printf("program terminated\n");
	exit(0);
}

int main()
{
	clock_t start = clock();
	signal  (SIGINT , handler);
	signal  (SIGTSTP , handler2);
	printf("enter ctrl+c to print sum & ctrl+z to terminate\n");
	  clock_t end = clock();
        double time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("time used %f \n",time_used);

	while(1)	
	{
	}
}

