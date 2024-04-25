#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>  // Include boolean data type

#define MAX_SIZE 100   // Maximum size of the queue

// Define a structure for the queue
typedef struct {
    int items[MAX_SIZE];  // Array to store the queue items
    int front, rear;      // Indices for front and rear of the queue
} Queue;

// Function prototypes
void initializeQueue(Queue *queue);          // Initialize the queue
bool isFull(Queue *queue);                    // Check if the queue is full
bool isEmpty(Queue *queue);                   // Check if the queue is empty
void enqueue(Queue *queue, int value);       // Enqueue an element into the queue
int dequeue(Queue *queue);                   // Dequeue an element from the queue
void displayQueue(Queue *queue);             // Display the queue elements

#endif
