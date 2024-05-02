#include <stdio.h>
#include <time.h>
#include "tree.h"

int main() {

    struct Node* root = NULL;
    clock_t start = clock();
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

    int sum = calculateSum(root);
    printf("Sum of all node values: %d\n", sum);
    clock_t end = clock();
    double Time_taken = ((double) (end - start));

    printf("Time taken: = %f seconds\n", Time_taken);

    return 0;
}
