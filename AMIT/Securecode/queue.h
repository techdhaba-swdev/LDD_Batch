#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 100

struct Queue {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
};

void initializeQueue(struct Queue* queue);
bool isEmpty(struct Queue* queue);
bool isFull(struct Queue* queue);
void enqueue(struct Queue* queue, int value);
int dequeue(struct Queue* queue);
int peek(struct Queue* queue);

#endif
