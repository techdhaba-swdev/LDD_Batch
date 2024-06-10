#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for student information
typedef struct Student {
    int id;
    char name[50];
} Student;

// Node structure for the linked list
typedef struct Node {
    Student data;
    struct Node* next;
} Node;

// Function to add a new student record 
void addStudent(Node** head, Student newStudent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newStudent;
    newNode->next = NULL;

    // If list is empty or new student should be first
    if (*head == NULL || strcmp((*head)->data.name, newStudent.name) > 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // Find the correct position in sorted list
        Node* current = *head;
        while (current->next != NULL && strcmp(current->next->data.name, newStudent.name) < 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to search for a student by id
Node* searchStudent(Node* head, int id) {
    Node* current = head;
    while (current != NULL) {
        if (current->data.id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a student record by id
void deleteStudent(Node** head, int id) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL && current->data.id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return; 
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Function to print all students by name in ascending order
void printStudents(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s\n", current->data.id, current->data.name);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    
    Student student1 = {1, "Dhriti"};
    addStudent(&head, student1);

    Student student2 = {2, "Sravani"};
    addStudent(&head, student2);

    Student student3 = {3, "Badrinath"};
    addStudent(&head, student3);

    
    printf("Students sorted by name:\n");
    printStudents(head);

    // Search for a student
    int search_id = 1;
    Node* foundStudent = searchStudent(head, search_id);
    if (foundStudent != NULL) {
        printf("Student found: %s\n", foundStudent->data.name);
    } else {
        printf("Student not found\n");
    }

    // Delete a student record by id
    int delete_id = 3;
    deleteStudent(&head, delete_id);

    
    printf("\nStudents sorted by name after deletion:\n");
    printStudents(head);

    return 0;
}
