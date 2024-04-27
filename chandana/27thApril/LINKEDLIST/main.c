#include <stdio.h>
#include "linklist.h"
//Standard Input/Output library and header files

int main() {
	//Function call with meaningful variable names
    LinkedList* list = createLinkedList();

    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    addNode(list, 5);
//call the print function
    printf("List: ");
    printList(list);
//call the sun function
    int sum = sumList(list);
    printf("Sum of all elements: %d\n", sum);

    return 0;
    //Successfull indication of program termination.
}
