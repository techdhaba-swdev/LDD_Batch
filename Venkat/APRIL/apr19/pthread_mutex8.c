#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // Needed for sleep function
#include <time.h> // Needed for time function

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int items = 0;

pthread_mutex_t mutex;
pthread_cond_t full;
pthread_cond_t empty;

void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100; // Generate a random item
        
        pthread_mutex_lock(&mutex); // Lock the mutex
        
        while (items == BUFFER_SIZE) { // Wait if buffer is full
            printf("Producer waiting (buffer full)\n");
            pthread_cond_wait(&empty, &mutex);
        }

        buffer[in] = item; // Add item to buffer
        in = (in + 1) % BUFFER_SIZE;
        items++;
        printf("Producer produced: %d\n", item);
        
        pthread_cond_signal(&full); // Signal consumer
        pthread_mutex_unlock(&mutex); // Unlock the mutex
    }
    return NULL;
}

void *consumer(void *arg) {
    int item;
    while (1) {
        pthread_mutex_lock(&mutex); // Lock the mutex
        
        while (items == 0) { // Wait if buffer is empty
            printf("Consumer waiting (buffer empty)\n");
            pthread_cond_wait(&full, &mutex);
        }

        item = buffer[out]; // Remove item from buffer
        out = (out + 1) % BUFFER_SIZE;
        items--;
        printf("Consumer consumed: %d\n", item);
        
        pthread_cond_signal(&empty); // Signal producer
        pthread_mutex_unlock(&mutex); // Unlock the mutex
        
        // Simulate processing
        sleep(1);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    int num_producers = 2;
    int num_consumers = 3;
    srand(time(NULL)); // Seed random number generator

    pthread_mutex_init(&mutex, NULL); // Initialize mutex
    pthread_cond_init(&full, NULL); // Initialize condition variables
    pthread_cond_init(&empty, NULL);

    pthread_t producers[num_producers], consumers[num_consumers];

    // Create producer threads
    for (int i = 0; i < num_producers; i++) {
        pthread_create(&producers[i], NULL, producer, NULL);
    }

    // Create consumer threads
    for (int i = 0; i < num_consumers; i++) {
        pthread_create(&consumers[i], NULL, consumer, NULL);
    }

    // Join all threads
    for (int i = 0; i < num_producers; i++) {
        pthread_join(producers[i], NULL);
    }
    for (int i = 0; i < num_consumers; i++) {
        pthread_join(consumers[i], NULL);
    }

    // Destroy mutex and condition variables
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);

    return 0;
}
