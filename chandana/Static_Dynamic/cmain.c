#include <stdio.h>
#include "clink.h"

int main() {
	int n;
	printf("Enter the length of the circular linked list :");
	scanf("%d",&n);

	Node* head=createList(n);
	display(head);

	return 0;
}
