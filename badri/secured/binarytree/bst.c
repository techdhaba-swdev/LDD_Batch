#include "bst.h"
#include <stdio.h>
#include <stdlib.h> // Added for error handling

// Function to insert a new node into the tree while maintaining the BST property
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        // If tree is empty, create a new node and return it as the new root
        return createNode(data);
    }
    if (data < root->data) {
        // If data is less than current node's data, recursively insert into left subtree
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        // If data is greater than current node's data, recursively insert into right subtree
        root->right = insert(root->right, data);
    }
    // If data is equal to current node's data, do nothing (BST doesn't allow duplicates)
    return root;
}

// Function to search for a node with the given data in the tree
int search(struct node* root, int data) {
    if (root == NULL) {
        // If tree is empty or node not found, return 0
        return 0;
    }
    if (root->data == data) {
        // If current node's data matches the search data, return 1
        return 1;
    } else if (data < root->data) {
        // If search data is less than current node's data, search in left subtree
        return search(root->left, data);
    } else {
        // If search data is greater than current node's data, search in right subtree
        return search(root->right, data);
    }
}

// Function to perform an in-order traversal of the tree (prints node values)
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        // Traverse left subtree
        inorderTraversal(root->left);
        // Print current node's data
        printf("%d ", root->data);
        // Traverse right subtree
        inorderTraversal(root->right);
    }
}
