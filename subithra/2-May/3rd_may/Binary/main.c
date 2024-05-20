#include <stdio.h> // Standard input-output header
#include "main.h" // Header file for BST operations
#include <time.h>// for adding clock

int main() {
    clock_t start = clock();//optimization:clock start for knowing time taken by program
    struct Node* root = NULL; // Initialize root pointer to NULL, indicating an empty tree

    // Insert values into the binary search tree
    root = insert(root, 50); // Insert 50 as the root node
    root = insert(root, 30); // Insert 30
    root = insert(root, 20); // Insert 20
    root = insert(root, 40); // Insert 40
    root = insert(root, 70); // Insert 70
    root = insert(root, 60); // Insert 60
    root = insert(root, 80); // Insert 80

    // Print inorder traversal of the binary search tree
    printf("Inorder traversal: ");
    inorderTraversal(root); // Visit nodes in ascending order (Left-Root-Right)
    printf("\n");

    // Print preorder traversal of the binary search tree
    printf("Preorder traversal: ");
    preorderTraversal(root); // Visit root before its children (Root-Left-Right)
    printf("\n");

    // Print postorder traversal of the binary search tree
    printf("Postorder traversal: ");
    postorderTraversal(root); // Visit children before their root (Left-Right-Root)
    printf("\n");

    // Print the minimum value in the binary search tree
    printf("Minimum value in BST: %d\n", minValue(root)); // Find and print the minimum value

    // Print the maximum value in the binary search tree
    printf("Maximum value in BST: %d\n", maxValue(root)); // Find and print the maximum value

    int key = 70; // Key to search for
    // Search for a key in the binary search tree
    if (search(root, key) != NULL) { // If key is found
        printf("%d found in the BST.\n", key); // Print message
    } else {
        printf("%d not found in the BST.\n", key); // Print message
    }

    // Delete a node from the binary search tree
    root = deleteNode(root, 20); // Delete node with key 20
    // Print inorder traversal after deletion
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root); // Print the updated tree
    printf("\n");

    // Check if the binary tree is a binary search tree (BST)
    printf("Checking if a Binary Tree is a Binary Search Tree (BST):\n");
    if (isBST(root)) { // If the tree is a BST
        printf("The tree is a BST.\n"); // Print message
    } else {
        printf("The tree is not a BST.\n"); // Print message
    }

    // Find the height of the binary tree
    printf("Finding the Height of a Binary Tree:\n");
    printf("Height of the tree: %d\n", height(root)); // Print height
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time Taken : %f seconds\n", time_taken);
    return 0; // Return 0 to indicate successful completion
}
