//header guards which protects multiple inclusion of same header files and ensure compile only once
#ifndef QUEUE_H_
#define QUEUE_H_
struct node; //declaerd structure node
void enqueue(int data); //declaration of enqueue API
int dequeue(); //declaration of dequeue API
void print(void); //declaration of print API
#endif
