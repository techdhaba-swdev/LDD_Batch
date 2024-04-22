#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node* create_node(int data)
{
	struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
	new_node->data=data;
	printf("%d",data);
	new_node->next=NULL;
	return  new_node;	
}


void insert_node(struct Node* root,int data)
{
	printf("%d",data);
struct Node* new_node=create_node(data);
struct Node* tmp=root;
while(tmp->next!=NULL)
{
	tmp=tmp->next;
}
tmp->next=new_node;

}

int getmiddelOfLinkList(struct Node* root)
{
struct Node* slow=root;
struct Node* fast=root->next;
//while(fast!=NULL && fast->next!=NULL)
while(fast->next != NULL && fast!=NULL)
{
	slow=slow->next;
	fast=fast->next->next;
}
return slow->data;
}
