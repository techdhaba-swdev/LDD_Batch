#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));   //allowcating memory for new node
    newNode->data = data;                                             //set the data of the new node to provided value
    newNode->left = NULL;                                            //initialize left pointer to NULL indicate left node not exist yet
    newNode->right = NULL;                                           // similarly initialize right pointer to NULL
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {  // Base case: Empty tree, create a new root node
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);  // Insert in left subtree for smaller values
    } else if (data > root->data) {
        root->right = insert(root->right, data);  // Insert in right subtree for larger values
    } else { // Handle duplicates (optional: can modify to overwrite or reject)
        // printf("Duplicate value: %d\n", data);
    }

    return root;  // Return the (potentially modified) root node
}

// Function to perform in-order traversal of the binary tree
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);  // Visit left subtree
        printf("%d ", root->data);  // Visit current node
        inOrder(root->right); // Visit right subtree
    }
}

// Function to calculate the sum of all nodes in the binary tree
int sumOfNodes(struct Node* root) {
    if (root == NULL)                          //checking if tree is empty if empty then return sum zero
        return 0;
    return (root->data + sumOfNodes(root->left) + sumOfNodes(root->right));     //here we recursivly calling sum function and returnig sum
}




