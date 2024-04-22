#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
    pthread_mutex_t mutex;
} ThreadSafeQueue;

void initializeQueue(ThreadSafeQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
    pthread_mutex_init(&(queue->mutex), NULL);
}

int isQueueEmpty(ThreadSafeQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isQueueFull(ThreadSafeQueue* queue) {
    return ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front);
}

void enqueue(ThreadSafeQueue* queue, int value) {
    pthread_mutex_lock(&(queue->mutex));
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        pthread_mutex_unlock(&(queue->mutex));
        return;
    }
    if (isQueueEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }
    queue->items[queue->rear] = value;
    printf("Enqueued: %d\n", value);
    pthread_mutex_unlock(&(queue->mutex));
}

int dequeue(ThreadSafeQueue* queue) {
    pthread_mutex_lock(&(queue->mutex));
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        pthread_mutex_unlock(&(queue->mutex));
        return -1; // Return a default value indicating failure
    }
    int value = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }
    printf("Dequeued: %d\n", value);
    pthread_mutex_unlock(&(queue->mutex));
    return value;
}

int main() {
    ThreadSafeQueue queue;
    initializeQueue(&queue);

    // Example usage:
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    return 0;
}

