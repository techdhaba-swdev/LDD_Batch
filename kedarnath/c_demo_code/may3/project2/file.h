#ifndef FILE_L
#define FILE_L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

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





#endif
