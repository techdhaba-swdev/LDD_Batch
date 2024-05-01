#include "order.h"// includes the order.h header file

void inOrder(struct Node *root) // fuction for inorder alignment of node data
{
	if(root != NULL) // checking weather root is null or not
	{
		inOrder(root->Left);//inorder alignment of root left node
		printf("%d\n",root->data); // prints root data
		inOrder(root->Right); // inorder alignment of right node
	}
}

