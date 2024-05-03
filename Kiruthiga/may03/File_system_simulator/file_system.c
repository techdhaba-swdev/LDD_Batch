#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "file_system.h"
// Create a new file node
struct FileNode* createFileNode(char* name, bool isDirectory) {
    struct FileNode* newNode = (struct FileNode*)malloc(sizeof(struct FileNode));
    strcpy(newNode->name, name);
    newNode->isDirectory = isDirectory;
    newNode->next = NULL;
    return newNode;
}

// Create a new directory node
struct DirNode* createDirNode(char* name, struct DirNode* parent) {
    struct DirNode* newNode = (struct DirNode*)malloc(sizeof(struct DirNode));
    strcpy(newNode->name, name);
    newNode->parent = parent;
    newNode->files = NULL;
    newNode->subdirs = NULL;
    newNode->next = NULL;
    return newNode;
}

// Create a new directory in the file system
void createDirectory(struct DirNode* parent, char* name) {
    struct DirNode* newDir = createDirNode(name, parent);
    if (parent->subdirs == NULL) {
        parent->subdirs = newDir;
    } else {
        struct DirNode* temp = parent->subdirs;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newDir;
    }
}

// Create a new file in the directory
void createFile(struct DirNode* dir, char* name, bool isDirectory) {
    struct FileNode* newFile = createFileNode(name, isDirectory);
    if (dir->files == NULL) {
        dir->files = newFile;
    } else {
        struct FileNode* temp = dir->files;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newFile;
    }
}

// Print directory contents (files and subdirectories)
void printDirContents(struct DirNode* dir) {
    struct FileNode* file = dir->files;
    struct DirNode* subdir = dir->subdirs;

    printf("Directory: %s\n", dir->name);

    printf("Files:\n");
    while (file != NULL) {
        printf("- %s\n", file->name);
        file = file->next;
    }

    printf("Subdirectories:\n");
    while (subdir != NULL) {
        printf("- %s\n", subdir->name);
        subdir = subdir->next;
    }
}

// Delete file from directory
void deleteFile(struct DirNode* dir, char* name) {
    struct FileNode* prev = NULL;
    struct FileNode* current = dir->files;

    // Find the file
    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    // File not found
    if (current == NULL) {
        printf("File not found\n");
        return;
    }

    // Delete file node
    if (prev == NULL) {
        dir->files = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Delete directory and its contents recursively
void deleteDirectory(struct DirNode* dir) {
    struct DirNode* subdir = dir->subdirs;
    struct DirNode* temp;

    // Delete subdirectories
    while (subdir != NULL) {
        temp = subdir;
        subdir = subdir->next;
        deleteDirectory(temp);
    }

    // Delete files
    struct FileNode* file = dir->files;
    struct FileNode* tempFile;
    while (file != NULL) {
        tempFile = file;
        file = file->next;
        free(tempFile);
    }

    // Free directory node
    free(dir);
}

// Search for file by name in directory and subdirectories
void searchFile(struct DirNode* dir, char* name) {
    struct FileNode* file = dir->files;
    while (file != NULL) {
        if (strcmp(file->name, name) == 0) {
            printf("File found: %s\n", file->name);
            return;
        }
        file = file->next;
    }

    struct DirNode* subdir = dir->subdirs;
    while (subdir != NULL) {
        searchFile(subdir, name);
        subdir = subdir->next;
    }
}

