#ifndef CLINKLIST_H
#define CLINKLIST_H

struct Node {
	int data;
	struct Node* next;
};

typedef struct Node Node;

Node* newNode(int data);
void insertNode(Node** head, int data);
void inputs(Node* head_f);
int sum(Node* head_f);

#endif
