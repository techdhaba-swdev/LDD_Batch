#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t buff;

void  *addfuc (void *arg)
{
		int sum =0;
	for(int i = 0 ; i<10 ; i++)
	{
		pthread_mutex_lock(&buff);
		sum = sum + i;
		printf("value of sum %d\n" , sum);
	
	pthread_mutex_unlock(&buff);
	}
	pthread_exit(NULL);
}

void *subfnc (void *arg)
{
		int sub ;
	pthread_mutex_lock (&buff);
	for(int i = 10 ; i>=5 ; i--)
	{
		
		sub = i - 4;
		printf("%d\n",sub);
			}
	pthread_mutex_unlock(&buff);
	pthread_exit(NULL);
}

int main()
{
		clock_t start = clock();
		pthread_t thread1 , thread2;
		
		pthread_mutex_lock(&buff);
		pthread_create(&thread1 , NULL ,  addfuc  , NULL);
		printf("threads1 created successfully\n");
		
		pthread_create(&thread2 , NULL , subfnc  , NULL);
		printf("thread2 creted successfully \n");
		pthread_mutex_unlock(&buff);
		pthread_join(thread1 , NULL);
		pthread_join(thread2,NULL);
		
		clock_t end = clock();
		int time_used = ((double)(end - start) / CLOCKS_PER_SEC);
		printf("time used by program %d\n",time_used);
	}
