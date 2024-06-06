#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "node.h"

// Function to insert a node into the binary tree
struct Node* insert(struct Node* root, int data);

// Function to perform in-order traversal of the binary tree
void inOrder(struct Node* root);

#endif

