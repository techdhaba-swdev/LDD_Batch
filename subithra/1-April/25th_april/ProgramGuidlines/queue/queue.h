#ifndef QUEUE_H //checks if the given identifier has not been defined before.QUEUE_H is an identifier unique to this header file, used to prevent multiple inclusions of the same header.
#define QUEUE_H//#define is used to define the identifier QUEUE_H.This prevents the header file contents from being included more than once in the same translation unit.


typedef struct Queue Queue;//This line defines a new type Queue, which is a structure.It allows us to use Queue as a type without revealing its implementation details.


Queue* createQueue();//This declares a function prototype for createQueue().It returns a pointer to Queue.
int isEmpty(Queue* queue);//This declares a function prototype for isEmpty().It takes a pointer to Queue as an argument and returns an integer.
int isFull(Queue* queue);//This declares a function prototype for isFull().It takes a pointer to Queue as an argument and returns an integer.
void enqueue(Queue* queue, int value);//This declares a function prototype for enqueue().It takes a pointer to Queue and an integer value as arguments and returns void (nothing).
int dequeue(Queue* queue);//This declares a function prototype for dequeue().It takes a pointer to Queue as an argument and returns an integer.It's expected to return the value dequeued from the queue.

#endif//#endif marks the end of the conditional inclusion started by #ifndef.