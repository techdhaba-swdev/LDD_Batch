#include<stdio.h>
#include "linklist1.h"
int main()
{
Node *head = createLinkedList();
int sum = sumLinkedList(head);
printf("sum of all values:%d\n",sum);
freeLinkedList(head);
}
