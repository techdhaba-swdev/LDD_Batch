#include "file_system.h" // Including header file for file system functionality
#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation and other functions
#include <string.h> // Including string manipulation functions

// Global variables for root directory and current directory
Directory* rootDirectory = NULL; // Declaration and initialization of root directory pointer
Directory* currentDirectory = NULL; // Declaration and initialization of current directory pointer

void initializeFileSystem() {
    rootDirectory = (Directory*)malloc(sizeof(Directory)); // Allocating memory for root directory
    rootDirectory->name = strdup("root"); // Setting name of root directory
    rootDirectory->parent = NULL; // Setting parent directory of root directory to NULL
    rootDirectory->subdirectories = NULL; // Setting subdirectories of root directory to NULL
    rootDirectory->files = NULL; // Setting files in root directory to NULL
    rootDirectory->next = NULL; // Setting next directory pointer to NULL
    currentDirectory = rootDirectory; // Setting current directory to root directory
}

void createDirectory(const char* name) {
    Directory* newDirectory = (Directory*)malloc(sizeof(Directory)); // Allocating memory for new directory
    newDirectory->name = strdup(name); // Setting name of new directory
    newDirectory->parent = currentDirectory; // Setting parent directory of new directory
    newDirectory->subdirectories = NULL; // Setting subdirectories of new directory to NULL
    newDirectory->files = NULL; // Setting files in new directory to NULL
    newDirectory->next = NULL; // Setting next directory pointer to NULL

    if (currentDirectory->subdirectories == NULL) { // Checking if current directory has no subdirectories
        currentDirectory->subdirectories = newDirectory; // Setting new directory as the first subdirectory
    } else { // If current directory has existing subdirectories
        Directory* temp = currentDirectory->subdirectories; // Temporary pointer to traverse existing subdirectories
        while (temp->next != NULL) { // Looping until last subdirectory is reached
            temp = temp->next; // Moving to next subdirectory
        }
        temp->next = newDirectory; // Adding new directory to the end of subdirectories list
    }
}

void createFile(const char* name, int size) {
    File* newFile = (File*)malloc(sizeof(File)); // Allocating memory for new file
    newFile->name = strdup(name); // Setting name of new file
    newFile->size = size; // Setting size of new file
    newFile->next = NULL; // Setting next file pointer to NULL

    if (currentDirectory->files == NULL) { // Checking if current directory has no files
        currentDirectory->files = newFile; // Setting new file as the first file in directory
    } else { // If current directory has existing files
        File* temp = currentDirectory->files; // Temporary pointer to traverse existing files
        while (temp->next != NULL) { // Looping until last file is reached
            temp = temp->next; // Moving to next file
        }
        temp->next = newFile; // Adding new file to the end of files list
    }
}

void viewDirectoryContents(const char* directoryName) {
    Directory* temp = currentDirectory->subdirectories; // Temporary pointer to traverse subdirectories
    while (temp != NULL) { // Looping through subdirectories
        printf("Directory: %s\n", temp->name); // Printing name of each subdirectory
        temp = temp->next; // Moving to next subdirectory
    }

    File* fileTemp = currentDirectory->files; // Temporary pointer to traverse files
    while (fileTemp != NULL) { // Looping through files
        printf("File: %s, Size: %d\n", fileTemp->name, fileTemp->size); // Printing name and size of each file
        fileTemp = fileTemp->next; // Moving to next file
    }
}

void navigateIntoDirectory(const char* directoryName) {
    Directory* temp = currentDirectory->subdirectories; // Temporary pointer to traverse subdirectories
    while (temp != NULL) { // Looping through subdirectories
        if (strcmp(temp->name, directoryName) == 0) { // Checking if directory name matches
            currentDirectory = temp; // Changing current directory to matched directory
            return; // Exiting function
        }
        temp = temp->next; // Moving to next subdirectory
    }
    printf("Directory not found.\n"); // Printing message if directory not found
}

void deleteFile(const char* fileName) {
    File* temp = currentDirectory->files; // Temporary pointer to traverse files
    File* prev = NULL; // Pointer to track previous file in list
    while (temp != NULL) { // Looping through files
        if (strcmp(temp->name, fileName) == 0) { // Checking if file name matches
            if (prev == NULL) { // If file to be deleted is the first file in list
                currentDirectory->files = temp->next; // Update files list to skip first file
            } else { // If file to be deleted is not the first file in list
                prev->next = temp->next; // Adjusting previous file's next pointer to skip deleted file
            }
            free(temp->name); // Freeing memory allocated for file name
            free(temp); // Freeing memory allocated for file structure
            return; // Exiting function
        }
        prev = temp; // Moving previous pointer to current file
        temp = temp->next; // Moving to next file
    }
    printf("File not found.\n"); // Printing message if file not found
}

void deleteDirectory(const char* directoryName) {
    Directory* temp = currentDirectory->subdirectories; // Temporary pointer to traverse subdirectories
    Directory* prev = NULL; // Pointer to track previous directory in list
    while (temp != NULL) { // Looping through subdirectories
        if (strcmp(temp->name, directoryName) == 0) { // Checking if directory name matches
            if (prev == NULL) { // If directory to be deleted is the first directory in list
                currentDirectory->subdirectories = temp->next; // Update subdirectories list to skip first directory
            } else { // If directory to be deleted is not the first directory in list
                prev->next = temp->next; // Adjusting previous directory's next pointer to skip deleted directory
            }
            free(temp->name); // Freeing memory allocated for directory name
            free(temp); // Freeing memory allocated for directory structure
            return; // Exiting function
        }
        prev = temp; // Moving previous pointer to current directory
        temp = temp->next; // Moving to next directory
    }
    printf("Directory not found.\n"); // Printing message if directory not found
}

void searchFile(const char* fileName) {
    File* temp = currentDirectory->files; // Temporary pointer to traverse files
    while (temp != NULL) { // Looping through files
        if (strcmp(temp->name, fileName) == 0) { // Checking if file name matches
            printf("File found: %s, Size: %d\n", temp->name, temp->size); // Printing name and size of file
            return; // Exiting function
        }
        temp = temp->next; // Moving to next file
    }
    printf("File not found.\n"); // Printing message if file not found
}
