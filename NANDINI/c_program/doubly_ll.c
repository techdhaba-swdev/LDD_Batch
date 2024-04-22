#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* prev;
	struct node* next;
};
struct node* createnode(int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}
void insertingatbeginning(struct node** headref, int data)
{
	struct node* newnode = createnode(data);
	if(*headref == NULL)
	{
		*headref = newnode;
	}
	else
	{
		newnode->next = *headref;
		(*headref)->prev = newnode;
		*headref = newnode;
	}

}
void insertatend(struct node** headref, int data)
{
	struct node* newnode = createnode(data);
	if(*headref == NULL)
	{
		*headref = newnode;
	}
	else
	{
		struct node* temp = *headref;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
	}
}
void printlist(struct node* head)
{
	while(head != NULL)
	{
		printf("%d", head->data);
		head = head->next;
	}
	printf("\n");
}
int main()
{
	struct node* head = NULL;
        insertingatbeginning(&head, 22);
	insertingatbeginning(&head, 29);
	insertingatbeginning(&head, 7);
	printf("Doubly linked list after inserting at the beginning: ");
	printlist(head);
	insertatend(&head, 10);
	insertatend(&head, 5);
	printf("Doubly linked list after inserting at the end: "); 
	printlist(head);
	return 0;
}

