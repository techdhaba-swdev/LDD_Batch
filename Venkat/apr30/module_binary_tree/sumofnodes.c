#include "sumofnodes.h"
#include <stddef.h>
#include <stdlib.h>
// sum of all node data elements
int sumOfNodes(struct Node* root) {
    if (root == NULL) return 0; // Base case: empty node, sum is 0
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right); // Sum of current node and its subtrees
}
