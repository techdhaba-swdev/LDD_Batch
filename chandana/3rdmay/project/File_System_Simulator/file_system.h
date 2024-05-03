#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <stdbool.h> // Including header file for boolean data type

// Structures
typedef struct File { // Defining structure for a file
    char* name;         // Name of the file
    int size;           // Size of the file
    struct File* next;  // Pointer to the next file in the list
} File;

typedef struct Directory { // Defining structure for a directory
    char* name;                 // Name of the directory
    struct Directory* parent;   // Pointer to the parent directory
    struct Directory* subdirectories;  // Pointer to the first subdirectory
    File* files;               // Pointer to the first file in the directory
    struct Directory* next;    // Pointer to the next directory in the list
} Directory;

// Function declarations
void initializeFileSystem();  // Function prototype to initialize the file system
void createDirectory(const char* name);  // Function prototype to create a new directory
void createFile(const char* name, int size);  // Function prototype to create a new file
void viewDirectoryContents(const char* directoryName);  // Function prototype to view contents of a directory
void navigateIntoDirectory(const char* directoryName);  // Function prototype to navigate into a directory
void deleteFile(const char* fileName);  // Function prototype to delete a file
void deleteDirectory(const char* directoryName);  // Function prototype to delete a directory
void searchFile(const char* fileName);  // Function prototype to search for a file


#endif // End of preprocessor directive
