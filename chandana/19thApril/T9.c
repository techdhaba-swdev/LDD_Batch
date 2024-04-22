#include <stdio.h>
#include <pthread.h>

#define MAX_SIZE 5

pthread_mutex_t lock;
pthread_cond_t notFull, notEmpty;
char buffer[MAX_SIZE];
int count = 0;

void *producer(void *arg) {
    for (;;) {
        pthread_mutex_lock(&lock);
        while (count == MAX_SIZE)
            pthread_cond_wait(&notFull, &lock);
        char item = getChar();
        buffer[count] = item;
        count++;
        pthread_cond_signal(&notEmpty);
        pthread_mutex_unlock(&lock);
    }
printf("entered");
}

void *consumer(void *arg) {
    for (;;) {
        pthread_mutex_lock(&lock);
        while (count == 0)
            pthread_cond_wait(&notEmpty, &lock);
        char item = buffer[count - 1];
        count--;
        useChar(item);
        pthread_cond_signal(&notFull);
        pthread_mutex_unlock(&lock);
    }
printf("hello");
}


int main() {
    pthread_t producerThread, consumerThread;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&notFull, NULL);
    pthread_cond_init(&notEmpty, NULL);

    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&notFull);
    pthread_cond_destroy(&notEmpty);

    return 0;
}
