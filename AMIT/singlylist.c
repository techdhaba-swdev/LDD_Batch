#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* createnode(int value)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node*));
	newnode->data= value;
	newnode->next= NULL;
	return newnode;
}

void insert(struct node** head, int value)
{
	struct node* newnode= createnode(value);
	newnode->next = *head;
	*head = newnode;
}
void delete(struct node** head, int value)
{
	struct node* current= *head;
	struct node* prev= NULL;

	while(current!=NULL && current->data != value)
	{
		prev= current;
		current= current->next;
	}
	if(current==NULL)
	{
		printf("Element %d  not found in the list.\n",value);
		return;
	}
	if(prev==NULL)
	 *head= current->next;
	else
		prev->next= current->next;

	free(current);
		printf("element %d deleted from the list\n",value);

}

void traverse(struct node* head)
{
	struct node* current =head;
	while(current != NULL)
	{
		printf("%d-> ",current->data);
		current= current->next;
	}

	printf("NULL \n");
}

int main()
{
	struct node* head=NULL;

	insert(&head,30);
	insert(&head,40);
	insert(&head,50);

	printf("origiinal linked list:");
	traverse(head);
	delete(&head,40);
	
	printf("updated linked list:");
	traverse(head);

	while(head!=NULL)
	{
		struct node* temp= head;
		head= head->next;
		free(temp);
	}
	return 0;
}























