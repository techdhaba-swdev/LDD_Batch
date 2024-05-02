#include<stdio.h>
#include<signal.h>
int a = 10 , b = 5;
void signal_handle1(int signum)
{
	printf(" adding two numbers :%d", a + b);
}
void signal_handle2(int signum)
{
	printf("signal end ");
}
int main()
{

	signal(SIGINT, signal_handle1);
	signal(SIGTSTP, signal_handle2);
	while(1);
	return 0;
}

