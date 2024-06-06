
#include <stdio.h>
#include "clinklist.h"

int main(){
	Node* head_f = NULL;
	char inp[100];
	printf("Enter numbers: ");
	fgets(inp, sizeof(inp), stdin);
	char *ptr = inp;
	int num;
	while(sscanf(ptr, "%d", &num)==1) {
		insert(&head_f, num);
		ptr++;
	}

	printf("Circular LK: ");
	inputs(head_f);
	printf("Sum of the numbers: %d\n", sum(head_f));
	return 0;
}
