#include<stdio.h>
#include"pthread.h"
void *printMessage(void *threadID){
	long tid;
	tid = (long)threadID;
	printf("Thread #%ld: hello, litheef!\n",tid);
	pthread_exit(NULL);
}
