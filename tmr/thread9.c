#include <stdio.h>

#include <pthread.h>

#define MAX_SIZE 5

pthread_mutex_t lock;

pthread_cond_t not Full. notEmpty;

int count;

void producer(char* buf) (

for(::) {

pthreads_mutex_lock(lock);

while(count == MAX_SIZE)

buf[count] = getChar():

count++;

pthread_cond_signal(notEmpty):

pthread_mutex_unlock(lock);

}

}

pthread_cond_wait(notFull, lock);

void consumer(char* buf) {


for(;;) {

pthread_mutex_lock(lock);

while(count == 0) I

pthread_cond_wait(notEmpty, lock

useChar(buf[count-1]);

count-;

pthread_cond_signal(notFull);

pthread_mutex_unlock(lock);
}
}
int main() {

char buffer[MAX_SIZE];

pthread_ tp:

count = 0;

pthread_mutex_init(&bufLock);

pthread_cond_init(&notFull):

pthread_cond_init(&notEmpty):

pthread_create(&p, NULL, (void*)producer, &buffer);

consume(&buffer);

return 0;
}
