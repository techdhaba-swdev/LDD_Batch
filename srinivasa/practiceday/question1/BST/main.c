// Including the all required  header files
#include <stdio.h>
#include "bst.h"
#include<time.h>
// Starting the main function
int main() {
    clock_t start = clock();   // starting time of the execution
    struct Node* root = NULL; // creating a root node 
    root = insert(root, 50);  // insering a value to the  root 
    insert(root, 30);         //insering some nodes 
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    // printing the inorder transversal of the tree
    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);      // calling the function by value 
    printf("\n");
    //performing the delete operation 
    root = deleteNode(root, 20);  // calling the funtion to delete
    // printing the values after deleting the key
    printf("In-order traversal after deleting 20: ");
    inOrderTraversal(root);
    printf("\n");
    // this function is used to search any element in bst
    struct Node* searchResult = search(root, 30);
    if (searchResult != NULL) {   // checking the key is present or not
        printf("Element found  in the BST.\n");
    } else {
        printf("Element not found in the BST.\n");
    }
    clock_t end = clock();   //end time of the execution
    float time = ((float)(end - start ));
    printf("time taken :%f",time);
    return 0;
}
