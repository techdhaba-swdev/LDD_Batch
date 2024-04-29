#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM 5

void sigusr1_handler(int sig)
{
	printf("thread %ld received SIGUSR1\n",pthread_self() );
}
void *thread_function(void *arg)
{
	signal(SIGUSR1 , sigusr1_handler);
	while(1)
	{
		sleep(1);
	}
	return NULL;
}

int main()
{
	

	
	pthread_t threads[NUM];
	int i;
	for (i=0 ; i<NUM ; i++)
	{
		pthread_create(&threads[i] , NULL , thread_function , NULL);
	}
	for(i=0 ; i<NUM ; i++)
	{
		pthread_kill(threads[i] , SIGUSR1);
	}
	for (i = 0 ; i<NUM ; i++)
	{
		pthread_join(threads[i] , NULL);
	}
	
	return 0;
}
