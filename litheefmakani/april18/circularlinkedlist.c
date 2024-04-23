#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
//function to insert a new node at the end of the list
void insert(struct Node** head_ref,int data){
	//allocate memory for new node
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = *head_ref; //to traverse the list to find the
	//assign data to new node
	new_node->data = data;
	new_node->next = *head_ref; //make next of new node as head
        //if the list is empty, then make the new node as head
	if(*head_ref == NULL){
		new_node->next = new_node;
	}else{
		//otherwise, traverse the list to find the last node
		while(last->next != *head_ref){
			last = last->next;
		}
		last->next = new_node;
	}
	*head_ref = new_node;
}
//function to print the circular linked list
void printList(struct Node* head){
	struct Node* temp = head;
	//if the list is empty, return 
	if(head==NULL){
		printf("List is empty.\n");
		return;
	}
	//traverse the list starting from head
	do{
		printf("%d",temp->data);
		temp = temp->next;
	}while(temp != head); //stop when we reach back to the head
        printf("\n");
}
int main(){
	struct Node* head = NULL;
	int length,data;
	//ask the user for the length of the list
	printf("Enter the length of the circular linked list:");
	scanf("%d",&length);
	//ask the user for the elements of the list
	printf("Enter the elements of the circular linked list:\n");
	for(int i=0;i<length;i++){
		scanf("%d",&data);
		insert(&head, data); //insert the data into the list
	}
	//print      the circular linked list
	printf("circular linked list:");
	printList(head);
	return 0;
}

