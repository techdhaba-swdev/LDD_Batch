#include <stdio.h>//to include input output library
#include "main.h"//to include main header file

int main() {
    struct LinkedList list;//declare a variable list of type struct LinkedList 
    initLinkedList(&list);//initialize linked list by calling the this function and passing a ponnter to list variable
    int numNodes, value;//declare variable to store number and value of node respectively

    // Ask the user for the number of nodes
    printf("Enter the number of nodes: ");//print messasge asking user to enteeeer the number of nodes he/she want
    scanf("%d", &numNodes);//reading number of nodes enter by user and storing it in numNodes

    // Ask the user to enter values for each node
    printf("Enter values for each node:\n");//ask user to enter the value of each node
    for (int i = 0; i < numNodes; i++) {//iterate numNodes times to receive value of each node
        printf("Node %d value: ", i + 1);//asking to enter values according to current node
        scanf("%d", &value);//reading value enter by user nd store it in variable value
        addNode(&list, value);//add a node with entered value to linked list by calling addNode function
    }

    // Print the sum of values
    printf("Sum of values: %d\n", sumLinkedList(&list));//calculate sum  of values in linked list by calling it

    return 0;//successful comp of program
}
