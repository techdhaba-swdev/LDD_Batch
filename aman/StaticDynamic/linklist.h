#ifndef LINKLIST_H
#define LINKLIST_H
struct Node{
	int data;
	struct Node* next;
};
void insertNode(struct Node**headRef, int newData);
int sumList(struct Node* head);
#endif
