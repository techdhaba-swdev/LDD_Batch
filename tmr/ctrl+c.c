#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
int n1 , n2;
 
 void handleCtrlc(int sig)
{
	
	printf("sum: %d\n",n1+n2);


}
int main()
{
	signal(SIGINT,handleCtrlc);
	printf("enter first number:");
	scanf("%d",&n1);
	printf("enter second number:");
	scanf("%d",&n2);
	while(1)
	{

	}
	return 0;
}

