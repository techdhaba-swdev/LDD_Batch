#ifndef LKADD_H
#define LKADD_H

 struct Node{
	int data;
	struct Node* next; //next:ptr to the next node in the list
};

void insertnode(struct Node** head, int new_data);
void printlist(struct Node* node);

#endif

