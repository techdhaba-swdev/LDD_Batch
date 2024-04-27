#include <stdio.h>
#include "ll.h"


// Initialize the linked list
void initLinkedList(struct LinkedList *list) {
    list->head = -1;//initialize head to -1, indicating an empty list
    list->tail = -1;//initialize tail to -1 , indicating an empty list
    list->size = 0;//initialize size to 0, indicate empty list
    for (int i = 0; i < MAX_NODES; i++) {
        list->nodes[i].next = -1; // Mark all nodes as unused by setting their next pointers to -1
    }
}

// Add a new node with the given value to the linked list
void addNode(struct LinkedList *list, int value) {
    if (list->size >= MAX_NODES) {//check if the list has reached its maximum capacity
        printf("Error: Linked list is full\n");//print the error message if linked list is full
        return;//return without adding the code
    }
    int newIndex = list->size;//determine  the index of new node
    list->nodes[newIndex].data = value;//set the data of new node to the given value
    list->nodes[newIndex].next = -1;//set next pointer of new node to -1,indicates end of the list
    if (list->size == 0) {//check  if  list is empty or not
        list->head = newIndex;//if empty then set head with index of new node
    } else {
        list->nodes[list->tail].next = newIndex;//if not empty .then update next pointer of previous tail nodeto poitnt to new node
    }
    list->tail = newIndex;//update the tail to index of new node
    list->size++;//increase size of ll
    }

// Calculate the sum of values in the linked list
int sumLinkedList(struct LinkedList *list) {
    int sum = 0;//intialize sum with zerp
    int currentIndex = list->head;//startv from head of list
    while (currentIndex != -1) {//interatee till reach end
        sum += list->nodes[currentIndex].data;//add data of current node to sum
        currentIndex = list->nodes[currentIndex].next;//move to next node
    }
    return sum;//return sum
}
