#include <stdio.h>
#include<time.h>
#include "bst1.h"

int main() {
  clock_t start = clock(); //start the close
    struct node* root = NULL;
    // Insert some nodes into the BST
    root = insert(root, 15);
    insert(root, 13);
    insert(root, 12);
    insert(root, 14);
    insert(root, 17);
    insert(root, 16);
    insert(root, 18);

    clock_t end = clock(); //stop the clock
 double time_taken = ((double)(end - start)); //cal the elapsed time'
    
    // Print the in-order traversal of the BST
    printf("Inorder traversal of the bst: ");
    inorderTraversal(root);
    printf("\n");
    printf("time taken %f \n",time_taken);
    //delete a node from the BST
    int key = 14;
    root = deletion(root,key);
    printf("Node with data %d deleted from the tree.\n",key);

    // Search for a v// Search for a value in the BST
    int search_key = 16;
    if (search(root, search_key)) {
        printf("%d is present in the tree.\n", search_key);
    } else {
        printf("%d is not present in the tree.\n", search_key);
    }

    return 0;
}
