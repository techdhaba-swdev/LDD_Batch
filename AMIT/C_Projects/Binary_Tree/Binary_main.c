#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h> //for INT_MIN and INT_MAX
#include"tree.h"
#include<time.h>

int main()
{  
    clock_t start = clock();
    struct Node* root = NULL;

    // Insertion
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // In-order traversal
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Search
    int searchValue = 70;
    struct Node* searchedNode = search(root, searchValue);
    if (searchedNode != NULL) {
        printf("%d found in the BST.\n", searchValue);
    } else {
        printf("%d not found in the BST.\n", searchValue);
    }

    // Minimum and Maximum
    printf("Minimum value in the BST: %d\n", findMin(root)->data);
    printf("Maximum value in the BST: %d\n", findMax(root)->data);

    // Deletion
    int deleteValue = 30;
    root = deleteNode(root, deleteValue);
    printf("In-order traversal after deleting %d: ", deleteValue);
    inOrderTraversal(root);
    printf("\n");

    // Check if the tree is a BST
    printf("Is the tree a BST? %s\n", isBST(root) ? "Yes" : "No");

    // Height
    printf("Height of the BST: %d\n", height(root));
     
    clock_t end = clock();

    // Calculate the elapsed time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
      printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
