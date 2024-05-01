#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
 
  
struct Node;
 
struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
void inOrder(struct Node* root);
int sumOfNodes(struct Node* root);

#endif

