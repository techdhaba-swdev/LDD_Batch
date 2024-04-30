#include "freetree.h"
#include <stdlib.h>

// recursively free memory used by the tree nodes
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left); // Free left subtree
    freeTree(root->right); // Free right subtree
    free(root); // Free current node
}
