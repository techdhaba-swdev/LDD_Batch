#include<stdio.h>
#include "BST.h"


int main() {

	struct node* root = NULL; //here root is set to null indicating an empty tree

	root = insert(root,8);  //insertig 8 as root node

        insert(root,4);
	insert(root,5);
	insert(root,6);
	insert(root,11);
	insert(root,12);
	insert(root,13);

	//search data
	
	if(search (root,12)){
		printf("The data is found: 40 \n");
	}else{
		printf("The data is not found: SEARCH AGAIN \n");
	} 


	printf("The In order data is: ");
	inorderTraversal(root); //sets the data into ascending order
	printf("\n");
}

//root is a ptr to the root node
