#include <stdio.h>
#include <time.h>
#include "binary_tree.h"

int main() {
    struct TreeNode* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Measure the time taken to calculate the sum of all node values
    time_t start = time(NULL); // Record the starting time
    int sum = sumAllNodes(root); // Calculate the sum of all node values
    time_t end = time(NULL); // Record the ending time

    // Calculate the elapsed time
    double time_taken = difftime(end, start);
    printf("Sum of all node values: %d\n", sum);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
