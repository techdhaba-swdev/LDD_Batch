#include<stdio.h>
#include "dbt.h"
#include<stdlib.h>

int main()
{
	struct Node* root = NULL;
	root = insert(root,25);
	insert(root,60);
	insert(root,50);
	insert(root,90);
	insert(root,70);

	printf("Inorder Node  BST:");
	inorder(root);
	printf("\n");
	
	 root= deletenode(root,50);
	printf("After inorder  delete Node:\n");
       inorder(root);
       printf("\n");
       
       struct Node* found = search(root,25);
       if (root == found)
       {
	       printf("found the value\n");
       }
       else
       {
	       printf("Not found the value\n");
       }
       return 0;
}       

