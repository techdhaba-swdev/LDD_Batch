#include"header.h" //includes header.h headerfile 
#include "insert.h"// includes insert header file
#include "newnode.c" // includes the newnode function 

struct Node *insert(struct Node *root , int data) // function for inserting nodes and data using structure
{
	if(root == NULL) // checks newnode is created or not
	{
		return createnode(data); // returns to create node function when root is found null
	}
	if(data < root->data) // checks if data is lessthan root data 
	{
		root->Left = insert(root->Left , data); // if condition true insert data to leftnode of root
	}
	else if (data > root->data) // checks is data is greaterthan root data
	{
		root->Right = insert(root->Right ,data);//if condition true insert data to rightnode of root
	}
	else
	{
		printf("duplicate data %d\n",data);// if the data does not matches above condition the print it as duplicate value
	}
	return root;//returns root to function
}


