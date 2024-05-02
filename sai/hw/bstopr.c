#include "bstopr.h"
#include<stdlib.h>

struct Node* createNode(char data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL)
	{
		printf("Memory allocated failed\n");
		return ;
	}
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct Node* Inoder(struct Node* root)
{
	if(root != NULL)
	{
		Inorder(root->left);
		printf("%c",root);
		Inorder(root->right);
	}
}


