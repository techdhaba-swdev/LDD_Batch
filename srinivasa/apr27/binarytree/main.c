#include "bst.h"  // including the bst header file
#include <stdio.h>  // including the input/output header functions

// Main function 
int main() {
    struct node* root = NULL;  // creating a root and initialize as NULL
    root = insert(root, 50); // inserting 50 as root
    insert(root, 30);        // inserting some nodes 
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the BST: "); 
    inorderTraversal(root);  // printing the BTS
    printf("\n");

    int searchKey = 60;     // giving a element to search
    // searching the key and printing the result
    if (search(root, searchKey)) {
        printf("%d is present in the BST.\n", searchKey);
    } else {
        printf("%d is not present in the BST.\n", searchKey);
    }

    return 0;  // executing the programe with out errors
}
