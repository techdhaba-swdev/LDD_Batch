#include <stdio.h>
#include "projectbst.h"

// Main function
int main() 
{
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 20);
    printf("In-order traversal after deleting 20: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
