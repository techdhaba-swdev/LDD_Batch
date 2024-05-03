#include "dbt.h"
#include<stdio.h>
#include<stdlib.h>

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) { //check if memory allocation was successful
        newNode->data = data;//initialize node data
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}


// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
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
struct Node* minValue(struct Node* root){
	struct Node* current = root;
	while(current && current ->left != NULL){
		current = current ->left;
	}
	return current;
}
// Function to delete for a node with the given data in the BST
struct Node* deletenode(struct Node* root, int data){
	if(root == NULL){
		return root;
	}
	if(data < root -> data){
		root->left=deletenode(root->left,data);
	}
	else if(data > root->data){
		root->right=deletenode(root->right,data);
	}
	else {
		if(root->left == NULL){
			struct Node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			struct Node* temp = root->left;
			free(root);
			return temp;
	}
	struct Node* temp = minValue(root->right);
	root->data = temp->data;
	root->right=deletenode(root->right,temp->data);
	}
	return root;}

// Function to search for a node with the given data in the BST
struct Node*  search(struct Node* root, int num) {
    if (root == NULL ) { //if tree is empty or node with data is found return
        return root; //retun 1 if root is not null , 0 otherwise
    }

    if (num < root ->data) { //search left subtree if data is less than current nodes data
        return search(root->left,num);

    }
    else  {
        return search(root->right, num);
    }
}

// Function to perform an in-order traversal of the BST
void inorder(struct Node* root) {
    if (root == NULL) {//if tree is empty return
	    return;
    }
        inorder(root->left);//transvers left tree
        printf("%d ", root->data);
        inorder(root->right);//transverse right tree
    }
