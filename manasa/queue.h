#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue();
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int isEmpty(Queue* queue);
void displayQueue(Queue* queue);
void deleteQueue(Queue* queue);

#endif /* QUEUE_H */
