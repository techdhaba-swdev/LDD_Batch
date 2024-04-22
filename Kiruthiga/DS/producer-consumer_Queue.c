#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 10

// Define the structure for a queue
typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear, count;
    pthread_mutex_t lock;
    pthread_cond_t not_empty, not_full;
} Queue;

// Initialize the queue
void initializeQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    pthread_mutex_init(&queue->lock, NULL);
    pthread_cond_init(&queue->not_empty, NULL);
    pthread_cond_init(&queue->not_full, NULL);
}

// Function to enqueue data into the queue
void enqueue(Queue* queue, int value) {
    pthread_mutex_lock(&queue->lock);
    while (queue->count >= MAX_QUEUE_SIZE) {
        pthread_cond_wait(&queue->not_full, &queue->lock);
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->data[queue->rear] = value;
    queue->count++;
    pthread_cond_signal(&queue->not_empty);
    pthread_mutex_unlock(&queue->lock);
}

// Function to dequeue data from the queue
int dequeue(Queue* queue) {
    pthread_mutex_lock(&queue->lock);
    while (queue->count <= 0) {
        pthread_cond_wait(&queue->not_empty, &queue->lock);
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->count--;
    pthread_cond_signal(&queue->not_full);
    pthread_mutex_unlock(&queue->lock);
    return value;
}

// Producer thread function
void* producer(void* arg) {
    Queue* queue = (Queue*)arg;
    for (int i = 0; i < 20; i++) {
        printf("Producing item %d\n", i);
        enqueue(queue, i);
    }
    return NULL;
}

// Consumer thread function
void* consumer(void* arg) {
    Queue* queue = (Queue*)arg;
    for (int i = 0; i < 20; i++) {
        int item = dequeue(queue);
        printf("Consuming item %d\n", item);
    }
    return NULL;
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, &queue);
    pthread_create(&consumer_thread, NULL, consumer, &queue);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&queue.lock);
    pthread_cond_destroy(&queue.not_empty);
    pthread_cond_destroy(&queue.not_full);

    return 0;
}



