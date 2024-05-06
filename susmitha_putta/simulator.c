#include "simulator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Directory* createDirectory(char* name) {
    Directory* newDirectory = (Directory*)malloc(sizeof(Directory));
    if (newDirectory == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newDirectory->name, name);
    newDirectory->subdirectories = NULL;
    newDirectory->files = NULL;
    newDirectory->next = NULL;
    return newDirectory;
}

File* createFile(char* name) {
    File* newFile = (File*)malloc(sizeof(File));
    if (newFile == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newFile->name, name);
    newFile->next = NULL;
    return newFile;
}

void addDirectory(Directory** root, char* name) {
    Directory* newDirectory = createDirectory(name);
    newDirectory->next = *root;
    *root = newDirectory;
}

void addFile(Directory* directory, char* name) {
    File* newFile = createFile(name);
    newFile->next = directory->files;
    directory->files = newFile;
}

void viewDirectoryContents(Directory* directory) {
    printf("Directory: %s\n", directory->name);
    printf("Files:\n");
    File* filePtr = directory->files;
    while (filePtr != NULL) {
        printf("- %s\n", filePtr->name);
        filePtr = filePtr->next;
    }
    printf("Subdirectories:\n");
    Directory* subdirectoryPtr = directory->subdirectories;
    while (subdirectoryPtr != NULL) {
        printf("- %s\n", subdirectoryPtr->name);
        subdirectoryPtr = subdirectoryPtr->next;
    }
}

Directory* navigateToSubdirectory(Directory* root, char* name) {
    Directory* current = root->subdirectories;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->next;
    }
    printf("Subdirectory '%s' not found.\n", name);
    return NULL;
}

void deleteFile(Directory* directory, char* name) {
    File* current = directory->files;
    File* prev = NULL;
    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("File '%s' not found.\n", name);
        return;
    }
    if (prev == NULL)
        directory->files = current->next;
    else
        prev->next = current->next;
    free(current);
}

void deleteDirectory(Directory** root, char* name) {
    Directory* current = *root;
    Directory* prev = NULL;
    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Directory '%s' not found.\n", name);
        return;
    }
    if (prev == NULL)
        *root = current->next;
    else
        prev->next = current->next;
    free(current);
}

File* searchFile(Directory* directory, char* name) {
    File* current = directory->files;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

