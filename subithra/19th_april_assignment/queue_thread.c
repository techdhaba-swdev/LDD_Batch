#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front, rear;
    pthread_mutex_t mutex;
} ThreadSafeQueue;

// Function to initialize the queue
void initQueue(ThreadSafeQueue *queue) {
    queue->front = 0;
    queue->rear = -1;
    pthread_mutex_init(&queue->mutex, NULL);
}

// Function to check if the queue is empty
int isEmpty(ThreadSafeQueue *queue) {
    return (queue->rear < queue->front);
}

// Function to check if the queue is full
int isFull(ThreadSafeQueue *queue) {
    return (queue->rear - queue->front + 1 >= MAX_QUEUE_SIZE);
}

// Function to enqueue an item into the queue
void enqueue(ThreadSafeQueue *queue, int item) {
    pthread_mutex_lock(&queue->mutex);
    if (!isFull(queue)) {
        queue->items[++queue->rear] = item;
    }
    pthread_mutex_unlock(&queue->mutex);
}

// Function to dequeue an item from the queue
int dequeue(ThreadSafeQueue *queue) {
    int item = -1;
    pthread_mutex_lock(&queue->mutex);
    if (!isEmpty(queue)) {
        item = queue->items[queue->front++];
    }
    pthread_mutex_unlock(&queue->mutex);
    return item;
}

// Function to print the contents of the queue (for demonstration purposes)
void printQueue(ThreadSafeQueue *queue) {
    pthread_mutex_lock(&queue->mutex);
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
    pthread_mutex_unlock(&queue->mutex);
}

int main() {
    ThreadSafeQueue queue;
    initQueue(&queue);

    // Example usage
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    printQueue(&queue);

    int item = dequeue(&queue);
    printf("Dequeued item: %d\n", item);
    printQueue(&queue);

    return 0;
}
