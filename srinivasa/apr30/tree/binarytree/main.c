#include<stdio.h>
#include<stdlib.h>
#include"binary.h"
int main()
{
	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
        insert(root, 60);
        insert(root, 80);
	printf("in-order transversal:");
	inorder(root);
	printf("\n");
	return 0;
}


