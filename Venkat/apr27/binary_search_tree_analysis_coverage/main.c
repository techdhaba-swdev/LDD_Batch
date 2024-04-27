#include "bst.h"
#include <stdio.h>

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    int searchData = 60;
    if (search(root, searchData)) {
        printf("%d found in the BST.\n", searchData);
    } else {
        printf("%d not found in the BST.\n", searchData);
    }

    
      freeTree(root);// free up allocated memory to prevent from memory leaks
      root = NULL;   // ensure root pointer is not dangling pointer,so assigned to null 

    return 0;
}
