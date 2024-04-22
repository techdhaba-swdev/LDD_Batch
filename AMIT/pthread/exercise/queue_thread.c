#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10

typedef struct {
    int buffer[BUFFER_SIZE];
    size_t count;
    size_t max_size;
    pthread_mutex_t mtx;
    pthread_cond_t cv_not_full;
    pthread_cond_t cv_not_empty;
} ThreadSafeQueue;

void init_queue(ThreadSafeQueue* queue, size_t size) {
    queue->count = 0;
    queue->max_size = size;
    pthread_mutex_init(&queue->mtx, NULL);
    pthread_cond_init(&queue->cv_not_full, NULL);
    pthread_cond_init(&queue->cv_not_empty, NULL);
}

void push(ThreadSafeQueue* queue, int item) {
    pthread_mutex_lock(&queue->mtx);
    while (queue->count == queue->max_size) {
        pthread_cond_wait(&queue->cv_not_full, &queue->mtx);
    }
    queue->buffer[queue->count++] = item;
    pthread_cond_signal(&queue->cv_not_empty);
    pthread_mutex_unlock(&queue->mtx);
}

int pop(ThreadSafeQueue* queue) {
    pthread_mutex_lock(&queue->mtx);
    while (queue->count == 0) {
        pthread_cond_wait(&queue->cv_not_empty, &queue->mtx);
    }
    int item = queue->buffer[--queue->count];
    pthread_cond_signal(&queue->cv_not_full);
    pthread_mutex_unlock(&queue->mtx);
    return item;
}

void* producer(void* arg) {
    ThreadSafeQueue* queue = (ThreadSafeQueue*)arg;
    while (1) {
        int item = rand() % 100; // Generate a random number
        push(queue, item);
        usleep(500000); // Simulate work (500 ms)
    }
    return NULL;
}

void* consumer(void* arg) {
    ThreadSafeQueue* queue = (ThreadSafeQueue*)arg;
    while (1) {
        int item = pop(queue);
        printf("Consumed: %d\n", item);
        usleep(300000); // Simulate processing (300 ms)
    }
    return NULL;
}

int main() {
    const size_t buffer_size = 10;
    ThreadSafeQueue queue;
    init_queue(&queue, buffer_size);

    pthread_t prod_thread, cons_thread;
    pthread_create(&prod_thread, NULL, producer, &queue);
    pthread_create(&cons_thread, NULL, consumer, &queue);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    return 0;
}
