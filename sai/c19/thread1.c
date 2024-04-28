#include<stdio.h>
#include<pthread.h>

#define MAX_SIZE 5
pthread_mutex_t lock;
pthread_cond_t notFull,notEmpty;
int count;

void producer(char* buf)
{
	pthread_mutex_lock(lock);
	while(count == MAX_SIZE){
		pthread_cond_wait(notFull,lock);
	buf[count] = getchar();
	count++;
	pthread_cond_signal(notEmpty);
	pthread_mutex_unlock(lock);
  }
}

