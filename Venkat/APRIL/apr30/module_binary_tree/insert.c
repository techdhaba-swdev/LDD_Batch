#include "insert.h"
#include <stdlib.h>
#include <stddef.h>
// Function to insert data into the binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data); // Create new node if tree is empty

    if (data < root->data) root->left = insert(root->left, data); // Insert in left subtree for smaller values
    else if (data > root->data) root->right = insert(root->right, data); // Insert in right subtree for larger values

    return root; // Return the (potentially modified) root node
}
