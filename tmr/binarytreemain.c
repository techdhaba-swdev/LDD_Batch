#include <stdio.h>
#include "binarytree.h"

int main() {
    struct Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(7);
    root->right->right = createNode(9);

    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");

    if (isBinarySearchTree(root)) {
        printf("The binary tree is a binary search tree.\n");
    } else {
        printf("The binary tree is not a binary search tree.\n");
    }

    printf("Height of the binary tree: %d\n", findHeight(root));

    int min, max;
    findMinMaxValues(root, &min, &max);
    printf("Minimum value in the binary tree: %d\n", min);
    printf("Maximum value in the binary tree: %d\n", max);

    return 0;
}
