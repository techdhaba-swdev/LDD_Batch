#include<stdio.h>
#include "circularlist.h"
int main(){
	Node* head = NULL;
	for (int i=1; i<= 5; i++){
		head = insertNode(head, i);
	}
	printf("Circular List: ");
	displayList(head);
	int sum = sumAllNodes(head);
	printf("Sum of all nodes' values: %d\n", sum);
	return 0;
}
