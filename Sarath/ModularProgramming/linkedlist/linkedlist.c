#include<stdio.h> //header file which has library functions like printf and scanf...
#include"linkedlist.h" //header file which we creaeted for our API's
#include<stdlib.h> //header file of standard library functions such as dynamic memory allocation malloc(),calloc()...
struct node //created a structure(defining)
{
	int data; //declared a variable which stores integer
	struct node *next; //created a pointer which points to structure for traversing
};
struct node *head=NULL;
void insert_at_start(int data) //defined insertion at start API
{
        struct node *temp=malloc(sizeof(struct node));  //created a dynamic space to store data and named temp
        temp->data=data; //assigned data to  created pointer in before step
        if(head==NULL)
        {
                head=temp; //as first element has no next node loop enters and assign temp into head
                return ;
        }
        temp->next=head; //from second push loop breaks every time as head is not null from second push
			//temp will store the head address
        head=temp; //so head will be reassigned to temp as this is insert at start API

}
void insert_at_end(int data) //defined insertion at end API
{
        struct node *temp=malloc(sizeof(struct node)); //created dynamic space using malloc and declared as temp
        struct node *ptr=head; //re initialising head for traversing throughout list
        temp->data=data; //assigning data into temp
        while(ptr->next!=NULL) 
        {
                ptr=ptr->next; //loop rotates untill next node address will be NULL which is last node
        }
        ptr->next=temp; //when while loop breaks the temp will be locked into ptr
        temp->next=NULL; //making the last element next node address as NULL 
}
void print() //printed the sum of all elements of list using print() API
{
        struct node *ptr=head; //re initialised head with ptr for traversing through list
        int result=0; //declaring a variable named result to store sum and initially assigned zero
	printf("List elements:");
	while(ptr!=NULL) //loop functions untill last node as last node
	{
		result=result+ptr->data; //adding all the elements and assigned to result everytime
		printf("%d ",ptr->data); //printing every element of the list
		ptr=ptr->next; //so that everytime ptr will be updated to next node
	}
        printf("\nSum of list is %d\n",result); //printed the sum of list elements using printf library function
}

