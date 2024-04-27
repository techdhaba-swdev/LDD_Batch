#include <stdio.h>
#include "queue.h"

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("Queue elements: ");
    displayQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    printf("Queue elements after dequeue: ");
    displayQueue(queue);

    deleteQueue(queue);

    return 0;
}
