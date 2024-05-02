#include<stdio.h>
#include<stdlib.h>
#include<binary.h>

//function to create a new node
struct node *createnode(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
//function to insert a node into binary tree
struct node *insert(struct node *root, int data)
{
	if (root == NULL)
	{
		return createnode(data);
	}
	if (data < root->data)
	{
		root->left = insert(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = insert(root->right, data);
	}
	else 
	{
		printf("duplicate vale : %d\n",data);
	}
	return root;
}
//function to perform in order trasversal
void inorder(struct node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}
