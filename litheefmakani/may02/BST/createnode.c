#include"createnode.h"

//we are deifining the function 
struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));//dynamically allocated memory 
        newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
