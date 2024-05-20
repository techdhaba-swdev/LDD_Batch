#include <stdio.h>
#include "bst.h"

int main() {
    // Initialize the root of the BST as NULL
    struct node* root = NULL;

    // Insert some elements into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Perform an in-order traversal of the BST and print the elements
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Search for elements in the BST
    int searchKey = 40;
    if (search(root, searchKey)) {
        printf("%d is found in the BST.\n", searchKey);
    } else {
        printf("%d is not found in the BST.\n", searchKey);
    }

    searchKey = 90;
    if (search(root, searchKey)) {
        printf("%d is found in the BST.\n", searchKey);
    } else {
        printf("%d is not found in the BST.\n", searchKey);
    }

    // Deallocate memory for the entire BST
    destroyTree(root);

    return 0;
}
