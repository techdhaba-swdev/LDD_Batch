#include <stdio.h>
#include "main.h"

int main() {
    Node* root = NULL;                            // Initialize root pointer to NULL

    // Insert some nodes into the BST
    root = insert(root, 50);                      // Insert node with data 50
    insert(root, 30);                             // Insert node with data 30
    insert(root, 20);                             // Insert node with data 20
    insert(root, 40);                             // Insert node with data 40
    insert(root, 70);                             // Insert node with data 70
    insert(root, 60);                             // Insert node with data 60
    insert(root, 80);                             // Insert node with data 80

    // Perform in-order traversal of the BST and print node values
    printf("In-order traversal of the BST: ");
    inorderTraversal(root);                       // Call inorderTraversal function to print BST in-order
    printf("\n");

    // Search for a node with data 40 in the BST
    int key = 40;                                 // Key to search for
    if (search(root, key)) {                      // If node with data 40 is found
        printf("%d found in the BST\n", key);     // Print message indicating that 40 is found
    } else {
        printf("%d not found in the BST\n", key); // Print message indicating that 40 is not found
    }

    return 0;                                     // Return 0 to indicate successful execution
}
