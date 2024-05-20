#include <stdio.h>
#include "node.h"
#include "insert.h"
#include "inorder.h"
#include "sumofnodes.h"
#include "freetree.h" // Include the freetree module
#include <time.h>

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

    int totalSum = sumOfNodes(root);
    printf("Sum of all node data elements: %d\n", totalSum);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    freeTree(root); // Free memory used by tree nodes

    return 0;
}
