#include "queue.h" // Include the header file for the queue

#include <stdio.h> // Include standard input/output functions
#include <stdlib.h> // Include standard library functions

#define MAX_SIZE 100 // Define the maximum size of the queue

// Define the structure for the queue
struct Queue {
    int items[MAX_SIZE]; // Array to store queue elements
    int front; // Index of the front element
    int rear; // Index of the rear element
};

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue)); // Allocate memory for the queue structure
    queue->front = -1; // Initialize front index
    queue->rear = -1; // Initialize rear index
    return queue; // Return the newly created queue
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    if (queue->rear == -1) // If rear index is -1, the queue is empty
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    if (queue->rear == MAX_SIZE - 1) // If rear index is equal to the maximum size minus 1, the queue is full
        return 1;
    else
        return 0;
}

// Function to enqueue an element into the queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) { // Check if the queue is full
        printf("Queue is full!\n"); // Print an error message if the queue is full
    } else {
        if (queue->front == -1) // If the front index is -1, set it to 0
            queue->front = 0;
        queue->rear++; // Increment the rear index
        queue->items[queue->rear] = value; // Insert the value at the rear index
        printf("%d enqueued to queue.\n", value); // Print a message indicating successful enqueue operation
    }
}

// Function to dequeue an element from the queue
int dequeue(Queue* queue) {
    int item; // Variable to store the dequeued item
    if (isEmpty(queue)) { // Check if the queue is empty
        printf("Queue is empty!\n"); // Print an error message if the queue is empty
        return -1; // Return -1 to indicate failure
    } else {
        item = queue->items[queue->front]; // Get the item at the front index
        queue->front++; // Increment the front index
        if (queue->front > queue->rear) { // If front index surpasses rear index, reset indices
            queue->front = queue->rear = -1;
        }
        return item; // Return the dequeued item
    }
}