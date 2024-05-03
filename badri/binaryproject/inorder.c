#include "node.h"
// Function to perform in-order traversal (left, root, right)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {//checks If root is not NULL
        inOrderTraversal(root->left);// Traverse left subtree
        printf("%d ", root->data);// Print root data
        inOrderTraversal(root->right);// Traverse right subtree
    }
}
