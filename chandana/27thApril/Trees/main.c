#include <stdio.h>    // Include the standard input/output header file for printf
#include "bst.h"      // Include the custom header file for the BST implementation

int main() {
    struct node* root = NULL;  // Initialize an empty root node for the BST

    // Insert nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform an in-order traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a node
    int searchKey = 40;
    if (search(root, searchKey)) {
        printf("%d found in the BST\n", searchKey);
    } else {
        printf("%d not found in the BST\n", searchKey);
    }

    // Delete a node
    int deleteKey = 30;
    root = deleteNode(root, deleteKey);
    printf("After deleting %d, inorder traversal: ", deleteKey);
    inorderTraversal(root);
    printf("\n");

    // Find the minimum and maximum values
    struct node* minNode = minValueNode(root);
    struct node* maxNode = maxValueNode(root);
    printf("Minimum value in the BST: %d\n", minNode->data);
    printf("Maximum value in the BST: %d\n", maxNode->data);

    // Calculate the height of the tree
    int treeHeight = height(root);
    printf("Height of the BST: %d\n", treeHeight);

    return 0;  // Return 0 to indicate successful execution
}
