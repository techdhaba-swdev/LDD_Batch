#include "node.h"
// Function to perform pre-order traversal (root, left, right)
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {//checks weather noot is null or not
        printf("%d ", root->data);// Print root data
        preOrderTraversal(root->left);// Traverse left subtree
        preOrderTraversal(root->right);// Traverse right subtree
    }
}
