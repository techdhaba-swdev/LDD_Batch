#ifndef BST_H
#define BST_H

#include "node.h"

struct Node* insert(struct Node* root, int data);
struct Node* deleteNode(struct Node* root, int data);
struct Node* search(struct Node* root, int data);
void inOrderTraversal(struct Node* root);

#endif /* BST_H */
