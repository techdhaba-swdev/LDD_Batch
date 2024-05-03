#ifndef LLTREE_H
#define LLTREE_H

// Structure for a file
struct File {
    char name[100];
    struct File* next;
};

typedef struct File File;

// Structure for a directory
struct Directory {
    char name[100];
    struct Directory* subdirectories;
    struct File* files;
    struct Directory* next;
};

typedef struct Directory Directory;

// Function declarations
Directory* createDirectory(char* name);
File* createFile(char* name);
void addDirectory(Directory** root, char* name);
void addFile(Directory* directory, char* name);
void viewDirectoryContents(Directory* directory);
Directory* navigateToSubdirectory(Directory* root, char* name);
void deleteFile(Directory* directory, char* name);
void deleteDirectory(Directory** root, char* name);
File* searchFile(Directory* directory, char* name);

#endif /* LLTREE_H */

