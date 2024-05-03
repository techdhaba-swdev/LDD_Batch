#include "node.h"
// Function to perform post-order traversal (left, right, root)
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);// Traverse left subtree
        postOrderTraversal(root->right);// Traverse right subtree
        printf("%d ", root->data);// Print root data
    }
}
