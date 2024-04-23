#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"linkedlist.h"
void sumofdata(struct node *head)
{
	struct node *p = head;
	int sum =0;
	while (p!=NULL)
	{
		sum = sum + p->data;
		p=p->next;
	}
	printf("sum = %d",sum);
}


