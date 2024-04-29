#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
 
void sigsegv_handler(int signum){
	printf("segmentation fault \n");
}
int main(){
	signal(SIGSEGV,sigsegv_handler);
	int arr[5];
	arr[10]=10;
	printf("not comig to this line\n");
	return 0;
}
