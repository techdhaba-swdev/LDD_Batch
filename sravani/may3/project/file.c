#include<stdio.h>
#include<stdlib.h>
#include "file.h"
// Create a directory
DirectoryNode* createDir(const char* data, DirectoryNode* main) {
	//allocate memory for a new directory node
DirectoryNode* newDir = (DirectoryNode*)malloc(sizeof(DirectoryNode));
if (newDir == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);//exit program
}
//copy the dir data into the new node names field
strcpy(newDir->data, data);
//set the main pointer of the new node
newDir->main = main;
newDir->sub = NULL;//initially all are null
newDir->sibling = NULL;
newDir->files = NULL;
//return the newly created directory node
return newDir;
}

// Create a file in a directory
void createFiles(DirectoryNode* directory, const char* filename) {
	//allocate memory
FileNode* newFile = (FileNode*)malloc(sizeof(FileNode));
if (newFile == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
}
//copy file data into the new nodes name field
strcpy(newFile->data, filename);
//aet the next file into current file
newFile->next = directory->files;
//updating files list
directory->files = newFile;
}

// List contents of a directory
void listDir(DirectoryNode* directory) {
printf("directory: %s\n", directory->data);
printf("files:\n");
FileNode* currentFile = directory->files;
while (currentFile != NULL) {
    printf("%s\n", currentFile->data);
    currentFile = currentFile->next;
}
}

// Navigate into a subdirectory
DirectoryNode* navigateDir(DirectoryNode* currentDirectory, const char* dirname) {
DirectoryNode* temp = currentDirectory->sub;
while (temp != NULL) {
    if (strcmp(temp->data, dirname) == 0)
        return temp;
    temp = temp->sibling;
}
printf("directory '%s' not found\n", dirname);
return NULL;
}

// Delete a directory and its contents
void deleteDir(DirectoryNode* directory) {
if (directory == NULL)
    return;
deleteDir(directory->sub);
deleteDir(directory->sibling);
free(directory);
}

// Delete a file from a directory
void deleteFile(DirectoryNode* directory, const char* filename) {
FileNode* currentFile = directory->files;
FileNode* prevFile = NULL;

// Traverse the file list to find the file to be deleted
while (currentFile != NULL && strcmp(currentFile->data, filename) != 0) {
    prevFile = currentFile;
    currentFile = currentFile->next;
}

// If file not found
if (currentFile == NULL) {
    printf("File '%s' not found\n", filename);
    return;
}

// If file found, remove it from the list
if (prevFile == NULL)
    directory->files = currentFile->next;
else
    prevFile->next = currentFile->next;

free(currentFile);
}

// Search for a file in a directory
void searchFile(DirectoryNode* directory, const char* filename) {
FileNode* currentFile = directory->files;
while (currentFile != NULL) {
    if (strcmp(currentFile->data, filename) == 0) {
        printf("file '%s' found in directory '%s'\n", filename, directory->data);
        return;
    }
    currentFile = currentFile->next;
}
printf("file '%s not found '%s'\n", filename, directory->data);
}
