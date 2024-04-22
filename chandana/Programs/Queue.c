#include <stdio.h>
#include <stdlib.h>

#define size 10

typedef struct{
	int id;
	char name[50];
}Customer;

typedef struct {
	Customer data[size];
	int front,rear;
}Queue;

void initQueue(Queue *q){
	q->front=-1;
	q->rear=-1;
}
int isFull(Queue *q){
	return (q-> rear == size-1);
}
int isEmpty(Queue *q) {
	return (q->front == -1 || q->front > q-> rear);
}
void enqueue(Queue *q,Customer c) {
	if(isFull(q)) {
		printf("Queue is full.cannot enqueue.\n");
		return;
	}
	if(q->front == -1) {
		q->front=0;
	}
	q-> rear++;
	q->data[q->rear]=c;
}
Customer dequeue(Queue *q){
	if(isEmpty(q)){
		printf("Queue is empty.cannot dequeue.\n");
		Customer emptyCustomer={-1," "};
		return emptyCustomer;
	}
	Customer dequeuedCustomer=q->data[q->front];
	q->front++;

	if(q->front>q->rear){
		q->front=0;
		q->rear=-1;
	}

	return dequeuedCustomer;
}

void displayQueue(Queue *q){
	if(isEmpty(q)){
		printf("Queue is empty.\n");
		return;
	}
	printf("Queue:\n");
	for(int i=q->front;i<=q->rear;i++) {
		printf("Customer ID :%d,Name:%s\n",q->data[i].id,q->data[i].name);
	}
}
int main() {
	Queue q;
	initQueue(&q);

	Customer c1={1,"john"};
	Customer c2={2,"Alice"};
	Customer c3={3,"Bob"};

	enqueue(&q,c1);
	enqueue(&q,c2);
	enqueue(&q,c3);

	displayQueue(&q);

	Customer servedCustomer=dequeue(&q);
	printf("Serving Customer : %s \n",servedCustomer.name);

	displayQueue(&q);
	return 0;
}
