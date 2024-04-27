#include<stdio.h>
#include"binarysearchtree.h"
int main()
{
    	struct node* root = NULL; //Initializing the root node

    	// Inserting nodes into the binary search tree
    	root = insert(root, 50);
    	insert(root, 30);
    	insert(root, 20);
    	insert(root, 40);
    	insert(root, 70);
    	insert(root, 60);
    	insert(root, 80);
	printf("TREE :");
        inordertraversal(root);
        printf("\n");

    	if (search(root, 40) != NULL) //Perfromed search operation for node with data 60
	{
        	printf("Yes,40 is found\n");
    	}
    	else 
	{
        	printf("OOPS!! 40 not found\n");
    	}
    	struct node* temp = delete (root, 70); //Performed delete operation to delete the 70 node
    	printf("After Deleting Node with data 70: ");
    	inordertraversal(root); //Called inordertraversal for traversing through tree
    	printf("\n");
   	int min=*(int *)find_min(root); //typecasted the find min function as it returns integer
   	printf("Minimum element in Tree : %d\n",min);
    	int max=*(int *)find_max(root); //typecasted the find max function as it returns integer
    	printf("Maximum element in Tree: %d\n",max);
	free(root); //Freeing up the root

    return 0;
}
