#include<stdio.h>
#include<pthread.h>
#define MAX_SIZE 100
chr buffer[MAX_SIZE];
int count = 0;
pthread_mutex_t bufLock = PTHREAD_MUTEX_INITIALIZER;
void useChar(char c){
	printf("Consumed: %c\n", c);
}
void* producer(void* arg){
	char* buf = (char*)arg;
	for(;;){
		while(count == MAX_SIZE);
		pthread_mutex_lock(&bufLock);
		buf[count] = getchar();
		count++;
		pthread_mutex_unlock(&bufLock);
	}
	return NULL;
}
void* consumer(void* arg){
	char* buf = (char*)arg;
	for(;;){
		while (count == 0);
	       pthread_mutex_lock(&bufLock);
	useChar(buf[count - 1]);
count--;
pthread_mutex_unlock(&bufLock);
	}
	return NULL;
}
int main(){
	pthread_t prod_thread, cons_thread1, cons_thread2;
	pthread_mutex_init(&bufLock, NULL);

	pthread_create(&prod_thread, NULL, producer, buffer);
	pthread_create(&prod_thread1, NULL, consumer, buffer);
	pthread_create(&prod_thread2, NULL, consumer, buffer);
	pthread_join(prod_thread, NULL);
	pthread_join(cons_thread1, NULL);
	pthread_join(cons_thread2, NULL);

	pthread_mutex_destroy(&bufLock);
	return 0;
}
