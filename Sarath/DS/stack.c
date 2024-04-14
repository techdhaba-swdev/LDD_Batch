#include <stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *head=NULL;
void push(int data)
{
    struct stack *ptr=malloc(sizeof(struct stack));
    struct stack *temp=head;
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->next=NULL;
}
int pop()
{
    struct stack *ptr=head;
    while(ptr->next!=NULL && ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    printf("\n");
   
    if(ptr->next==NULL)
    {
        head=NULL;
        return ptr->data;
    }
    if(ptr->next->next==NULL)
    {
       
        int p= ptr->next->data;
        ptr->next=NULL;
        return p;
    }
   /* int p=ptr->next->data;
    ptr->next=NULL;
    return p;*/
}
int peek()
{
    struct stack *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    return temp->data;
}
void print()
{
    struct stack *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    push(10);
    print();
    int a = pop();
    printf("Poped element is %d\n",a);
    push(50);
    push(20);
    push(30);
    push(40);
    print();
    int p1=pop();
    printf("Poped element is %d\n",p1);
    print();
    int p2=pop();
    //print();
    printf("Poped element is %d\n",p2);
    print();
    int p=peek();
    printf("\nPeek element is %d",p);
    return 0;
}
