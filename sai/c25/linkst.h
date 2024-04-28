#ifndef LINKLIST_H_
#define LINKLIST_H_
struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int data);
void insertatbeg(struct Node** headref,int data);
void printList(struct Node* head);
#endif
