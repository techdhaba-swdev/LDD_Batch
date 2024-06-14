#include"node.h"
struct node* createNode(int data){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode==NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
