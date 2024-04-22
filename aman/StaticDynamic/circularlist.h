#ifndef CIRCULARLIST_H
#define  CIRCULARLIST_H
typedef struct Node  {
	int data;
	struct Node* next;
} Node;

Node* createNode(int data);
Node* insertNode(Node* head, int data);
void displayList(Node* head);
int sumAllNodes(Node* head);
#endif
