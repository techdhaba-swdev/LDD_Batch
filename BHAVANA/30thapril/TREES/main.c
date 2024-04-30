#include <stdio.h>
#include "binary_tree.h"

int main() {
    struct Node* root = NULL;
    // Insert nodes into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print in-order traversal of the binary tree
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    // Calculate the sum of all nodes in the binary tree
    int sum = add(root);
    printf("Sum of all nodes: %d\n", sum);

    // Memory deallocation for the binary tree is not shown here to keep the example simple

    return 0;
}
