#include "bst.h"
#include <stdio.h>

int main() {
    struct Node* root = NULL;

    // Insert some values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the in-order traversal of the BST
    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    // Search for a value in the BST
    int searchValue = 70;
    struct Node* searchResult = search(root, searchValue);
    if (searchResult != NULL) {
        printf("%d found in the BST\n", searchValue);
    } else {
        printf("%d not found in the BST\n", searchValue);
    }

    // Delete a value from the BST
    int deleteValue = 30;
    root = deleteNode(root, deleteValue);

    // Print the in-order traversal after deletion
    printf("In-order traversal after deleting %d: ", deleteValue);
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
