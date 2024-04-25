#include "queue.h"    // Include the header file that contains the structure definition and function prototypes

// Initialize the queue
void initializeQueue(Queue *queue) {
    queue->front = -1;  // Initialize front index to -1 (empty queue)
    queue->rear = -1;   // Initialize rear index to -1 (empty queue)
}

// Check if the queue is full
bool isFull(Queue *queue) {
    // Queue is full if front is 0 and rear is at the end, or if rear is just before front
    return (queue->rear == MAX_SIZE - 1 && queue->front == 0) || (queue->rear == queue->front - 1);
}

// Check if the queue is empty
bool isEmpty(Queue *queue) {
    // Queue is empty if front index is -1
    return queue->front == -1;
}

// Enqueue an element into the queue
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");  // Print an error message if queue is full
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;  // If queue is empty, set front to 0
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;  // Circular increment of rear index
    queue->items[queue->rear] = value;  // Add value to the rear of the queue
}

// Dequeue an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");  // Print an error message if queue is empty
        return -1;
    }
    int value = queue->items[queue->front];  // Get the front element
    if (queue->front == queue->rear) {
        // Reset front and rear to -1 if this is the last element in the queue
        queue->front = -1;
        queue->rear = -1;
    } else {
        // Circular increment of front index
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return value;  // Return the dequeued value
}

// Display the queue elements
void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");  // Print an error message if queue is empty
        return;
    }
    printf("Queue: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);  // Print each element from front to rear
        i = (i + 1) % MAX_SIZE;  // Circular increment of index
    }
    printf("%d\n", queue->items[i]);  // Print the last element
}
