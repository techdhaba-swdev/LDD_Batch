#include "binary_tree.h" // includes binarytree.h header file which contains the structure of node
#include "header.h" // includes header.h header file
#include "sum.h" // includes sum.h headerfile

int sumNodes(struct Node *root) // function for printing sum of all inserted nodes
{
	if(root == NULL) // checking weather roor tis null or not
	{
		return 0;// if root is null return 0
	}
	else
		return root->data + sumNodes(root->Left) + sumNodes(root->Right); // if root is not null returns sum of nodes
}
