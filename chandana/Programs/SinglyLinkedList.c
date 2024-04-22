#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	int data;
	struct Node* next;
};

struct LinkedList {
	struct Node* head;
};

struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}
void insertNode(struct LinkedList* list,int data) {
	struct Node* newNode=createNode(data);
	newNode->next=list->head;
	list->head=newNode;
}
void deleteNode(struct LinkedList* list,int key){
	struct Node* temp=list->head;
	struct Node* prev=NULL;

	if(temp!=NULL && temp->data==key){
		list->head=temp->next;
		free(temp);
		return;
	}
	while (temp!=NULL && temp->data!=key) {
		prev =temp;
		temp=temp->next;
	}

	if(temp==NULL) 
	return;

	prev->next=temp->next;
	free(temp);
}void printList(struct LinkedList* list) {
	struct Node* temp = list->head;
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	struct LinkedList list;
	list.head=NULL;

	insertNode(&list,1);
	insertNode(&list,2);
	insertNode(&list,3);
	insertNode(&list,4);
	printf("Original List: " );
	printList(&list);

	deleteNode(&list,3);

	printf("List after deleting 3: ");
	printList(&list);
	return 0;
}

