#include<stdio.h>
#include"circular.h"
#include<stdlib.h>

int main(){
	struct Node *last=NULL;
	int length,size,data;
	 
	printf("Enter the length of list: ");
	scanf("%d", &length);

	printf("Enter %d elements for the list: \n",length);
	for(i=0;i<length;i++){
		printf("Elements %d: ",i+1);
		scanf("%d",&data);
		list = inserEnd(last, data);
	}

	printf("The circular linked list is :");
	printList(last);

	return 0;
}
