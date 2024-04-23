#ifndef circular.h
#define circular.h
struct Node{
	int data;
	struct Node *next;
};
struct Node* insertEnd (struct Node *last, int data);
void printList(struct Node *last);
#endif

