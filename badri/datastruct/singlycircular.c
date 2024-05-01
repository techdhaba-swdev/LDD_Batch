#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int value;
	struct Node* next;
};

struct Node* create_node(int value)
{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->value=value;
	new_node->next=NULL;
	return new_node;
}

void insert_node(struct Node** head,int value)
{
	struct Node* new_node=create_node(value);
	if(*head==NULL)
	{
		*head=new_node;
		new_node->next=*head;
	}
	else
	{
		struct Node* tail=*head;
		while(tail->next!=*head)
		{
			tail=tail->next;
		}
		tail->next=new_node;
		new_node->next=*head;
	}
}

void print_list(struct Node* head)
{
	if(head==NULL)
	{
		printf("list is empty.\n");
		return;
	}

	struct Node* current =head;
	do
	{
		printf("%d",current->value);
		current=current->next;
	}while(current!=head);

	printf("\n");
}

int main()
{
	struct Node* head=NULL;
	int num_node;
	printf("Enter the number of nodes:");
	scanf("%d",&num_node);

	for(int i=0;i<num_node;++i)
	{
		int value;
		printf("Enter the value for the node %d: ",i+1);
		scanf("%d",&value);
		insert_node(&head,value);
	}

	printf("Circular linked list: ");
	print_list(head);

	struct Node* current=head;
	while(current!=NULL)
	{
		struct Node* temp=current;
		current=current->next;
		free(temp);
	}
	return 0;
}
