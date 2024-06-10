#ifndef HEADER_H
#define HEADER_H
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

BSTNode* createBSTNode(Student data);
BSTNode* addStudent(BSTNode* root, Student data);
BSTNode* searchStudent(BSTNode* root, int id);
BSTNode* findMin(BSTNode* root);
BSTNode* deleteStudent(BSTNode* root, int id);
void bstToList(BSTNode* root, ListNode** head);
ListNode* sortedMerge(ListNode* a, ListNode* b);
void splitList(ListNode* source, ListNode** front, ListNode** back);
void mergeSort(ListNode** headRef);
void printList(ListNode* head);
#endif
