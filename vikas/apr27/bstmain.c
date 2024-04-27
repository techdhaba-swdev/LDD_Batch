#include <stdio.h>
#include "bst.h"

int main() {
    struct node* root = NULL;

    // Insert some elements into the BST
    root = insert(root, 100);
    root = insert(root, 67);
    root = insert(root, 45);
    root = insert(root, 145);
    root = insert(root, 137);
    root = insert(root, 89);
    root = insert(root, 119);

    // Print the inorder traversal of the BST
    printf("Inorder traversal of BST: ");
    inorderTraversal(root);
    printf("\n");

    // Search for elements in the BST
    int searchKey = 119;
    if (search(root, searchKey)) {
        printf("%d found in the BST.\n", searchKey);
    } else {
        printf("%d not found in the BST.\n", searchKey);
    }

    searchKey = 188;
    if (search(root, searchKey)) {
        printf("%d found in the BST.\n", searchKey);
    } else {
        printf("%d not found in the BST.\n", searchKey);
    }

    return 0;
}
