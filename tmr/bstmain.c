#include <stdio.h>
#include "bst.h"

int main() {
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

    int sum = calculateSum(root);
    printf("Sum of all node values: %d\n", sum);

    return 0;
    
   }
    
