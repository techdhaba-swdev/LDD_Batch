#include "node.h"//includes node header file which contains node strucutre with function declarations and header files
#include <time.h>//time.h includes time calculating functions like CLOCK_T
int main() {
	clock_t start = clock();
    struct Node* root = NULL;  // Initialize root pointer
                                          
    // Insert elements into BST
    root = insert(root, 50);  //inserting 50 as root value                                           
    insert(root, 30);//inserting data 30
    insert(root, 20);//inserting data 20
    insert(root, 40);//inserting data 40
    insert(root, 70);//inserting data 70
    insert(root, 60);//inserting data 60
    insert(root, 80);//inserting data 80

    // In-order traversal
    printf("In-order traversal: ");   // Print in-order traversal                                   
    inOrderTraversal(root);//calling in order traversal that returns inorder traversal of root nodes data
    printf("\n");//print next line

    // Search
    int searchValue = 70; // Value to search                                                
    struct Node* searchedNode = search(root, searchValue);  // Search for value              
    if (searchedNode != NULL) {  //checking weather searchnode is not null                                        
        printf("%d found in the BST.\n", searchValue);  // Print if found                  
    } else {
        printf("%d not found in the BST.\n", searchValue); // Print if not found               
    }

    // Minimum and Maximum
    printf("Minimum value in the BST: %d\n", findMin(root)->data); // Print minimum value
    printf("Maximum value in the BST: %d\n", findMax(root)->data); // Print maximum value
    // Pre-order traversal
	printf("Pre-order traversal: ");//print the givenstring
	preOrderTraversal(root);//print preorder travel of root nodes
	printf("\n");//prins next line

	// Post-order traversal
	printf("Post-order traversal: ");//printd the entered string
	postOrderTraversal(root);//prints post order traversal of root node values
	printf("\n");//print next line

    // Deletion
    int deleteValue = 30; // Value to delete
    root = deleteNode(root, deleteValue); // Delete node
    printf("In-order traversal after deleting %d: ", deleteValue);// Print in-order traversal
    inOrderTraversal(root);
    printf("\n");

    // Check if the tree is a BST
    printf("Is the tree a BST? %s\n", isBST(root) ? "Yes" : "No");// Check if BST property is satisfied

    // Height
    printf("Height of the BST: %d\n", height(root));// Print height of the tree
	clock_t end = clock();
	double time_used = ((double)(start-end))/CLOCKS_PER_SEC;
		printf("time taken : %f\n",time_used);
    return 0;
}

