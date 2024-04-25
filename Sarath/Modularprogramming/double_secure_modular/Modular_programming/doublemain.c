#include<stdio.h>
#include<stdlib.h>
#include"double_linkedlist.h"
int main()
{
	struct node *head=NULL;
	insert_at_start(1);
	insert_at_start(2);
	insert_at_start(3);
	insert_at_end(4);
	insert_at_end(5);
	print();
	return 0;
}

