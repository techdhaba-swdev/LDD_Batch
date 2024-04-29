#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
 
int a = 10;
int b = 20;
void handler()
{
	int mul = a * b;
	printf("multiplication of two numbers%d \n",mul);
}
void handler2()
{
	printf("program terminated\n");
	exit (0);

}

int main(){
	signal(SIGINT , handler);
	signal(SIGTSTP , handler2);
	printf("enter ctrl+c to get mul value & ctrl+z to stop\n");
	while(1);
	}



