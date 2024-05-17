#include "main.h"

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 8);
    
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    int value = 5;
    struct Node* result = search(root, value);
    if (result != NULL) {
        printf("%d found in the BST.\n", value);
    } else {
        printf("%d not found in the BST.\n", value);
    }

    printf("Height of the binary tree: %d\n", maxDepth(root));

    printf("Minimum value in the binary tree: %d\n", minValue(root));

    printf("Maximum value in the binary tree: %d\n", maxValue(root));

    return 0;
}


