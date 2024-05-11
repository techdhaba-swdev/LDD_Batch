#include "main.h" // Include the header file for function prototypes (used to secure multiple inclusion)
#include <time.h>
#include <stdio.h>

// Main function: Example usage
int main() {
    clock_t start = clock();
    struct Node* root = NULL; // Initialize root pointer to NULL

    // Insert nodes into the binary tree
    root = insert(root, 50); // Insert node with value 50
    insert(root, 30); // Insert node with value 30
    insert(root, 20); // Insert node with value 20
    insert(root, 40); // Insert node with value 40
    insert(root, 70); // Insert node with value 70
    insert(root, 60); // Insert node with value 60
    insert(root, 80); // Insert node with value 80

    printf("In-order traversal: "); // Print message indicating in-order traversal
    inOrder(root); // Perform in-order traversal
    printf("\n"); // Print new line after traversal

    printf("Sum of all nodes: %d\n", sumOfNodes(root)); // Print sum of all nodes

    // Deallocate memory for the binary tree
    freeTree(root); // Free memory allocated for the binary tree nodes
    clock_t end = clock();
    double time_taken = ((double)(end-start)) / CLOCKS_PER_SEC;
    printf("time taken is :%f seconds\n", time_taken);
    return 0; // Return 0 to indicate successful program execution
}
