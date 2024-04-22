#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

struct Node
{
	int data;
	struct Node* next;
};

struct Node* createCircularLinkedList();
void append(struct Node**, int );
void display(struct Node*);

#endif

