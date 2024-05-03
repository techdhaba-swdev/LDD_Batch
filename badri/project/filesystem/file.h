#ifndef FILE_H // Header guard to prevent multiple inclusions of this file.
#define FILE_H

// Directory structure: Tree (linked list representation)
struct Directory {
    char name[100]; // Name of the directory.
    struct Directory* subdirectories; // Pointer to the first subdirectory.
    struct File* files; // Pointer to the first file in this directory.
};

// File information
struct File {
    char name[100]; // Name of the file.
    // Add other file-related information as needed
    struct File* next; // Pointer to the next file in the directory.
};

// Function prototypes
struct Directory* createDirectory(const char* name); // Creates a new directory with the given name.
struct File* createFile(const char* name); // Creates a new file with the given name.
void listDirectoryContents(const struct Directory* dir); // Lists the contents of the directory (subdirectories and files).
struct Directory* navigateToSubdirectory(struct Directory* currentDir, const char* subDirName); // Navigates to a subdirectory with the given name.
void delete(struct Directory* parentDir, const char* name); // Deletes a directory or file from the parent directory.
void searchFilesByName(const struct Directory* dir, const char* fileName); // Searches for files with the given name in the directory.

#endif // End of header guard.
