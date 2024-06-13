#include<linux/kernel.h>
#include<sys/syscall.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	long int i=syscall(463);
	if(i==0){
		printf("Syscall successfull\n");
	}else{
		printf("Syscall unsuccessfull\n");
	}
	return 0;
}
