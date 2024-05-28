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

// Function to initialize the queue
void initQueue(ThreadSafeQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
    pthread_mutex_init(&queue->mutex, NULL);
}

// Function to check if the queue is empty
int isEmpty(ThreadSafeQueue *queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(ThreadSafeQueue *queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

// Function to enqueue an item into the queue
void enqueue(ThreadSafeQueue *queue, int item) {
    pthread_mutex_lock(&queue->mutex);

    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        pthread_mutex_unlock(&queue->mutex);
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }

    queue->items[queue->rear] = item;

    pthread_mutex_unlock(&queue->mutex);
}

// Function to dequeue an item from the queue
int dequeue(ThreadSafeQueue *queue) {
    pthread_mutex_lock(&queue->mutex);

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        pthread_mutex_unlock(&queue->mutex);
        return -1; // Return -1 indicating queue underflow
    }

    int item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }

    pthread_mutex_unlock(&queue->mutex);
    return item;
}

// Function to display the contents of the queue
void display(ThreadSafeQueue *queue) {
    pthread_mutex_lock(&queue->mutex);

    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        pthread_mutex_unlock(&queue->mutex);
        return;
    }

    printf("Queue contents: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("%d\n", queue->items[i]);

    pthread_mutex_unlock(&queue->mutex);
}

// Function to destroy the queue and free resources
void destroyQueue(ThreadSafeQueue *queue) {
    pthread_mutex_destroy(&queue->mutex);
}

int main() {
    ThreadSafeQueue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    display(&queue);

    int item = dequeue(&queue);
    printf("Dequeued item: %d\n", item);
    display(&queue);

    destroyQueue(&queue);

    return 0;
}


