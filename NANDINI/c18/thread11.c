#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int index_in = 0;
int index_out = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t buffer_not_empty = PTHREAD_COND_INITIALIZER;

void* producer(void* arg) {
    while (1) {
        int item = rand() % 100; // Generate random number
        pthread_mutex_lock(&mutex);
        while ((index_in + 1) % BUFFER_SIZE == index_out) {
            pthread_cond_wait(&buffer_not_full, &mutex);
        }
        buffer[index_in] = item;
        index_in = (index_in + 1) % BUFFER_SIZE;
        printf("Produced %d. Buffer: [", item);
        for (int i = 0; i < BUFFER_SIZE; ++i) {
            printf("%d ", buffer[i]);
        }
        printf("]\n");
        pthread_cond_signal(&buffer_not_empty);
        pthread_mutex_unlock(&mutex);
        sleep(1); // Simulate production time
    }
    return NULL;
}

void* consumer(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (index_in == index_out) {
            pthread_cond_wait(&buffer_not_empty, &mutex);
        }
        int item = buffer[index_out];
        index_out = (index_out + 1) % BUFFER_SIZE;
        printf("Consumed %d. Buffer: [", item);
        for (int i = 0; i < BUFFER_SIZE; ++i) {
            printf("%d ", buffer[i]);
        }
        printf("]\n");
        pthread_cond_signal(&buffer_not_full);
        pthread_mutex_unlock(&mutex);
        sleep(1); // Simulate consumption time
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;
    srand(time(NULL));

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}

