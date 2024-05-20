#include "binary_tree.h"
#include <stdio.h>
#include<time.h>

// Main function
int main() {
     clock_t start = clock(); // Start timing

    Node* root = NULL;
    root = insert(root, 50); // Insert root node
    insert(root, 30); // Insert nodes
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    printf("inorder traversal: ");
    inOrder(root);
    printf("\n");
    
    // End timing
    clock_t end = clock();

    // Calculate the elapsed time in milliseconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
   
    // Print the sum of all nodes
    printf("Sum of all nodes: %d\n", sumNodes(root));

    // Print the time taken for execution
    printf("Time taken: %f seconds\n", time_taken);

    // Free allocated memory
    freeTree(root);

    return 0;
}
