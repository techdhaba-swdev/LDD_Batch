#include "queue.h"
#include<stdio.h>
// Function to initialize the queue
void initialize(Queue *queue) {
    queue->front = -1; // Initialize front to -1 to indicate an empty queue
    queue->rear = -1;  // Initialize rear to -1 to indicate an empty queue
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(Queue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int dequeuedItem = queue->items[queue->front];
    if (queue->front == queue->rear) { // If there's only one element in the queue
        initialize(queue); // Reset the queue
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return dequeuedItem;
}
