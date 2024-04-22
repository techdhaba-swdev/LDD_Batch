#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0; // Number of items in the buffer
int in = 0;    // Index where the producer will place the next item
int out = 0;   // Index where the consumer will pick up the next item

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t buffer_empty = PTHREAD_COND_INITIALIZER;

// Function to produce an item and add it to the buffer
void* producer(void* arg) {
    while (1) {
        int item = rand() % 100; // Generate a random number

        pthread_mutex_lock(&mutex);

        // Wait while the buffer is full
        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&buffer_full, &mutex);
        }

        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        count++;

        // Signal that the buffer is not empty
        pthread_cond_signal(&buffer_empty);

        pthread_mutex_unlock(&mutex);

        usleep(rand() % 1000000); // Sleep for a random time
    }
    return NULL;
}

// Function to consume an item from the buffer
void* consumer(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        // Wait while the buffer is empty
        while (count == 0) {
            pthread_cond_wait(&buffer_empty, &mutex);
        }

        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        count--;

        // Signal that the buffer is not full
        pthread_cond_signal(&buffer_full);

        pthread_mutex_unlock(&mutex);

        usleep(rand() % 1000000); // Sleep for a random time
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}


