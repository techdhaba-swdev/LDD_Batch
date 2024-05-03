
#ifndef FILE_H
#define FILE_H

// Directory structure: Tree (linked list representation)
struct Directory {
    char name[100];
    struct Directory* subdirectories;
    struct File* files;
};

// File information
struct File {
    char name[100];
    // Add other file-related information as needed
    struct File* next;
};

struct Directory* createDirectory(const char* name);
struct File* createFile(const char* name);
void listDirectoryContents(const struct Directory* dir);
struct Directory* navigateToSubdirectory(struct Directory* currentDir, const char* subDirName);
void delete(struct Directory* parentDir, const char* name);
void searchFilesByName(const struct Directory* dir, const char* fileName);

#endif

