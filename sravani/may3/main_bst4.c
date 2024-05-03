#include <stdio.h>
#include "bst4.h"
#include<limits.h>
#include<time.h>

int main() {
  Node* root = newNode(4);
  root->left = newNode(2);
  root->right = newNode(5);
  root->left->left = newNode(1);
  root->left->right = newNode(3);
clock_t start, end;
    double cpu_time_used;

  int min_val = INT_MAX, max_val = INT_MIN;
  find_min_max(root, &min_val, &max_val);

  int tree_height = height(root);

  printf("The minimum value in the tree is %d\n", min_val);
  printf("The maximum value in the tree is %d\n", max_val);
  printf("The height of the tree is %d\n", tree_height);

  if (is_bst(root, INT_MIN, INT_MAX)) {
    printf("The tree is a Binary Search Tree\n");
  } else {
    printf("The tree is not a Binary Search Tree\n");
  }
// Timing the pre-order traversal
    start = clock();
    printf("\n");
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for pre-order traversal: %f seconds\n", cpu_time_used);

  return 0;
}
