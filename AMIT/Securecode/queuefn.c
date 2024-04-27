#include <stdio.h>
#include <stdbool.h>
#include"queue.h"

// Initialize an empty queue
void initializeQueue(struct Queue* queue) {
    queue->front = queue->rear = -1;
}

// Check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Check if the queue is full
bool isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

// Enqueue (add) an element to the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow! Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->data[queue->rear] = value;
}

// Dequeue (remove) an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow! Cannot dequeue.\n");
        return -1; // Or any sentinel value
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    return value;
}

// Peek at the front element without removing it
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1; // Or any sentinel value
    }
    return queue->data[queue->front];
}

