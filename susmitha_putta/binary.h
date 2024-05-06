#ifndef BINARY_H
#define BINARY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Node structure for the Binary Search Tree (BST)
typedef struct Node Node;


// Function prototypes
Node* createNode(int data);
Node* insert(Node* root, int data);
Node* delete(Node* root, int data);
Node* minValueNode(Node* node);
Node* search(Node* root, int data);
void inOrderTraversal(Node* root);
void preOrderTraversal(Node* root);
void postOrderTraversal(Node* root);
bool isBST(Node* root);
int height(Node* root);
void findMinMax(Node* root, int* min, int* max);

#endif
