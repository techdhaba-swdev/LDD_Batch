#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>


void printMsg(char* msg){
	int status =0;
 printf("%s\n", msg);
 pthread_exit(status);
}

int main(int argc, char** argv) {

	pthread_t thrdID;

	int status = (int*)malloc(sizeof(int));

	printf("Creating a new thread\n");

	pthread_create(&thrdID, NULL, (void*)printMsg, argv[1]);

	printf("Creatrd thread %d\n", thrdID);

	pthread_join(thrdID, &status);

	printf("thread %d exited with status %d\n",thrdID, status);



	return 0;
}

