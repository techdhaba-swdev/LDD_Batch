#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<limits.h>
#include "bstfunc.h"

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Creating a sample BST
    TreeNode* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);

    // Insertion and deletion
    root = insert(root, 8);
    root = deleteNode(root, 3);

    // Search
    int searchKey = 5;
    TreeNode* searchedNode = search(root, searchKey);
    if (searchedNode != NULL)
        printf("%d found in the BST.\n", searchKey);
    else
        printf("%d not found in the BST.\n", searchKey);

    // In-order traversal
    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Pre-order traversal
    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Post-order traversal
    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Check if BST
    if (isBST(root))
        printf("The tree is a Binary Search Tree.\n");
    else
        printf("The tree is not a Binary Search Tree.\n");

    // Height of the tree
    int height = findHeight(root);
    printf("Height of the tree is: %d\n", height);

    // Min and Max values
    int min = INT_MAX, max = INT_MIN;
    findMinMax(root, &min, &max);
    printf("Minimum value in the tree: %d\n", min);
    printf("Maximum value in the tree: %d\n", max);

    // Measure time taken
    start = clock();
    // Perform operations here...
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
