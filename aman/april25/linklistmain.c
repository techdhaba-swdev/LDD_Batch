#include<stdio.h>//standard input output library required for function printf
#include "linklist.h"//user define header file containing declartion for   related linklist
int main(){ //starting point of main function,also entry point
	insertAtBegin(12);//call function insertatbegin , which insert a new node with value 12
	insertAtBegin(22);
	insertAtEnd(30);// call function insertatend, which insert a newnode 30 at end of link list


	printf("Linked List: ");//print the string called Linked List
	printList();// calls function printlist
	freeList();//calls function freelist
	return 0;//denote successful completion of program
}
