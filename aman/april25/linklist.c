#include<stdio.h> //include standardinput output library for function printf
#include<stdlib.h> // include standard library for function like malloc, free
#include"linklist.h" // include a user define header file that i named as linklist.h
struct node *head = NULL; //this declares a global variable head, which also pointer to a structure of type node. and initialize it to NuLL
void printList(){ //defines a function printList which will print the elements of linklist
	struct node *p = head; //declare local pointervariable p  oftype  struct node andinitializing it to head of linklist
	printf("\n[");//it prints open square bracket to represent start of link list and \n for next line
	while (p != NULL){ // start loop that continue as long p is not NULL, indicating that there are still nodes to traverse
		printf("%d", p->data); //it prints the data of current node pointed by p and %d is format specifier for integer
		p = p->next; // it moves pointer p to next node in linklist.
	}
	printf("]");// it print closeing of  square brackets,represent end of linklist
}
void insertAtBegin(int data){ //define function insertatbegin to insert new node at begin of link list
	struct node *newNode = (struct node *)malloc(sizeof(struct node)); //a pointer new node is declare of type struct node and allocate memory fornewnode.and size ofmemory block is calculated by sizeof(structnode).
	newNode->data = data;// it assign the value of data to  data member of new created node i.e newnode
	newNode->next = head;//it sets next the pointer to new node to point to current head  of linklist
	head = newNode;//it update head pointer to newly inserted node  newnode  and make it new head of linklist
}
void insertAtEnd(int data){ //define function insertatend to insert new node at end of link list
	struct node *newNode = (struct node *)malloc(sizeof(struct node));//declare pointer newnode of type  structnode and allocate memory for newnode.
	newNode->data = data;//assigns value of data to the   data member of new created node new node
	newNode->next = NULL;//it sets next pointer of newnode to NULL,indicates that it is last node in linklist
	if(head == NULL){//here checks if linklist is empty by testing if head isNULL and if list is empty,i mean new node will the only node in linklist
		head = newNode;//if list is empty it sets head pointer to point to new inserted node new node,making it first and  only node in linklist
		return;//exists function since insert process is  complete in case where list is empty
	}
	struct node *temp  = head;//declare local variable temp of type struct node and initialize it to current head of linklist.it will be  used to traverse the list to finf last node
	while (temp->next != NULL){ // start loop that continue as long next pointer of  current node temp is not NULL, indicate temp is not last node in list
		temp = temp->next;//move temp pointer to point to next node in linklist
	}
	temp->next = newNode; //assign next pointer of last node temp to point to new creatednode newnode,and insert newnode at end of linklist

	return 0;
}
void freeList(){ //  define function freelist to free the memory allocated for all nodes in link list
	struct node *current = head; //it declare local pointer variavle current of type strct node and initialize it to current head of linklist
	struct node *next;//declares a local pointer next of type struct node and will be used to keep track of next node to be free while travering

	while(current != NULL){ //start a loop that continue aslong as current is not NULL,indicating there are still nodes to traverse in linklist
		next = current->next;//assign next pointer to point the next node in  linklist.andis done before free the current node to avoid losing track pf rest of list
		free(current);//it free the memory for the current node pointed by current
		current = next;//moves current pointer to point to next node in linklist
	}
	head = NULL;//after free all node,it sets pointer head to NULL,indicate that list is empty now
}
