#include<stdio.h>
#include<pthread.h>
void printMsg(char *msg)
{
	printf("%s\n",msg);
}
int main(int argc,char** argv)
{
	pthread_t thrdID;
	printf("Creating a new thread\n");
	pthread_create(&thrdID,NULL,(void*)printMsg,argv[1]);
	printf("creating thread %ld\n",thrdID);
	pthread_join(thrdID,NULL);
	return 0;
}

