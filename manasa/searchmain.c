#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"

// Function to create a new tree node
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build a sample binary tree
TreeNode* buildTree() {
    TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);
    return root;
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    TreeNode* root = buildTree();

    start = clock();
    int result = isBST(root);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    if (result)
        printf("The tree is a Binary Search Tree.\n");
    else
        printf("The tree is not a Binary Search Tree.\n");
    
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
