#include<stdio.h>
#include<time.h>
#include"binarysearchtree.h"
struct node {
	int data;
	struct node *left;
	struct node *right;
};
int main()
{
	clock_t start=clock();
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
        inordertraversal(root); //traversing into the tree and pritning the elements
        printf("\n");

    	if (search(root, 40) != NULL) //Perfromed search operation for node with data 40
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
	int sum=calculatesum(root);
	printf("Sum of elements is %d\n",sum);
	free(root); //Freeing up the root
	clock_t end=clock();
	double time_taken=((double)(end-start));
	printf("Time taken is %f\n",time_taken);
    return 0;
}
