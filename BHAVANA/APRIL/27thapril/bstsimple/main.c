#include <stdio.h>
#include "bst.h" //Include the header file for BST functions

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

    return 0;
}
