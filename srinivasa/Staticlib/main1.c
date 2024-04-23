#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"linkedlist.h"
struct node{
        int data;
        struct node *next;
};
int sumlinkedlist(struct node* head);

int main()
{

struct node *head = createnode(1);
head->next = createnode(2);
head->next->next = createnode(3);
head->next->next->next = createnode(4);
head->next->next->next->next = createnode(5);

 int sum = sumlinkedlist(head);
 printf("sum = %d\n",sum);
 return 0;
}

