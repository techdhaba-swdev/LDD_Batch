#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node  *next;
};
void insertStart(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->data = data;
			newNode->next = *head;
			
			*head = newNode;
			printf("Inserted %d\n",newNode->data);
}
void deleteStart(struct Node** head)
{
	struct Node* temp = *head;
		if(*head == NULL)
		{
		printf("Impossible to delete from singly linked list");
		return;
		}
		*head = (*head)->next;
		printf("deleted:%d\n", temp->data);
		free(temp);
}
void traverse(struct Node* node)
{
printf("\nLinked List: ");
while(node!=NULL){
	printf("%d",node->data);
	node = node->next;
}
printf("\n");
}
int main()
{
	struct Node* head = NULL;
		insertStart(&head,100);
		insertStart(&head,80);
		insertStart(&head,60);
		insertStart(&head,40);

		traverse(head);

		deleteStart(&head);
		deleteStart(&head);
		traverse(head);
		return 0;

}

	

