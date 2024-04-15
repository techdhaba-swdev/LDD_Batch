#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void enqueue(int data)
{
    struct node*ptr=malloc(sizeof(struct node));
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
        return;
    }
    ptr->next=head;
    head=ptr;
}
int dequeue()
{
    printf("\n");
    int p=head->data;
    head=head->next;
    return p;
}
void print()
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    enqueue(40);
    enqueue(30);
    enqueue(20);
    enqueue(10);
    print();
    int d1=dequeue();
    printf("Dequeued element is %d\n",d1);
    print();
    int d2=dequeue();
    printf("Dequeued element is %d\n",d2);
    print();

    return 0;
}
