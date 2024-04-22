#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
struct Node {
	int data;
	struct Node* next;
};
struct Node* createNode(int data);
void insertAtEnd(struct Node** head_ref, int data);
void displaylist(struct Node* head);
#endif
