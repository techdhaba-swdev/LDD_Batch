#include<stdio.h>
#include<pthread.h>
int counter =0;

void *thread_fuc(void)
{
	printf("thread = %d",pthread_self());
	counter++;
	printf("counter :%d",counter);
}
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void main()
{
	pthread_t threadid[20];
	for (int i = 0 ; i < 20 ; i++)
	{
		pthread_create(&threadid[i], NULL, thread_fuc, NULL);
	}
	for (int i = 0; i < 20; i++){
		pthread_join(threadid[i], NULL);
	}
	printf("couner : %d", counter);
}

