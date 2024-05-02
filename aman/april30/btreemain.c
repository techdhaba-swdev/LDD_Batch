#include <stdio.h>//include standard c libraries for printf,scanf
#include "btree.h"//include header filewhich contains structure definition and function prototype 
#include <time.h>//include standard libraries for measuring time

int main() {//starting main function
    clock_t start = clock();//declaring start of typ clock_t ans assignvalue return by clock()
    struct Node* root = NULL;//this declares pointer variable root of type struct node anf initialize it to null
    
    // Insert nodes into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    // Print in-order traversal of the binary tree
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");
    
    int totalSum = sumAll(root);
    printf("Total sum of all values in the binary tree: %d\n", totalSum);
    
    clock_t stop = clock();//declaring stop oftype clock_t and assign it value return by clockk()
    double time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC;//calculating the time taken by subtract value to start from stop and result is double to allow fractionalvalue
    printf("Time taken: %f seconds\n", time_taken);//prints total time taken
    
    return 0;
}

