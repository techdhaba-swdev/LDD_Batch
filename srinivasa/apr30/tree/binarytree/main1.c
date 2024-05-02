#include "binary_tree.h"
#include <stdio.h>
#include<time.h>
int main() {
	clock_t start = clock();
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Sum of data in the tree: %d\n", sumOfData(root));

    freeTree(root); // Free allocated memory
    clock_t end = clock();
    float time = ((float)(end - start));
    printf("time taken: %f\n", time);
    return 0;
}
