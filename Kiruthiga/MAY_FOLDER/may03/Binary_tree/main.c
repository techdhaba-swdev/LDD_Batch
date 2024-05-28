#include<stdio.h>
#include"binary_tree.h"
int main() {
    struct Node* root = NULL;
    root = insert(root, 20);
    insert(root, 100);
    insert(root, 40);
    insert(root, 30);
    insert(root, 90);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");

    int key = 40;
    struct Node* searchResult = search(root, key);
    if (searchResult != NULL)
        printf("%d found in the tree.\n", key);
    else
        printf("%d not found in the tree.\n", key);

    printf("Is the tree a BST? %s\n", isBST(root) ? "Yes" : "No");

    printf("Height of the tree is %d\n", maxDepth(root));

    printf("Minimum value in the tree is %d\n", minValue(root));
    printf("Maximum value in the tree is %d\n", maxValue(root));

    // Delete a node
    int deleteKey = 40;
    root = deleteNode(root, deleteKey);
    printf("In-order traversal after deletion of %d: ", deleteKey);
    inorderTraversal(root);
    printf("\n");

    return 0;
}




