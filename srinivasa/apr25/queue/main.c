#include <stdio.h>  // including the header files
#include "queue.h"

int main() {
    Queue* queue = createQueue(5);  // creating a structure
   // performing some queue operations
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    displayQueue(queue);

    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    dequeue(queue);
    displayQueue(queue);  // display the queue

    destroyQueue(queue);  // dealocating the memory

    return 0;    // executing the programe with zero errors
}
