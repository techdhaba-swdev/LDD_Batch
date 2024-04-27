#include "queue.h"    // Include the header file that contains the structure definition and function prototypes
#include <stdio.h>    // Include standard I/O functions

int main() {
    Queue queue;        // Declare a queue
    initializeQueue(&queue);  // Initialize the queue

    // Enqueue elements into the queue
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    // Display the queue
    displayQueue(&queue);

    // Dequeue an element from the queue
    printf("Dequeued element: %d\n", dequeue(&queue));

    // Display the queue after dequeue
    displayQueue(&queue);

    return 0;
}
