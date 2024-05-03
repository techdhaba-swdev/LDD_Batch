// including all the required headerfile
#include <stdio.h>
#include "bst.h"
#include<stdlib.h>
//function to create a new node
struct Node* createNode(int data) {
   // creating a new node dinamically
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// function to insert the nodes to the tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {   // checking the root is NULL
        return createNode(data); // if the root NULL creating a newnode
    }
    
    if (data < root->data) {  //if data is greater than the root data
        root->left = insert(root->left, data);  //asign the data to left child of the root
    } else if (data > root->data) { // if data is less than the root data
        root->right = insert(root->right, data); //asign the data to left child of the root
    }
    
    return root;     // return the root 
}
//this fucntion is used to find the node with the minimun value in a given sub tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {  // looping untile find the last left node
        current = current->left;
    }
    return current;
}
// this function is used to delete a node in the bst
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {  // checking the root is null
        return root;     //returing the root 
    } 
    // if the key is less than the root data
    if (key < root->data) {
	    //recursivey enter the deletenode function with value root->left
        root->left = deleteNode(root->left, key);
	// if the key is grater than the root data
    } else if (key > root->data) {
	    //recursivey enter the deletenode function with value root->right
        root->right = deleteNode(root->right, key);
    } else {
	    //checking the root left is equal to NULL
        if (root->left == NULL) {
		// assigin the root->right value to temp
            struct Node* temp = root->right;
	    //free the root 
            free(root);
            return temp;// returing temp value
        } //checking the root right is NULL
	  else if (root->right == NULL) {      
            //assigining the temp value as root->left
            struct Node* temp = root->left;
            free(root);
            return temp; // returning the temp
        }
        // assiging temp equal to minvaluenode function which tells the least left node of the sub tree
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
	// now deleting the right side subtree of the bst
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
// this function is used to search an element in the bst
struct Node* search(struct Node* root, int key) {
	//if root = NULL, root data is a key then return the root
    if (root == NULL || root->data == key) {
        return root;
    }
    
    if (root->data < key) {
	    //if the key is grater than the root data 
	    //search recursivly right subtree elements as root as root right 
        return search(root->right, key);  // returing the element
    }
    //search recursivly right subtree elements as root as root right
    return search(root->left, key);
}
// this function is used to print the tree in inordertransversal
// in inorder transversal first we print left values than middle and last right values 
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
	// calling recursivly and printing the data
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
