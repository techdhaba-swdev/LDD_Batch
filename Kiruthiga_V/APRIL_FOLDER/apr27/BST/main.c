#include<stdio.h>
#include"BST.h"
int main() {
    // Initialize an empty BST
    struct node* root = NULL;

    // Inserting elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Performing in-order traversal
    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Searching for elements
    int key = 30;
    if (search(root, key)) {
        printf("%d found in the BST.\n", key);
    } else {
        printf("%d not found in the BST.\n", key);
    }

    key = 55;
    if (search(root, key)) {
        printf("%d found in the BST.\n", key);
    } else {
        printf("%d not found in the BST.\n", key);
    }

    return 0;
}


