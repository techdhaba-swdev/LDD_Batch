#include<stdio.h>
#include<stdlib.h>
#include "circularll.h"
void show(struct node* head){
	int choice,data;
	printf("\n circularll operations:\n");
	printf("1. Add elements to list:\n");
	printf("2.Display numbers:\n");
	printf("3.sum of numbers\n");
	printf("4.exit\n");
	switch(choice){
		case 1:
		printf("Enter elements to add:");
		scanf("%d",&data);
		append(&head,data);
		printf("Elements added:%d\n",data);
		break;
		case 2:
		printf("circularll :");
		display(head);
		break;
		case 3:
		printf("Sum of elements:\n");
		sum(head);
		break;
                case 4:
		printf("exit\n");
		return;
		default:
		printf("invalid\n");
		
	}
	show(head);
}
int main(){
	struct node* head = createcircularll();
	show(head);
	return 0;
}


		

