#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct {
    int *array;
    int front, rear;
    unsigned int capacity;
} Queue;

// Function to initialize the queue
Queue* initialize() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->array = (int *)malloc(MAX_SIZE * sizeof(int));
    queue->capacity = MAX_SIZE;
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
bool isFull(Queue *queue) {
    return (queue->rear == queue->capacity - 1);
}

// Function to check if the queue is empty
bool isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->array[++queue->rear] = value;
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
}

int main() {
    // Initialize the queue
    Queue *queue = initialize();

    // Start the clock
    clock_t start = clock();

    // Enqueue elements into the queue
    for (int i = 1; i <= MAX_SIZE; ++i) {
        enqueue(queue, i);
    }

    // Dequeue and print elements from the queue
    printf("Dequeued elements from the queue:\n");
    while (!isEmpty(queue)) {
        printf("%d\n", dequeue(queue));
    }

    // Stop the clock
    clock_t end = clock();

    // Calculate the elapsed time
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the execution time
    printf("Time taken: %f seconds\n", time_taken);

    // Free memory allocated for the queue array and the queue structure
    free(queue->array);
    free(queue);

    return 0;
}
