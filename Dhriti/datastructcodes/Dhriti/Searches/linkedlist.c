#include<stdio.h>
#include<stdlib.h>
        struct Node{
	int data;
	struct Node* next; //next:ptr to the next node in the list
};


void insertnode(struct Node** head, int new_data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data; 
	new_node->next = NULL; //next pointer of new node is set to null

	if (*head == NULL){ //null means the head of the list is empty
		*head = new_node; // make the new node head
		return;
	}
        struct Node* last = *head; // create a temp ptr last
	while(last-> next != NULL)
		last = last->next;
	last->next = new_node; //appends the new node tothe end of the list making it the new last node

}

void deletenode(struct Node** head, int space){ 
	struct Node* temp = *head, *prev=NULL; // temp traverse the list
	if(temp!= NULL && temp->data == space) {
		*head = temp->next;
		free(temp);
		return;
	}

	while (temp != NULL && temp->data != space){
		prev = temp;
		temp = temp->next;
	}
	if (temp ==NULL)
		return;
	prev-> next = temp->next;
	free(temp);
}

void printlist(struct Node* node){ //traveses and prints the entire ll starting fromthe given node
	while (node != NULL){
		printf("%d", node->data);
		node = node->next;
	}
}

int main(){
	struct Node* head = NULL;
	insert(&head, 1);
	insert(&head, 2);
        insert(&head, 3);
        insert(&head, 4);
	printf("Linked List: ");

	printlist(head);
	deletenode(&head,2);

	printf("LL after deletion of node 2: ");
	printlist(head);

	return 0;
}





