#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#define SIZE 10
int buffer[SIZE];
int in=0,out=0,items=0;
pthread_mutex_t mutex;
pthread_cond_t full;
pthread_cond_t empty;
void *producer(void* arg)
{
	int item;
	while(1)
	{
		item=rand() % 100;
		pthread_mutex_lock(&mutex);
		while(items==SIZE)
		{
			printf("Producer waiting (buffer full)\n");
			pthread_cond_wait(&empty,&mutex);
		}
		buffer[in]=item;
		in=(in+1)%(SIZE);
		items++;
		printf("Producer produces %d\n",item);
		pthread_cond_signal(&full);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}
void *consumer(void *arg)
{
	int item;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		while(items==0)
		{
			printf("Consumer waiting (buffer empty)\n");
			pthread_cond_wait(&full,&mutex);
		}
		item=buffer[out];
		out=(out+1)%(SIZE);
		items--;
		printf("Consumer consumed %d\n",item);
		pthread_cond_signal(&empty);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	return NULL;
}
int main(int argc,char* argv)
{
	int num_producers=2;
	int num_consumers=3;
	srand(time(NULL));
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&full,NULL);
	pthread_cond_init(&empty,NULL);
	pthread_t producers[num_producers],consumers[num_consumers];
	for(int i=0;i<num_producers;i++)
	{
		pthread_create(&producers[i],NULL,producer,NULL);
	}
	for(int i=0;i<num_consumers;i++)
	{
		pthread_create(&consumers[i],NULL,consumer,NULL);
	}
	for(int i=0;i<num_producers;i++)
        {
                pthread_join(producers[i],NULL);
        }
	for(int i=0;i<num_consumers;i++)
        {
                pthread_join(consumers[i],NULL);
        }
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&full);
	pthread_cond_destroy(&empty);
	return 0;
}



