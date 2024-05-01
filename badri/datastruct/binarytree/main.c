#include "header.h" // includes the header.h header to main.c
 #include "newnode.h" // includes newnode.h header to main.c file 
#include "insert.h"// includes insert.h header file to main.c file
#include "order.h"// includes order.h header file 
#include "binary_tree.h"//includes binary_tree.h headerfile
#include"sum.h"//includes sum.h headerfile
#include<time.h>//includes time functions
int main()
{
	clock_t start = clock();
	struct Node *root = NULL;//assining NULL value to root
	root = insert(root,50);//inserting 50 value to root 
	insert(root,30);//inserting 30 value to root
	insert(root,20);//inserting 20 value to root
	insert(root,40);//inserting 40 value to root
	insert(root,70);//inserting 70 value to root
	insert(root,60);//inserting 60 value to root
	insert(root,80);//inserting 80 value to root
	printf("in -order traversal:\n ");// prints string
	inOrder(root);//calling inorder function
	printf("\n");//prints nest line
	int sum = sumNodes(root);//assining return sumofnodes value to sum
	printf("sum of root nodes %d\n",sum);//printing sum of all nodes
	clock_t end = clock();
	double time_taken = ((double)(start - end)) /CLOCKS_PER_SEC;
	printf("time taken : %f\n",time_taken);
	return 0;//returning value 0 successful termination of program
	}

