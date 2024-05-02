#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int n1 = 5;

int n2 = 4;
void sigint_handler(int signum)
{
    
    printf("sum SIGINT(%d)and %d:%d\n",n1,n2,n1+n2);
   
}

void sigint_handler1(int signum)
{
	
	printf("sub SIGINT(%d) and %d :%d\n",n1,n2,n1-n2);
	
}

int main()
{

	signal(SIGINT,sigint_handler);
	signal(SIGTSTP,sigint_handler1);


	printf("Adding and sub of number%d and %d\n",n1,n2);
	while(1)
	{
	}
	return 0;
}
