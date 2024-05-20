
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "BST.h"

int main() {
    struct Node* root = NULL;
    clock_t start, end; // Variables to store start and end time
     double cpu_time_used; //Variables to store CPU time used
     
     //Start clock
     start = clock();

    // Insert nodes into the binary tree
    root = insert(root, 50);
    insert(root, 80);
    insert(root, 60);
    insert(root, 40);
    insert(root, 30);
    insert(root, 10);
    insert(root, 90);

    // Print in-order traversal of the binary tree
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");


    // Calculate the sum of all nodes in the binary tree
    int sum = add(root);
    printf("Sum of all nodes: %d\n", sum);

    //stop clock
    end = clock();
   
    //Calculate CPU time used
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time used: %f seconds\n", cpu_time_used);
    // Memory deallocation for the binary tree is not shown here to keep the example simple

    return 0;
}


