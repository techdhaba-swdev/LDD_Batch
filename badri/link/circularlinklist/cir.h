#ifndef LINKLIST_H
#define LINKLIST_H
typedef struct Node {
	int data;
	struct Node* next;
} Node;
Node* createNode(int data);
void insertNode(struct Node** headRef , int data);
void printList(struct Node* head);
int sumList(Node* head);
#endif
