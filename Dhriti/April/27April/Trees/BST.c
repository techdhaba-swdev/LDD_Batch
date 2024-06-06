#include<stdio.h>
#include<stdlib.h>
#include "BST.h"


struct node* createnode(int data) {
          
	struct node* newnode = (struct node*)malloc(sizeof(struct node));	//Allocating memory for the new node
        if(newnode != NULL) { 
	newnode->data = data; //Initialize data
          
	newnode->left = NULL;
	newnode->right = NULL;	//setting both the nodes to null
	}
	return newnode;
}

struct node* insert(struct node* root, int data) {

	if (root == NULL) {
		return createnode(data);
	}
	if(data < root->data) {
		root->left = insert(root->left,data);  //if data is less than currentnode insert into left subtree
	}

	else if (data > root->data) {
		root->right = insert(root->right,data);  //if data is greater than currentnode insert into right subtree
	}

	return root;
}

int search(struct node* root, int data) {
        if(root == NULL) {
	return 0;
	//if root is empty return 0
	}

	if(root->data == data) {
		return 1;
	}

	else if (root->data >data) { //if data is less than current node search in left subtree
		return (search (root->left,data));
	}

	else if (root->data < data) {
		return (search (root->right,data)); //if data is greater than current node search in right search tree
	}

}

void inorderTraversal(struct node* root) {
	if(root != NULL) {

		inorderTraversal(root->left);	//treverse leftsubtree
                                            
		printf("Current node: %d", root->data);
		
		inorderTraversal(root->right); //traverse rightsubtree

	}
}
