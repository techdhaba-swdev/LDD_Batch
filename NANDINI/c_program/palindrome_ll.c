#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
int data;
struct node *next;
};
struct node *head, *tail = NULL;
int size = 0;
void addnode(int data)
{
struct node *newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = data;
newnode->next = NULL;
if(head == NULL)
{
head = newnode;
tail = newnode;
}
{
tail->next = newnode;
tail = newnode;
}
size++;
}
struct node* reverselist(struct node *temp)
{
struct node *current = temp;
struct node *prevnode = NULL, *nextnode = NULL;
while(current != NULL)
{
nextnode = current->next;
current->next = prevnode;
prevnode = current;
current = nextnode;
}
return prevnode;
}
void ispalindrome()
{
struct node *current = head;
bool flag = true;
int mid = (size%2 == 0)?(size/2):((size+1)/2);
for(int i=1; i<mid; i++)
{
current = current->next;
}
struct node *revhead = reverselist(current->next);
while(head != NULL && revhead != NULL)
{
if(head->data != revhead->data)
{
flag = false;
break;
}
head = head->next;
revhead = revhead->next;
}
if(flag)
printf("given singly linked list is a palindrome\n");
else
printf("goven singly linked list is not a palindromr\n");
}
void display()
{
struct node *current = head;
if(head == NULL)
{
printf("list is empty\n");
return;
}
printf("nodes of singly linked list: \n");
while(current != NULL)
{
printf("%d", current->data);
current = current->next;
}
printf("\n");
}

int main()
{
addnode(1);
addnode(2);
addnode(3);
addnode(2);
addnode(1);
display();
ispalindrome();
return 0;
}

