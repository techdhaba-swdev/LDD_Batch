#include"file.h"



// Create a directory
DirectoryNode* createDirectory(const char* name, DirectoryNode* parent) {
DirectoryNode* newDir = (DirectoryNode*)malloc(sizeof(DirectoryNode));
if (newDir == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
}
strcpy(newDir->name, name);
newDir->parent = parent;
newDir->child = NULL;
newDir->sibling = NULL;
newDir->files = NULL;
return newDir;
}

// Create a file in a directory
void createFile(DirectoryNode* directory, const char* filename) {
FileNode* newFile = (FileNode*)malloc(sizeof(FileNode));
if (newFile == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
}
strcpy(newFile->name, filename);
newFile->next = directory->files;
directory->files = newFile;
}

// List contents of a directory
void listDirectoryContents(DirectoryNode* directory) {
printf("Directory: %s\n", directory->name);
printf("Files:\n");
FileNode* currentFile = directory->files;
while (currentFile != NULL) {
    printf("%s\n", currentFile->name);
    currentFile = currentFile->next;
}
}

// Navigate into a subdirectory
DirectoryNode* navigateDirectory(DirectoryNode* currentDirectory, const char* dirname) {
DirectoryNode* temp = currentDirectory->child;
while (temp != NULL) {
    if (strcmp(temp->name, dirname) == 0)
        return temp;
    temp = temp->sibling;
}
printf("Directory '%s' not found\n", dirname);
return NULL;
}

// Delete a directory and its contents
void deleteDirectory(DirectoryNode* directory) {
if (directory == NULL)
    return;
deleteDirectory(directory->child);
deleteDirectory(directory->sibling);
free(directory);
}

// Delete a file from a directory
void deleteFile(DirectoryNode* directory, const char* filename) {
FileNode* currentFile = directory->files;
FileNode* prevFile = NULL;

// Traverse the file list to find the file to be deleted
while (currentFile != NULL && strcmp(currentFile->name, filename) != 0) {
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
    if (strcmp(currentFile->name, filename) == 0) {
        printf("File '%s' found in directory '%s'\n", filename, directory->name);
        return;
    }
    currentFile = currentFile->next;
}
printf("File '%s' not found in directory '%s'\n", filename, directory->name);
}


