#include <stdio.h>
#include "queue.h"

int main() {
    // Create a queue
    Queue* queue = createQueue();

    // Enqueue elements to the queue
    enqueue(queue, 5);
    enqueue(queue, 3);
    enqueue(queue, 9);
    enqueue(queue, 7);

    // Dequeue and print elements from the queue
    printf("Dequeued elements: ");
    while (!isEmpty(queue)) {
        printf("%d ", dequeue(queue));
    }
    printf("\n");

    return 0;
}

