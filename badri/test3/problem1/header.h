#ifndef HEADER_H //checks weather header file included previous
#define HEADER_H//defines header file atleast one time
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student record
typedef struct Student {
    int id;
    char name[100];
} Student;

// Define the node structure for the binary search tree (BST)
typedef struct BSTNode {
    Student data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Define the node structure for the linked list
typedef struct ListNode {
    Student data;
    struct ListNode* next;
} ListNode;

BSTNode* createBSTNode(Student data);//function to create new binary search tree node
BSTNode* addStudent(BSTNode* root, Student data);//function to add a student to bst
BSTNode* searchStudent(BSTNode* root, int id);//fuction to search for a student by id in the bst
BSTNode* findMin(BSTNode* root);//function to find the minimum node in the bst
BSTNode* deleteStudent(BSTNode* root, int id);//function to delete a student by id from the bst
void bstToList(BSTNode* root, ListNode** head);//function to convert the bst to a linked list
ListNode* sortedMerge(ListNode* a, ListNode* b);//function to merge two sorted linked lists
void splitList(ListNode* source, ListNode** front, ListNode** back);//function to split a linked list in to two halves
void mergeSort(ListNode** headRef);//function to sort the linked list using merge sort
void printList(ListNode* head);//function to print the linked list
#endif//end of ifndef directive
