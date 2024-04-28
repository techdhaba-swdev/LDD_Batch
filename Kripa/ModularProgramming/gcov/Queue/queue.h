#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

// Structure representing a node in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure representing a queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function declarations
Queue* createQueue();
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
bool isEmpty(Queue* queue);

#endif

