#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void sigsegv(int sig){
	
		printf("\nsegmentation error msg genrated by mayur");
		exit(EXIT_SUCCESS);
	

}


int main()
{
signal(SIGSEGV,sigsegv);

int *ptr;
*ptr=20;
return 0;
}
