#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"linkedlist.h"
struct node{
        int data;
        struct node *next;
};
void sumofdata(struct node *head);
struct node *head = NULL;
struct node *current = NULL;
void insertatbegin(int data)
{
	struct node *lk= (struct node* )malloc(sizeof(struct node ));
	lk->data=data;
	lk->next=head;
	head=lk;
}
int main()
{
int k =0;
insertatbegin(1);
insertatbegin(2);
insertatbegin(3);
insertatbegin(4);
insertatbegin(5);
sumofdata(head);
return 0;
}
