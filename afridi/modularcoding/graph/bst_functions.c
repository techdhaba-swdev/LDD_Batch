#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to perform in-order traversal of BST
void inOrderTraversal(const Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to perform pre-order traversal of BST
void preOrderTraversal(const Node* root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal of BST
void postOrderTraversal(const Node* root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a value in BST
Node* search(const Node* root, int data) {
    const Node* current = root;
    while (current) {
        if (data == current->data)
            return (Node*)current;
        else if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return NULL;
}

// Function to check if a binary tree is a binary search tree
int isBST(const Node* root, int min, int max) {
    if (!root) return 1;
    if (root->data < min || root->data > max) return 0;
    return isBST(root->left, min, root->data - 1) && isBST(root->right, root->data + 1, max);
}

// Function to find the height of a binary tree
int height(const Node* root) {
    if (!root) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Function to find the minimum value in a binary tree
int findMin(const Node* root) {
    if (!root) return INT_MAX;
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    return (root->data < leftMin && root->data < rightMin) ? root->data : (leftMin < rightMin) ? leftMin : rightMin;
}

// Function to find the maximum value in a binary tree
int findMax(const Node* root) {
    if (!root) return INT_MIN;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    return (root->data > leftMax && root->data > rightMax) ? root->data : (leftMax > rightMax) ? leftMax : rightMax;
}

// Function to free memory allocated for BST
void freeBST(Node* root) {
    if (root) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}
