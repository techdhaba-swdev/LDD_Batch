#include<stdio.h>
#include<pthread.h>

void printmsg(char* msg)
{
	int status=0;
	printf("%s\n",msg);
	pthread_exit(&status);
}

int main(int argc,char** argv)
{
	pthread_t thrdlD;
	int* status=(int*)malloc(sizeof(int));

	printf("creating the new thread\n");
	pthread_create(&thrdlD , NULL,(void*)printmsg,argv[1]);
	printf("created thread %d\n",thrdlD);
	pthread_join(thrdlD,&status);
	printf("Thread %d exited with status %d \n",thrdlD,*status);

	return 0;
}

