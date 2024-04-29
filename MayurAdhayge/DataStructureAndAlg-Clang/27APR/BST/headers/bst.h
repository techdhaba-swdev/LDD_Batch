#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>

struct node;

struct node* createNode(int data);

struct node* insert(struct node* root, int data);

int search(struct node* root, int data);

void inorderTraversal(struct node* root);

#endif
