#include <stdio.h>
#include "bst.h" // Include the header file for BST functions

int main() {
    struct node* root = NULL; // Declare a pointer to the root node and initialize it to NULL
    root = insert(root, 50); // Insert nodes into the BST
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the BST: ");
    inorderTraversal(root); // Perform an in-order traversal of the BST
    printf("\n");

    int searchData = 30;
    if (search(root, searchData)) { // Search for a node in the BST
        printf("%d found in the BST\n", searchData);
    } else {
        printf("%d not found in the BST\n", searchData);
    }

    printf("Minimum value in the BST: %d\n", findMin(root)); // Find the minimum value in the BST
    printf("Maximum value in the BST: %d\n", findMax(root)); // Find the maximum value in the BST
    printf("Height of the BST: %d\n", height(root)); // Calculate the height of the BST

    // Deleting node 30 for testing deletion
    root = deleteNode(root, 30);
    printf("In-order traversal of the BST after deleting 30: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
