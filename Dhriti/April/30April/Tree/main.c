#include <stdio.h>
#include "binary_tree.h"
#include<time.h>
int main() {
    // Initialize an empty binary search tree (BST) represented by the root node
    struct Node* root = NULL;
     
    
    clock_t start = clock(); //start the clock
    
    // Insert nodes with various values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    

     clock_t end = clock(); //stop the clock

        double time_taken = ((double)(end - start)); //cal the elapsed time'

    // Print the elements of the BST in sorted order using in-order traversal
    printf("In-order traversal: ");

    printf("Time taken: %f seconds \n",time_taken);
    inOrder(root);
    printf("\n");

    return 0;
}

