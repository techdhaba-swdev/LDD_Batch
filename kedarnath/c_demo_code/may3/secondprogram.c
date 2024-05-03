#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for file node
typedef struct FileNode {
    char name[100];
    struct FileNode* next;
} FileNode;

// Define structure for directory node
typedef struct DirectoryNode {
    char name[100];
    struct DirectoryNode* parent;
    struct DirectoryNode* child;
    struct DirectoryNode* sibling;
    FileNode* files;
} DirectoryNode;

// Function prototypes
DirectoryNode* createDirectory(const char* name, DirectoryNode* parent);
void createFile(DirectoryNode* directory, const char* filename);
void listDirectoryContents(DirectoryNode* directory);
DirectoryNode* navigateDirectory(DirectoryNode* currentDirectory, const char* dirname);
void deleteDirectory(DirectoryNode* directory);
void deleteFile(DirectoryNode* directory, const char* filename);
void searchFile(DirectoryNode* directory, const char* filename);

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

// Main function
int main() {
    // Create root directory
    DirectoryNode* root = createDirectory("root", NULL);

    // Create some files in root directory
    createFile(root, "file1.txt");
    createFile(root, "file2.txt");
    createFile(root, "file3.txt");

    // List contents of root directory
    listDirectoryContents(root);

    // Create a subdirectory
    DirectoryNode* subDir = createDirectory("subdir", root);
    root->child = subDir;

    // Navigate into subdirectory
    printf("\nNavigating into subdir...\n");
    listDirectoryContents(subDir);

    // Search for a file in subdir
    printf("\nSearching for file 'file2.txt' in subdir...\n");
    searchFile(subDir, "file2.txt");

    // Delete a file from subdir
    printf("\nDeleting file 'file2.txt' from subdir...\n");
    deleteFile(subDir, "file2.txt");
    listDirectoryContents(subDir);

    // Delete subdir and root directories
    deleteDirectory(root);

    return 0;
}




