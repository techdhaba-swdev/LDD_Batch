#include <stdio.h>
#include <stdbool.h>
#include"queue.h"

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Front element: %d\n", peek(&myQueue));
    printf("Dequeued element: %d\n", dequeue(&myQueue));
    printf("Front element after dequeue: %d\n", peek(&myQueue));

    return 0;
}
