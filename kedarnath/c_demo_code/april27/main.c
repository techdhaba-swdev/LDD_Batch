#include"treenode.h"

int main() {
    struct node* root = NULL;

    // Insert some elements into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print in-order traversal of the BST
    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for elements in the BST
    int key = 50;
    if (search(root, key)) {
        printf("%d is found in the BST.\n", key);
    } else {
        printf("%d is not found in the BST.\n", key);
    }

    key = 90;
    if (search(root, key)) {
        printf("%d is found in the BST.\n", key);
    } else {
        printf("%d is not found in the BST.\n", key);
    }

    // Find minimum and maximum values in the BST
    printf("Minimum value in the BST: %d\n", findMinValue(root));
    printf("Maximum value in the BST: %d\n", findMaxValue(root));

    // Find height of the BST
    printf("Height of the BST: %d\n", findHeight(root));

    // Delete some elements from the BST
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    root = deleteNode(root, 50);

    // Print in-order traversal of the modified BST
    printf("In-order Traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}




