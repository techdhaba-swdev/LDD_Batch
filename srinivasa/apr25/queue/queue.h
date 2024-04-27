#ifndef QUEUE_H
#define QUEUE_H
// defining the structure
typedef struct {
    int capacity;
    int size;
    int front;
    int rear;
    int *array;
} Queue;
// function prototypes
Queue* createQueue(int capacity);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
void enqueue(Queue* queue, int item);
int dequeue(Queue* queue);
int front(Queue* queue);
int rear(Queue* queue);
void displayQueue(Queue* queue);
void destroyQueue(Queue* queue);

#endif
