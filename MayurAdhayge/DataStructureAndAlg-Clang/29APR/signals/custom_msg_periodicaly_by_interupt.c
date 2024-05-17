#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
void sigint(int sig){
	 if (sig==SIGINT)
	 {
		printf("\nctrl+c interupt genrated \n");
		exit(EXIT_SUCCESS);
	 }
	else if(sig==SIGTSTP)
	{
		printf("\nperiodic data ");
	}
	

}




int main()
{
signal(SIGINT,sigint);
signal(SIGTSTP,sigint);
pid_t pid=getpid();
while(1){
kill(getpid(),SIGTSTP);
}
return 0;
}
