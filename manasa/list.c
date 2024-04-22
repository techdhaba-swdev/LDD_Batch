#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
} Node;
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
Node* insertAtBeginning(Node* head, int data) {
	Node* newNode = createNode(data);
	newNode->next = head;
	return newNode;
}
Node* insertAtEnd(Node* head, int data) {
	Node* newNode = createNode(data);
       if (head == NULL) {
       return newNode;
       }
Node* current = head;
while (current->next != NULL) {
	current = current->next;
}
current->next = newNode;
return head;
}
Node* deleteNode(Node* head, int key) {
	Node* prev = NULL;
	Node* current = head;
	while (current != NULL && current->data != key) {
		prev = current;
		current = current->next;
	}
	if (prev == NULL) {
		return head;
	}
	if (prev == NULL) {
		head = head->next;
	} else {
		prev->next = current->next;
	}
	free(current);
	return head;
}
void printLinkedList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}
void freeLinkedList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		Node* temp = current;
		current = current->next;
		free(temp);
	}
}
int main() {
	Node* head = NULL;
	head = insertAtBeginning(head, 3);
	head = insertAtBeginning(head, 2);
	head = insertAtBeginning(head, 1);
	printf("Linked list after inserting at the beginning: ");
	printLinkedList(head);
	head = insertAtEnd(head, 4);
	head = insertAtEnd(head, 5);
	head = insertAtEnd(head, 6);
	printf("Linked list after inserting ata the end: ");
	printLinkedList(head);
	head = deleteNode(head, 3);
	printf("Linked list after deleting node with value 3: ");
	printLinkedList(head);
	freeLinkedList(head);
	return 0;
}


