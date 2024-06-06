#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct Node {
	int data;
	struct Node *next;
}Node;

void addlinklist(Node **head,int data);
int sum(Node *head);

#endif
