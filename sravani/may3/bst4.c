#include <stdio.h>
#include<stdlib.h>
#include "bst4.h"

// Function to create a new node
Node* newNode(int data) {
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

// Function to check if a binary tree is a BST
int is_bst(Node* node, int min_val, int max_val) {
  if (node == NULL) {
    return 1;
  }

  if (node->data < min_val || node->data > max_val) {
    return 0;
  }

  return is_bst(node->left, min_val, node->data) &&
         is_bst(node->right, node->data, max_val);
}

// Function to find the height of a binary tree
int height(Node* node) {
  if (node == NULL) { 
	  return 0;
  }

  int left_height = height(node->left);
  int right_height = height(node->right);

  return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
}

// Function to find the minimum and maximum values in a binary tree
void find_min_max(Node* node, int* min_val, int* max_val) {
  if (node == NULL) {
    return;
  }

  // Update minimum if current node's data is smaller
  *min_val = (*min_val < node->data) ? (*min_val) : node->data;

  // Update maximum if current node's data is greater
  *max_val = (*max_val > node->data) ? (*max_val) : node->data;

  find_min_max(node->left, min_val, max_val);
  find_min_max(node->right, min_val, max_val);
}

 

