#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5 // Size of the buffer

pthread_mutex_t mutex;
pthread_cond_t bufferFull, bufferEmpty;
int buffer[BUFFER_SIZE];
int itemCount = 0; // Number of items in the buffer

void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100; // Generate a random number as an item
        pthread_mutex_lock(&mutex);
        while (itemCount == BUFFER_SIZE) {
            pthread_cond_wait(&bufferEmpty, &mutex); // Wait if buffer is full
        }
        buffer[itemCount++] = item;
        printf("Produced: %d\n", item);
        pthread_cond_signal(&bufferFull); // Signal that buffer is not empty
        pthread_mutex_unlock(&mutex);
        usleep(1000000); // Sleep for 1 second (for demonstration purposes)
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item;
    while (1) {
        pthread_mutex_lock(&mutex);
        while (itemCount == 0) {
            pthread_cond_wait(&bufferFull, &mutex); // Wait if buffer is empty
        }
        item = buffer[--itemCount];
        printf("Consumed: %d\n", item);
        pthread_cond_signal(&bufferEmpty); // Signal that buffer is not full
        pthread_mutex_unlock(&mutex);
        usleep(1000000); // Sleep for 1 second (for demonstration purposes)
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producerThread, consumerThread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&bufferFull, NULL);
    pthread_cond_init(&bufferEmpty, NULL);

    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&bufferFull);
    pthread_cond_destroy(&bufferEmpty);

    return 0;
}
