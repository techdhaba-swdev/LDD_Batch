#include <stdio.h>          // Include standard input-output library
#include <stdlib.h>         // Include standard library
#include <string.h>         // Include string library for string manipulation
#include "file_system.h"    // Include the header file containing function prototypes

// Define structures

struct FileInfo {          // Define structure for file information
    char name[50];         // Name of the file
    struct FileInfo* next; // Pointer to the next file in the list
};

struct Directory {          // Define structure for directory
    char name[50];          // Name of the directory
    struct Directory* parent;        // Pointer to parent directory
    struct Directory* children;      // Pointer to first child directory
    struct FileInfo* files;          // Pointer to files in this directory
    struct Directory* nextSibling;   // Pointer to next sibling directory
};

// Function implementations

struct Directory* createDirectory(struct Directory* parent, const char* name) {
    if (!name || strlen(name) == 0) {     // Check if directory name is valid
        printf("Error: Invalid directory name.\n");  // Print error message
        return NULL;                    // Return NULL indicating failure
    }

    struct Directory* newDir = (struct Directory*)malloc(sizeof(struct Directory)); // Allocate memory for new directory
    if (!newDir) {                      // Check if memory allocation failed
        printf("Error: Memory allocation failed.\n");  // Print error message
        return NULL;                    // Return NULL indicating failure
    }

    strcpy(newDir->name, name);        // Copy directory name
    newDir->parent = parent;            // Set parent directory
    newDir->children = NULL;            // Initialize children pointer
    newDir->files = NULL;               // Initialize files pointer
    newDir->nextSibling = NULL;         // Initialize next sibling pointer

    // Add the new directory to the parent's children list
    if (parent != NULL) {               // If parent directory exists
        struct Directory* child = parent->children;   // Get the first child directory
        if (child == NULL) {            // If no children exist
            parent->children = newDir; // Set the new directory as the first child
        } else {                       // If children already exist
            while (child->nextSibling != NULL) {  // Traverse to the last sibling
                child = child->nextSibling;
            }
            child->nextSibling = newDir;  // Add the new directory as the next sibling
        }
    }

    return newDir;                      // Return the new directory
}

void createFile(struct Directory* dir, const char* name) {
    if (!dir || !name || strlen(name) == 0) {  // Check if input is valid
        printf("Error: Invalid input for creating file.\n");  // Print error message
        return;                          // Return without creating file
    }

    struct FileInfo* newFile = (struct FileInfo*)malloc(sizeof(struct FileInfo));  // Allocate memory for new file
    if (!newFile) {                     // Check if memory allocation failed
        printf("Error: Memory allocation failed.\n");  // Print error message
        return;                          // Return without creating file
    }

    strcpy(newFile->name, name);       // Copy file name
    newFile->next = NULL;              // Initialize next pointer

    // Add the new file to the directory's files list
    struct FileInfo* file = dir->files;  // Get the first file in the directory
    if (file == NULL) {                // If no files exist
        dir->files = newFile;          // Set the new file as the first file
    } else {                           // If files already exist
        while (file->next != NULL) {   // Traverse to the last file
            file = file->next;
        }
        file->next = newFile;          // Add the new file at the end of the list
    }
}

void viewDirectoryContents(struct Directory* dir) {
    if (!dir) {                       // Check if directory is valid
        printf("Error: Invalid directory.\n");  // Print error message
        return;                          // Return without viewing contents
    }

    printf("Contents of directory '%s':\n", dir->name);  // Print directory name

    // Print files in the directory
    struct FileInfo* file = dir->files;
    while (file != NULL) {
        printf("File: %s\n", file->name);
        file = file->next;
    }

    // Print subdirectories in the directory
    struct Directory* subdir = dir->children;
    while (subdir != NULL) {
        printf("Directory: %s\n", subdir->name);
        subdir = subdir->nextSibling;
    }
}

struct Directory* navigateToDirectory(struct Directory* currentDir, const char* name) {
    if (!currentDir || !name || strlen(name) == 0) {  // Check if inputs are valid
        printf("Error: Invalid input for navigating to directory.\n");  // Print error message
        return NULL;                   // Return NULL indicating failure
    }

    struct Directory* subdir = currentDir->children;  // Get the first child directory
    while (subdir != NULL) {          // Traverse through children directories
        if (strcmp(subdir->name, name) == 0) {  // If directory found
            return subdir;             // Return the found directory
        }
        subdir = subdir->nextSibling;  // Move to next sibling directory
    }

    printf("Error: Directory '%s' not found.\n", name);  // Print error message
    return NULL;                       // Return NULL indicating failure
}

void deleteFile(struct Directory* dir, const char* name) {
    if (!dir || !name || strlen(name) == 0) {  // Check if input is valid
        printf("Error: Invalid input for deleting file.\n");  // Print error message
        return;                          // Return without deleting file
    }

    struct FileInfo* prev = NULL;       // Pointer to previous file
    struct FileInfo* current = dir->files;  // Pointer to current file

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {  // If file found
            if (prev == NULL) {         // If first file
                dir->files = current->next;  // Update files pointer
            } else {                     // If not first file
                prev->next = current->next;  // Update previous file's next pointer
            }
            free(current);              // Free memory for file
            return;
        }
        prev = current;                // Move to next file
        current = current->next;
    }

    printf("Error: File '%s' not found.\n", name);  // Print error message
}

void deleteDirectory(struct Directory* parent, const char* name) {
    if (!parent || !name || strlen(name) == 0) {  // Check if input is valid
        printf("Error: Invalid input for deleting directory.\n");  // Print error message
        return;                          // Return without deleting directory
    }

    struct Directory* prev = NULL;       // Pointer to previous directory
    struct Directory* current = parent->children;  // Pointer to current directory

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {  // If directory found
            if (prev == NULL) {         // If first directory
                parent->children = current->nextSibling;  // Update parent's children pointer
            } else {                     // If not first directory
                prev->nextSibling = current->nextSibling;  // Update previous directory's nextSibling pointer
            }
            free(current);              // Free memory for directory
            return;
        }
        prev = current;                // Move to next directory
        current = current->nextSibling;
    }

    printf("Error: Directory '%s' not found.\n", name);  // Print error message
}

struct FileInfo* searchFile(struct Directory* dir, const char* name) {
    if (!dir || !name || strlen(name) == 0) {  // Check if input is valid
        printf("Error: Invalid input for searching file.\n");  // Print error message
        return NULL;                   // Return NULL indicating failure
    }

    struct FileInfo* file = dir->files;  // Get the first file in the directory

    while (file != NULL) {
        if (strcmp(file->name, name) == 0) {  // If file found
            return file;                // Return pointer to the file
        }
        file = file->next;              // Move to next file
    }

    printf("Error: File '%s' not found.\n", name);  // Print error message
    return NULL;                       // Return NULL indicating failure
}
