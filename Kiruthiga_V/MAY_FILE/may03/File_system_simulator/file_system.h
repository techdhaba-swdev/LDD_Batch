#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H
#include <stdbool.h>
// Node structure for linked list representation of files
struct FileNode {
    char name[50];          // File name
    bool isDirectory;       // Flag to indicate if it's a directory
    struct FileNode* next;  // Pointer to the next file node
};

// Node structure for tree representation of directories
struct DirNode {
    char name[50];              // Directory name
    struct DirNode* parent;     // Pointer to the parent directory
    struct FileNode* files;     // Pointer to the files in this directory
    struct DirNode* subdirs;    // Pointer to the subdirectories in this directory
    struct DirNode* next;       // Pointer to the next directory node (sibling)
};
struct FileNode* createFileNode(char* name, bool isDirectory);
struct DirNode* createDirNode(char* name, struct DirNode* parent);
void createDirectory(struct DirNode* parent, char* name);
void createFile(struct DirNode* dir, char* name, bool isDirectory);
void printDirContents(struct DirNode* dir);
void deleteFile(struct DirNode* dir, char* name);
void deleteDirectory(struct DirNode* dir);
void searchFile(struct DirNode* dir, char* name);

#endif

