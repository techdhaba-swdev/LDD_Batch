#include <pthread.h>
#include<stdio.h>
#define MAX_SIZE 5

pthread_mutex_t lock;

pthread_cond_t notFull, notEmpty;

int count;

void *producer(char* buf) {

  for(;;) {



	if(count == MAX_SIZE) break;
        pthread_mutex_lock(&lock);
	//pthread_cond_wait(&notFull, &lock);

	buf[count]=getchar();

	count++;

	//pthread_cond_signal(&notEmpty);

        pthread_mutex_unlock(&lock);
        
        }
}       
void consumer(char* buf) {

 for(;;)
 {

	

	if(count == -1) break;
	putchar(buf[count]);
	count--;

 }
}
int main() {

char buffer[MAX_SIZE];

pthread_t p;

count = 0;

pthread_mutex_init(&lock,NULL);

pthread_cond_init(&notFull,NULL);

pthread_cond_init(&notEmpty,NULL);

pthread_create(&p, NULL, (void*)producer, buffer);

consumer(buffer);

return 0;

}
