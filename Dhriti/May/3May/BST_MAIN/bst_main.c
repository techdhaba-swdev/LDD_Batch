#include "bst_main.h"

int main() {
	
    struct Node* root = NULL; //  the root node to NULL
    
    clock_t start = clock();
    root = insert(root, 15);   // Insert nodes into the tree
    insert(root, 13);
    insert(root, 12);
    insert(root, 14);
    insert(root, 17);
    insert(root, 16);
    insert(root, 18);
    
    // Stop the clock
    clock_t end = clock();

    // Calculate the elapsed time
    double time_taken = ((double)(end - start));

    
    printf("In order traversal: ");
    
    printf("Time taken: %f seconds\n", time_taken);
    inOrderTraversal(root);  // Performing in-order traversal and printing the nodes
    printf("\n");

    printf("Height of BST: %d\n", height(root));  // Calculate the height of the binary tree and then print

    int min = INT_MAX;  // Initialize min to the maximum possible output
    int max = INT_MIN;  // Initialize max to the minimum possible output
    MinMax(root, &min, &max);  // Find the minimum and maximum values in the binary tree
    printf("Minimum value in BST: %d\n", min);  // Print the minimum value
    
    printf("Maximum value in BST: %d\n", max);  // Print the maximum value
    printf("BINARY TREE USING PRE :"); //printing bst
        preorder(root); //PREORDER  TRAVERSING THROUGH THE TREE AND PRINTING EACH ELEMENT
        printf("\n");
	printf("BINARY TREE USING POSTORDER :"); //printing bst 
        postorder(root); // POSTORDER TRAVERSING THROUGH THE TREE AND PRINTING EACH ELEMENT
        printf("\n");
	

    root = deletion(root, 12);  // Delete a node from the binary tree
    printf("In-order traversal after deletion: ");
    inOrderTraversal(root);  //  print the nodes after deletion
    printf("\n");

    return 0; 
}
