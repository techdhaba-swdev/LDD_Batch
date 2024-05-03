#include "filesystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new node (file or directory)
struct Node* createNode(char name[], int isDirectory) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->isDirectory = isDirectory;
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

// Function to create a new directory
struct Node* createDirectory(char name[]) {
    return createNode(name, 1); // 1 indicates directory
}

// Function to create a new file
struct Node* createFile(char name[]) {
    return createNode(name, 0); // 0 indicates file
}

// Function to add a child node to a parent node
void addNode(struct Node* parent, struct Node* child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        struct Node* current = parent->child;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = child;
    }
}

// Function to view contents of a directory
void viewContents(struct Node* parent) {
    printf("Contents of directory '%s':\n", parent->name);
    struct Node* current = parent->child;
    while (current != NULL) {
        printf("%s %s\n", current->isDirectory ? "Directory:" : "File:", current->name);
        current = current->next;
    }
}

// Function to navigate to a subdirectory
struct Node* navigate(struct Node* current, char name[]) {
    struct Node* child = current->child;
    while (child != NULL) {
        if (strcmp(child->name, name) == 0 && child->isDirectory) {
            return child;
        }
        child = child->next;
    }
    printf("Subdirectory '%s' not found.\n", name);
    return current;
}

// Function to delete a file or directory
void deleteNode(struct Node* parent, char name[]) {
    struct Node* current = parent->child;
    struct Node* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->isDirectory && current->child != NULL) {
                printf("Cannot delete non-empty directory '%s'.\n", name);
                return;
            }
            if (prev == NULL) {
                parent->child = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("'%s' deleted successfully.\n", name);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("'%s' not found.\n", name);
}

// Function to search for a file by name
void searchFile(struct Node* current, char name[]) {
    if (!current->isDirectory) {
        if (strcmp(current->name, name) == 0) {
            printf("File '%s' found.\n", name);
            return;
        }
    }
    struct Node* child = current->child;
    while (child != NULL) {
        if (!child->isDirectory && strcmp(child->name, name) == 0) {
            printf("File '%s' found.\n", name);
            return;
        }
        searchFile(child, name);
        child = child->next;
    }
}
