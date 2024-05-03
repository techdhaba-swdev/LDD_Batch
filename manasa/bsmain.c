#include <stdio.h>
#include <time.h>
#include "bs.h"

int main() {
	 clock_t start = clock(); //start the close
    struct node* root = NULL;
    // Insert some nodes into the BST
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);

    clock_t end = clock(); //stop the clock
	double time_taken = ((double)(end - start)); //cal the elapsed time'
    
    // Print the in-order traversal of the BST
    printf("Inorder traversal of the bst: ");
    inorderTraversal(root);
    printf("\n");
    printf("time taken %f \n",time_taken);
    //delete a node from the BST
    int key = 2;
    root = deleteNode(root,key);
    printf("Node with data %d deleted froM THE BST\n",key);

    // Search for a v// Search for a value in the BST
    int searchKey = 6;
    if (search(root, searchKey)) {
        printf("%d is present in the bst.\n", searchKey);
    } else {
        printf("%d is not present in the bst.\n", searchKey);
    }

    return 0;
}
