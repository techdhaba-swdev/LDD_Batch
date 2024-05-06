#include "binarystree.h"
#include <stdio.h>
#include<time.h>
int main() {
	
    struct Node* root = NULL;
    clock_t start = clock();
    
    
    root = insertNode(root, 40);
    insertNode(root, 20);
    insertNode(root, 10);
    insertNode(root, 30);
    insertNode(root, 60);
    insertNode(root, 50);
    insertNode(root, 70);

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    int searchValue = 30;
    struct Node* foundNode = searchNodeValue(root, searchValue);
    if (foundNode != NULL) {
        printf("%d found in the Binary Tree.\n", searchValue);
    } else {
        printf("%d not found in the Binary Tree.\n", searchValue);
    }

    int minValue = findMinValue(root);
    printf("Minimum value in the Binary Tree: %d\n", minValue);

    int maxValue = findMaxValue(root);
    printf("Maximum value in the Binary Tree: %d\n", maxValue);


    printf("Height of the binary tree: %d\n", maxHeight(root));

    
    root = deleteNode(root, 10);
    printf("Inorder traversal after deleting 10 is: ");
    inOrderTraversal(root);
    printf("\n");
    printf("Preorder traversal after deleting 10 is: ");
    preOrderTraversal(root);
    printf("\n");
    printf("Postorder traversal after deleting 10 is: ");
    postOrderTraversal(root);
    printf("\n");

    root = deleteNode(root, 20);
    printf("Inorder traversal after deleting 20 is: ");
    inOrderTraversal(root);
    printf("\n");
    printf("Preorder traversal after deleting 20 is: ");
    preOrderTraversal(root);
    printf("\n");
    printf("Postorder traversal after deleting 20 is: ");
    postOrderTraversal(root);
    printf("\n");

    clock_t stop = clock();
    double time_taken = ((double)(stop - start));
    printf("Time taken: %f\n", time_taken);

    freeTree(root);

    return 0;
}
