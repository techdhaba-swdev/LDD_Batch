#include<stdio.h>
#include "doublelink.h"

struct Node* createNode(int data);
void addNode(struct Node**  head,int data);
int sumallNodes(struct Node* head);
void printList(struct Node* head);

int main() {
	struct Node* head =NULL;

	addNode(&head,1);
	addNode(&head,2);
	addNode(&head,3);
	addNode(&head,4);
	addNode(&head,5);
   
       printf("Elements are : ");	
	printList(head);

	int sum=sumAllNodes(head);
	printf("sum is %d \n",sum);

	return 0;
}
