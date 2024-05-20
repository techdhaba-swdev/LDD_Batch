#include <stdio.h>
#include <pthread.h>

#define MAX  5
pthread_mutex_t bufLock;
int count;

void producer(char* buf) {
   for(;;) {
	while(count == MAX);
	pthread_mutex_lock(&bufLock);
	buf[count] = getchar();
	count++;
	pthread_mutex_unlock(&bufLock);
   }
}
void consumer(char* buf) {
   for(;;) {
	while(count == 0);
	pthread_mutex_lock(&bufLock);
	putchar(buf[count-1]);
	count--;
	pthread_mutex_unlock(&bufLock);
   }
}

int main() {
   char buffer[MAX];
   pthread_t t1;
   int count;
   pthread_mutex_init(&bufLock, NULL);
   pthread_create(&t1, NULL, (void*)producer, &buffer);  
   consumer(buffer);
   return 0;
}
