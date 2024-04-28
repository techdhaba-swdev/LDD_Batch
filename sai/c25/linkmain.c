#include "linklist.h"

void printmessage(const char *message);//Function calling const character

int main()
{
	struct Node* head = NULL;

	insertatbeg(&head,15);//Insert value head 5
	insertatbeg(&head,5);
	insertatbeg(&head,10);

	printmessage("Linkedlist:\n");//Print Linklist
        printList(head);//struct Printlist value 
	return 0;
}

void printmessage(const char* message)
{
	printf("%s",message);// Given print message character
}
