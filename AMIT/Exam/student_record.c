#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the student record structure
struct Student {
    int student_id;
    char name[50];
    struct Student* next;
};

// Create a new student node
struct Student* createStudent(int id, const char* name) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent) {
        newStudent->student_id = id;
        strncpy(newStudent->name, name, sizeof(newStudent->name));
        newStudent->next = NULL;
    }
    return newStudent;
}

// Add a student to the list
void addStudent(struct Student** head, struct Student* newStudent) {
    if (!newStudent)
        return;

    newStudent->next = *head;
    *head = newStudent;
}

// Search for a student by ID
struct Student* searchStudentByID(struct Student* head, int id) {
    struct Student* current = head;
    while (current) {
        if (current->student_id == id)
            return current;
        current = current->next;
    }
    return NULL;
}

// Delete a student by ID
void deleteStudentByID(struct Student** head, int id) {
    struct Student* current = *head;
    struct Student* prev = NULL;

    while (current) {
        if (current->student_id == id) {
            if (prev)
                prev->next = current->next;
            else
                *head = current->next;
            free(current);
	    printf("Deleted Sudent with ID:%d\n",id);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Merge two sorted linked lists
struct Student* merge(struct Student* left, struct Student* right) {
    if (!left)
        return right;
    if (!right)
        return left;

    struct Student* result = NULL;
    if (strcmp(left->name, right->name) <= 0) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Merge sort for linked list , sorting student by name.
void mergeSort(struct Student** head) {  
    struct Student* current = *head;
    struct Student* left;
    struct Student* right;

    if (!current || !current->next)
        return;

    // Split the list into two halves
    left = current;
    right = current->next;
    while (right && right->next) {
        left = left->next;
        right = right->next->next;
    }

    // Recursively sort both halves
    right = left->next;
    left->next = NULL;
    mergeSort(&current);
    mergeSort(&right);

    // Merge the sorted halves
    *head = merge(current, right);
}

// Print all students sorted by name
void printStudentsSortedByName(struct Student* head) {
    mergeSort(&head); // Sort before printing
    struct Student* current = head;
    while (current) {
        printf("ID: %d, Name: %s\n", current->student_id, current->name);
        current = current->next;
    }
}



int main() {
    struct Student* head = NULL;

    // Add students
    addStudent(&head, createStudent(101, "Pratik"));
    addStudent(&head, createStudent(102, "Amit"));
    addStudent(&head, createStudent(103, "Shubham"));

    // Search for a student
    struct Student* foundStudent = searchStudentByID(head, 102);
    if (foundStudent)
        printf("Found student: %s\n", foundStudent->name);

    // Delete a student
    deleteStudentByID(&head, 103);

    // Print all students
    printf("\nAll students:\n");
    printStudentsSortedByName(head);

    // Clean up (free memory)
    while (head) {
        struct Student* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

