#include "bs.h"
#include<stdio.h>
#include<stdlib.h>

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode != NULL) { //check if memory allocation was successful
        newNode->data = data;//initialize node data
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}


// Function to insert a new node into the BST
struct node* insert(struct node* root, int data) {
    if (root == NULL) { //if tree is empty create a new node and return
        return createNode(data);
    }

    if (data < root->data) {  //insert into left subtree if data is less than current node
        root->left = insert(root->left, data);
    } else if (data > root->data) { //insert into right subtree if data is greater than current nod
        root->right = insert(root->right, data);
    }

    return root;
}
//Function to find the node with the minimum value in a subtree
struct node* minValueNode(struct node* node){
	struct node* current = node;
	while(current && current ->left != NULL){
		current = current ->left;
	}
	return current;
}
// Function to delete for a node with the given data in the BST
struct node* deleteNode(struct node* root, int data){
	if(root == NULL){
		return root;
	}
	if(data < root -> data){
		root->left=deleteNode(root->left,data);
	}
	else if(data > root->data){
		root->right=deleteNode(root->right,data);
	}
	else {
		if(root->left == NULL){
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			struct node* temp = root->left;
			free(root);
			return temp;
	}
	struct node* temp = minValueNode(root->right);
	root->data = temp->data;
	root->right=deleteNode(root->right,temp->data);
	}
	return root;}

// Function to search for a node with the given data in the BST
int search(struct node* root, int data) {
    if (root == NULL || root->data) { //if tree is empty or node with data is found return
        return root != NULL; //retun 1 if root is not null , 0 otherwise
    }

    if (data < root ->data) { //search left subtree if data is less than current nodes data
        return search(root->left,data);

    }
    else  {
        return search(root->right, data);
    }
}

// Function to perform an in-order traversal of the BST
void inorderTraversal(struct node* root) {
    if (root == NULL) {//if tree is empty return
	    return;
    }
        inorderTraversal(root->left);//transvers left tree
        printf("%d ", root->data);
        inorderTraversal(root->right);//transverse right tree
} 
