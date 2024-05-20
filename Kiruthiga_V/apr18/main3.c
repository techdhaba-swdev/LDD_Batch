#include<stdio.h>
#include"linklist2.h"
int main(){
struct Node* head = NULL;
int data, sum = 0;
printf("enter the five integers to insert in to circular linked list");
for (int i = 0; i<5; ++i)
{
	printf("enter data for node %d", i + 1);
	scanf("%d", &sum);
	head = insertNode(head,sum);
}
int total = sumValues(head);

	printf("sum of elements in the circular linked lists:%d\n",total);
	return 0;
}
