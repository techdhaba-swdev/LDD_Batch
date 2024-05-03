#ifndef FILESYSTEM_H
#define FILESYSTEM_H

// Node structure for file or directory
struct Node {
    char name[50];
    int isDirectory;
    struct Node* next;  // Linked list for files or subdirectories
    struct Node* child; // Linked list for subdirectories
};

// Function prototypes
struct Node* createNode(char name[], int isDirectory);
struct Node* createDirectory(char name[]);
struct Node* createFile(char name[]);
void addNode(struct Node* parent, struct Node* child);
void viewContents(struct Node* parent);
struct Node* navigate(struct Node* current, char name[]);
void deleteNode(struct Node* parent, char name[]);
void searchFile(struct Node* current, char name[]);

#endif
