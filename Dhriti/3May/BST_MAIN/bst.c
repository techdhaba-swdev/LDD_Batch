#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "bst.h"

// create a new node 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for the new node
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE); //SECURED: BY HANDLING MEMORY ALLOCATION FALIURE
    }
    
    newNode->data = data;  // Assign the data to the new node
    newNode->left = NULL;  // Initialize the left subtree pointer to NULL
    newNode->right = NULL; // Initialize the right subtree pointer to NULL
    return newNode;        // Return the pointer to the new node
}

// insert a new node 
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);  // If the root is NULL, create a new node and return it
    }
    if (data < root->data) {
        root->left = insert(root->left, data);   // If the data is less than the root's data, insert into the left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data); // If the data is greater than the root's data, insert into the right subtree
    }
    return root; 
}

//  delete a node 
struct Node* deletion(struct Node* root, int data) {
    if (root == NULL) {
        return root;  // If the root is NULL, return NULL
    }
    if (data < root->data) {
        root->left = deletion(root->left, data);   // If the data is less than the root's data, delete from the left subtree
    } else if (data > root->data) {
        root->right = deletion(root->right, data); // If the data is greater than the root's data, delete from the right subtree
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);        // If the node to be deleted has only right child, replace it with its right child
            return temp;       // and return the right child
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);        // If the node to be deleted has only left child, replace it with its left child
            return temp;       // and return the left child
        }
        struct Node* temp = Minimum(root->right);  // If the node to be deleted has both children
        root->data = temp->data;                   // find the minimum value in its right subtree
        root->right = deletion(root->right, temp->data);  // Replace the node's data with the minimum value
    }
    return root;  // Return the root node
}

//  find the minimum value node in a binary tree
struct Node* Minimum(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;  // Traverse to the leftmost node to find the minimum value
    }
    return current;  // Return the pointer to the minimum value node
}



void preorder(struct Node* root) //visits the root then in leftsubtree and finally its rightsubtree 
{
	if(root !=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct Node* root) // visit leftsubtree then in right and finally the current node
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

//  find the minimum and maximum values in a binary tree
void MinMax(struct Node* node, int *min, int *max) {
    if (node == NULL) {
        return;  // If the node is NULL, return
    }

    MinMax(node->left, min, max);  //  find min and max values in the left subtree
    
    if (node->data < *min) {
        *min = node->data;  // Update min value if current node's data is smaller
    }
    if (node->data > *max) {
        *max = node->data;  // Update max value if current node's data is larger
    }

    MinMax(node->right, min, max);  // find min and max values in the right subtree
}

//  perform in-order traversal of a binary tree
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);   // check the left subtree
        printf("%d ", root->data);      // Print the data of the current node
        inOrderTraversal(root->right);  // check the right subtree
    }
}

//  calculate the height of a binary tree
int height(struct Node* node) {
    if (node == NULL) {
        return 0;  // If the node is NULL, return 0
    }
    int leftHeight = height(node->left);   //  calculate the height of the left subtree
    int rightHeight = height(node->right); //  calculate the height of the right subtree
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);  // if leftheight is greater than rightheight it  returns leftheight+1
								       // otherwise rightheight+1
								       // this process goes on continusly until all nodes in the binary tree has been visited and their heights have been calculated.
}
