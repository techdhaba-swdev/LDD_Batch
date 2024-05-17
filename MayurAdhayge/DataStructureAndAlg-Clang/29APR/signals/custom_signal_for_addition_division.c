#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
int num1=10;
int num2=20;
void sigint_and_sigtstp_arthmatics(int sig){
	if (sig==SIGINT)
	{
		printf("\nctrl+c interupt genrated for addition:\n\t\t\t\t %d+%d=%d\n",num1,num2,num1+num2);
		exit(EXIT_SUCCESS);
	}
	else if (sig==SIGTSTP)
        {
                printf("\nctrl+z interupt genrated for multiplication:\n\t\t\t\t %d+%d=%d\n",num1,num2,num1*num2);
                exit(EXIT_SUCCESS);
        }

}


int main()
{
signal(SIGINT,sigint_and_sigtstp_arthmatics);
signal(SIGTSTP,sigint_and_sigtstp_arthmatics);
//printf("1.For addition press ctrl+c");
//printf("2.For multiplication press ctrl+z");
while(1){
printf("10");
}
return 0;
}
