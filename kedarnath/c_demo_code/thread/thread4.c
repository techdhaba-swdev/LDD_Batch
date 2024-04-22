#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *print_message(char *ptr);

int main(int argc,char** argv){

	pthread_t thread1;
	int* status=(int*)malloc(sizeof(int));
	printf("creating a new thread\n");
	pthread_create(&thread1,NULL,print_message,argv[1]);
	printf("created thread is %d\n",thread1);
	pthread_join(thread1,&status);
	printf("thread1 is returns %d and status is %ld\n",thread1,*status);
	//free(&status);
	return 0;

}

void *print_message(char *ptr){

	int status=0;
	printf("message is %s\n",ptr);
	pthread_exit(&status);



}

