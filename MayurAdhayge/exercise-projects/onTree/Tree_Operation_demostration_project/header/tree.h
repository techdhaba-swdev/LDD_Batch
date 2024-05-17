#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


// Function declarations
struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
struct Node* deleteNode(struct Node* root, int data);
struct Node* search(struct Node* root, int data);
void inorderTraversal(struct Node* root);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
bool isBST(struct Node* root);
int maxDepth(struct Node* root);
int minValue(struct Node* root);
int maxValue(struct Node* root);

#endif 
