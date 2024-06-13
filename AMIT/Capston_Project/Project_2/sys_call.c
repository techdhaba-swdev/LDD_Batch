#include<linux/kernel.h>
#include<sys/syscall.h>
#include<stdio.h>

int main()
{
	long i=syscall(462);
	if(i==0)
	{
		printf("system call hitted sucessfully!\n");
	}
	else
	{
		printf("system call unsucessfull..\n");
	}
	return 0;
}
