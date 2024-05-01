#include "newnode.h"//including newnode.h headerfile which contain newnode function

struct Node *createnode(int data) // Structure for creating newnode
{
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));//dynamically allocating memory for newnode using malloc
	newnode->data = data; // pointing and storing data to newnode
	newnode->Left = NULL;// new node pointing to left node
	newnode->Right = NULL;// newnode pointing to right node

	return newnode;// it returns newnode to the function
}

