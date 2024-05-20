#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
    pthread_mutex_t mutex;
} Queue;

void initialize_queue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
    pthread_mutex_init(&queue->mutex, NULL);
}

int is_empty(Queue *queue) {
    return queue->front == -1;
}

int is_full(Queue *queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

void enqueue(Queue *queue, int item) {
    pthread_mutex_lock(&queue->mutex);
    if (is_full(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (is_empty(queue)) {
            queue->front = 0;
            queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
        }
        queue->items[queue->rear] = item;
        printf("Enqueued: %d\n", item);
    }
    pthread_mutex_unlock(&queue->mutex);
}

int dequeue(Queue *queue) {
    pthread_mutex_lock(&queue->mutex);
    int item = -1;
    if (is_empty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        item = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
        }
        printf("Dequeued: %d\n", item);
    }
    pthread_mutex_unlock(&queue->mutex);
    return item;
}

int main() {
    Queue queue;
    initialize_queue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    dequeue(&queue);
    dequeue(&queue);

    enqueue(&queue, 40);
    enqueue(&queue, 50);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    return 0;
}
