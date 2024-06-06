#include "binary_tree.h"
#include<stdio.h>



// Function to insert a node into the binary tree
struct Node* insert(struct Node* root, int data) {
    // Base case: Empty tree, create a new root node
    if (root == NULL) {
        return createNode(data);
    }

    // If the data is less than the root node, insert into the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If the data is greater than the root node, insert into the right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // Handle duplicates (optional)
    else {
        // printf("Duplicate value: %d\n", data);
    }

    // Return the (potentially modified) root node
    return root;
}

// Function to perform in-order traversal of the binary tree
void inOrder(struct Node* root) {
    // Base case: If the root is not NULL
    if (root != NULL) {
        // Visit left subtree
        inOrder(root->left);
        // Visit current node
        printf("%d ", root->data);
        // Visit right subtree
        inOrder(root->right);
    }
}

