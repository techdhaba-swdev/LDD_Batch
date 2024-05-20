#include "main.h"
int main() {
	 struct node *head = createLinkedlist(); // created linked list of nodes
	 show(head);// function that shows the elements of linked list
         freelinkedlist(head);// deallocate the memory from memory leaks

	 return 0;
}
