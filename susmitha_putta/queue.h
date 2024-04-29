#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 100

// Struct representing a queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function prototypes
void initialize(Queue *queue);
int isEmpty(Queue *queue);
int isFull(Queue *queue);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);

#endif
