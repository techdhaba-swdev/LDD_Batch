#include<stdio.h>
#include<unistd.h>
#include<sys/syscall.h>

#define NR_custom_syscall 333 //match the number in syscall table
int main(){
	long int ret = syscall(NR_custom_syscall);
	if(ret==0){
		printf("custom syscall executed successfully.\n');
	}else{
		printf("custom syscall failed.\n");
	}
	return 0;
}_
