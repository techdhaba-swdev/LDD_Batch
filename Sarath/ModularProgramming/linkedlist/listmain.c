#include<stdio.h>
#include"linkedlist.h"
int main()
{
	struct node *head=NULL;	//declared a head node with NULL as initially head points to nothing unless we insert an elemnt
	
	//inserting elements both start and end
	insert_at_start(30); 
        insert_at_start(20);
        insert_at_start(10);
        insert_at_end(40);
        insert_at_end(50);
        
	//printing the required output using print API
	print();
        return 0;
}
