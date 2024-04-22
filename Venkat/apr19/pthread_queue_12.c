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

void initializeQueue(ThreadSafeQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
    pthread_mutex_init(&queue->mutex, NULL);
}

int isQueueFull(ThreadSafeQueue *queue) {
    return (queue->rear == MAX_QUEUE_SIZE - 1);
}

int isQueueEmpty(ThreadSafeQueue *queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(ThreadSafeQueue *queue, int item) {
    pthread_mutex_lock(&queue->mutex);
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
        printf("Enqueued: %d\n", item);
    }
    pthread_mutex_unlock(&queue->mutex);
}

int dequeue(ThreadSafeQueue *queue) {
    pthread_mutex_lock(&queue->mutex);
    int item = -1;
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        item = queue->items[queue->front];
        queue->front++;
        printf("Dequeued: %d\n", item);
    }
    pthread_mutex_unlock(&queue->mutex);
    return item;
}

int main() {
    ThreadSafeQueue queue;
    initializeQueue(&queue);

    // Enqueue some items
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    // Dequeue items
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    // Try to dequeue from an empty queue
    dequeue(&queue);

    return 0;
}
