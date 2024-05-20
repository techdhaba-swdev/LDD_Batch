#include "queue.h"//This line includes the queue.h header file, which contains function prototypes and type definitions related to the queue.
#include <stdio.h>//This line includes the standard input/output header file, providing functions for input and output operations.

int main() {//This line declares the beginning of the main function, which serves as the entry point of the program.
    Queue* queue = createQueue();//This line declares a pointer to a Queue structure and initializes it by calling the createQueue() function.It creates a new queue and assigns its address to the queue pointer.
//These lines enqueue four integers (10, 20, 30, and 40) into the queue pointed to by queue.Each enqueue() call inserts a value into the queue.

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
//This line dequeues an element from the queue pointed to by queue.It calls the dequeue() function and prints the dequeued value using printf()
    printf("%d dequeued from queue.\n", dequeue(queue));
    printf("%d dequeued from queue.\n", dequeue(queue));

    return 0;//This line indicates the successful completion of the main function and the program.It returns zero to the operating system, indicating that the program executed without errors.
}
