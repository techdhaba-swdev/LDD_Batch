#include<stdio.h>
#include <stdlib.h>
#include "binarytree.h"

int main()
{
	struct Node* root = NULL;
       root =insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,50);

	printf(" Order of the Binary Tree:");
	inorderTraversal(root);
	printf("\n");

	int searchData = 50;
	if(search(root,searchData))
	{
		printf("%d found the value Binary tree\n",searchData);
	}
	else
	{
		printf("%d not found the value Binary tree\n",searchData);
	}

	return 0;
}
			

