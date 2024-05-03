#include "binarytree.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Pre-order traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// In-order traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Post-order traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Helper function for checking if a binary tree is a binary search tree
int isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) {
        return 1;
    }
    if (root->data < min || root->data > max) {
        return 0;
    }
    return isBSTUtil(root->left, min, root->data - 1) && isBSTUtil(root->right, root->data + 1, max);
}

// Check if a binary tree is a binary search tree (BST)
int isBinarySearchTree(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Helper function to find the height of a binary tree
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Find the height of a binary tree
int findHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

// Helper function to find the minimum and maximum values in a binary tree
void findMinMaxValuesUtil(struct Node* root, int* min, int* max) {
    if (root == NULL) {
        return;
    }
    if (root->data < *min) {
        *min = root->data;
    }
    if (root->data > *max) {
        *max = root->data;
    }
    findMinMaxValuesUtil(root->left, min, max);
    findMinMaxValuesUtil(root->right, min, max);
}

// Find the minimum and maximum values in a binary tree
void findMinMaxValues(struct Node* root, int* min, int* max) {
    *min = INT_MAX;
    *max = INT_MIN;
    findMinMaxValuesUtil(root, min, max);
}
