#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
// creating a queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (!queue->array) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return queue;
}
// check the queue is full 
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}
// checking the queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}
// function for enqueue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}
//function for dequeue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}
// function for front
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->array[queue->front];
}
//function for queue
int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->array[queue->rear];
}
//function to display the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i;
    for (i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}
// function to deallocate the memory this is secure coding
void destroyQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}
