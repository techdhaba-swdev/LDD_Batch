#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node*head=NULL;
	struct node*current = NULL;
	void printlist()
	{
		struct node *p = head;
		printf("\n");
		while (p !=NULL)
		{
			printf("%d",p->data);
			p=p->next;
		}
		printf("]");
	}

	struct node

:wq




        

