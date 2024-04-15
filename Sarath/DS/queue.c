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
	struct node*temp=malloc(sizeof(struct node));
    struct node *ptr=head;
    temp->data=data;
    if(head==NULL)
    {
        head=temp;
        return;
    }
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->next=NULL;
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
