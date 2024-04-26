
#include <stdio.h>
#include "queue.h"

int main() {
    Queue queue;
    initialize(&queue); // Initialize the queue

    // Enqueuing elements into the queue
    enqueue(&queue, 10);
    enqueue(&queue, 20);

    // Dequeuing an element from the queue
    int dequeuedValue = dequeue(&queue);
    printf("Dequeued value: %d\n", dequeuedValue);

    return 0;
}
