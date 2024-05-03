#ifndef FILE_L
#define FILE_L

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Define structure for file node
typedef struct FileNode {
	char data[100];
	struct FileNode* next;
} FileNode;

// Define structure for directory node
typedef struct DirectoryNode {
	char data[100];
	struct DirectoryNode* main;
	struct DirectoryNode* sub;
	struct DirectoryNode* sibling;
	FileNode* files;
} DirectoryNode;

// Function prototypes
DirectoryNode* createDir(const char* name, DirectoryNode* parent);
void createFiles(DirectoryNode* directory, const char* filename);
void listDir(DirectoryNode* directory);
DirectoryNode* navigateDir(DirectoryNode* currentDirectory, const char* dirname);
void deleteDir(DirectoryNode* directory);
void deleteFile(DirectoryNode* directory, const char* filename);
void searchFile(DirectoryNode* directory, const char* filename);



#endif
