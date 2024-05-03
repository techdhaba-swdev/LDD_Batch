#include <stdio.h>
#include <time.h>
#include "post.h"

int main() {
    // Creating a binary tree
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    clock_t start, end;
    double cpu_time_used;

    // Timing the pre-order traversal
    start = clock();
    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for pre-order traversal: %f seconds\n", cpu_time_used);

    // Timing the post-order traversal
    start = clock();
    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for post-order traversal: %f seconds\n", cpu_time_used);

    return 0;
}
