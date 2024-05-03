#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"file.h"


// Create a new directory
struct Directory* createDirectory(const char* name) {
    struct Directory* newDir = (struct Directory*)malloc(sizeof(struct Directory));
    strcpy(newDir->name, name);
    newDir->subdirectories = NULL;
    newDir->files = NULL;
    return newDir;
}

// Create a new file
struct File* createFile(const char* name) {
    struct File* newFile = (struct File*)malloc(sizeof(struct File));
    strcpy(newFile->name, name);
    newFile->next = NULL;
    return newFile;
}

// List files and subdirectories in a directory
void listDirectoryContents(const struct Directory* dir) {
    printf("Contents of directory '%s':\n", dir->name);
    struct File* filePtr = dir->files;
    while (filePtr) {
        printf("File: %s\n", filePtr->name);
        filePtr = filePtr->next;
    }
    struct Directory* subDirPtr = dir->subdirectories;
    while (subDirPtr) {
        printf("Subdirectory: %s\n", subDirPtr->name);
        subDirPtr = subDirPtr->subdirectories;
    }
}

// Navigate into a subdirectory
struct Directory* navigateToSubdirectory(struct Directory* currentDir, const char* subDirName) {
    struct Directory* subDirPtr = currentDir->subdirectories;
    while (subDirPtr) {
        if (strcmp(subDirPtr->name, subDirName) == 0) {
            return subDirPtr;
        }
        subDirPtr = subDirPtr->subdirectories;
    }
    printf("Subdirectory '%s' not found.\n", subDirName);
    return NULL;
}

// Delete a file or directory
void delete(struct Directory* parentDir, const char* name) {
    struct File* filePtr = parentDir->files;
    struct File* prevFile = NULL;
    while (filePtr) {
        if (strcmp(filePtr->name, name) == 0) {
            if (prevFile) {
                prevFile->next = filePtr->next;
            } else {
                parentDir->files = filePtr->next;
            }
            free(filePtr);
            printf("File '%s' deleted.\n", name);
            return;
        }
        prevFile = filePtr;
        filePtr = filePtr->next;
    }
    printf("File '%s' not found.\n", name);
}

// Search for files by name
void searchFilesByName(const struct Directory* dir, const char* fileName) {
    struct File* filePtr = dir->files;
    while (filePtr) {
        if (strcmp(filePtr->name, fileName) == 0) {
            printf("Found file: %s\n", fileName);
            return;
        }
        filePtr = filePtr->next;
    }
    printf("File '%s' not found.\n", fileName);
}

