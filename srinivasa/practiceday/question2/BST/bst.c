// including all the required headerfile
#include <stdio.h>
#include<stdbool.h>
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
// this function is used to print the tree in preorder transversal
// in preorder transversal first we print data than left and last right values
void preordertraversal(struct Node *root)
{
	if (root != NULL) {
		printf("%d ", root->data);
		preordertraversal(root->left);
		preordertraversal(root->right);
	}
}
// this function is used to print the tree in postordertransversal
// in inorder transversal first we print left values and  middle and data
void postordertraversal(struct Node *root)
{
        if (root != NULL) {
                preordertraversal(root->left);
                preordertraversal(root->right);
		printf("%d ", root->data);
        }
}
//this function is used to check the tree is binary or not
bool isbst(struct Node* root)
{     
        //creating a node pointer prev by assigning NULL
	struct Node* prev = NULL;
	// calling the function to cheking the bst or not
	return isbstutil(root, prev);
}
// fuction to find the tree is following the the bst properties or not
bool isbstutil(struct Node* root, struct Node* prev)
{
	if (root != NULL)  // checking the root is NULL
	{       // RECURSIVLY CHECKING THE FUNCTION IS FOLLOWING THE BST PROPERITES
		if (!isbstutil(root->left, prev))
		{
			return false;
		}
		if (prev != NULL && root->data <=prev->data)
		{
			return false;
		}
		prev = root;
		return isbstutil(root->right, prev);
	}
	return true;
}
//function to know the height of the tree
int height(struct Node *root)
{ 
	if (root == NULL)
	{
	    return 0; //if the root equal to NULL return 0
	}
	else {  
	        // checking the left sub trees 
		int leftheight = height(root->left);
		//cheking the right sub tress
		int rightheight = height(root->right);
		//returning the height of the tree
		if (leftheight > rightheight)
		{
			return leftheight + 1;
		}
		else 
			return rightheight + 1;
	}
}
// Function to find the minimum and maximum values in a binary tree
void find_min_max(struct Node* node, int* min_val, int* max_val) {
  if (node == NULL) {
    return;
  }

  // Update minimum if current node's data is smaller
  *min_val = (*min_val < node->data) ? (*min_val) : node->data;

  // Update maximum if current node's data is greater
  *max_val = (*max_val > node->data) ? (*max_val) : node->data;
  // recurcively checking the min and max values of the tree
  find_min_max(node->left, min_val, max_val);
  find_min_max(node->right, min_val, max_val);
}
