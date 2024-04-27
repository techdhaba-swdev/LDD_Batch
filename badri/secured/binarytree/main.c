#include "bst.h"
#include <stdio.h>
#include <stdlib.h> // Added for error handling

int main() {
    struct node* root = NULL; // Initialize an empty tree

    // Insert some nodes into the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform in-order traversal to verify tree structure
    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a value in the tree
    int searchValue = 40;
    if (search(root, searchValue)) {
        printf("%d found in the tree.\n", searchValue);
    } else {
        printf("%d not found in the tree.\n", searchValue);
    }

    

    return 0;
}
