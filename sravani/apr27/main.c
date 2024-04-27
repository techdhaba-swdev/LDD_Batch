#include <stdio.h>
#include "bst.h"

int main() {
    struct node* root = NULL;
    // Insert some nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the in-order traversal of the BST
    printf("Inorder traversal of the bst: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a value in the BST
    int searchKey = 60;
    if (search(root, searchKey)) {
        printf("%d is present in the bst.\n", searchKey);
    } else {
        printf("%d is not present in the bst.\n", searchKey);
    }

    return 0;
}

