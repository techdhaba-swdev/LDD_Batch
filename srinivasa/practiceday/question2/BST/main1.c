// Including the all required  header files
#include <stdio.h>
#include<stdbool.h>
#include "bst.h"
#include<time.h>
#include<limits.h>
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
    // printing the inorder traversal of the tree
    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);      // calling the function by value 
    printf("\n");
    //printing the preorder traversal of the tree
    printf("pre-order traversal of the tree:");
    preordertraversal(root);
    printf("\n");
    //printing the postorder traversal of the tree
    printf("post -ordertraversal of the tree");
    postordertraversal(root);
    printf("\n");
    // checking the tree is binary search tree or not
    if (isbst(root))
	    printf("the tree is binarysearch tree\n");
    else 
	    printf("this tree is not a binarysearch tree\n");
    // height of the tree
    printf("height of the tree is %d\n",height(root));
    //priting the maximun and minimum values of the binary tree
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    find_min_max(root, &min_val, &max_val);
    printf("MINIMUM VALUE : %d\n",min_val);
    printf("MAXIMUN VALUE : %d\n",max_val);

    clock_t end = clock();   //end time of the execution
    float time = ((float)(end - start ));
    printf("time taken :%f",time);
    return 0;
}
