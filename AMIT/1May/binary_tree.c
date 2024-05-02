#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"tree.h"


// Main function: Example usage
int main()
{   
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
    int sum = sumOfNodes(root);
    printf("Sum of all nodes: %d\n", sum);
        clock_t end = clock();

    // Calculate the elapsed time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
      printf("Time taken: %f seconds\n", time_taken);
    
    return 0;
}

