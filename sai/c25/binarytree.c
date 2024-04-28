#include "binarytree.h"
#include<stdlib.h>
#include<stdio.h>


struct node* createNode(int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
        if(newNode != NULL)
	{
           
	
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	}
	return newNode;
}

struct node* insert(struct node* root,int data)
{
         if(root == NULL)
	 {
	     return createNode(data);
	 }	     
        if(data <root-> data)
	{
		root->left = insert(root->left,data);
	}
	else if(data > root->data)
	{
             root->right = insert(root->right,data);
	}
	return root;
}


int search (struct node* root,int data)
{
	if(root == NULL)
	{
		return 0;
	}
	if(root->data == data)
	{
		return 1;
	}
	else if(root->data >data)
	{
	   return search(root->left,data);
	}
	else 
	{
		return search(root->right,data);
	}
}

void inorderTraversal(struct node* root)
{
	if(root != NULL)
	{
		inorderTraversal(root->left);
		printf("%d->",root->data);
         	inorderTraversal(root->right);

	}
}



