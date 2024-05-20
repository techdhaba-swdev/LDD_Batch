#ifndef FILE_SYSTEM_H   // Start of header guard to prevent multiple inclusions
#define FILE_SYSTEM_H

// Forward declarations
struct FileInfo;     // Declare struct FileInfo
struct Directory;    // Declare struct Directory

// Function prototypes
struct Directory* createDirectory(struct Directory* parent, const char* name);   // Create directory function prototype
void createFile(struct Directory* dir, const char* name);   // Create file function prototype
void viewDirectoryContents(struct Directory* dir);   // View directory contents function prototype
struct Directory* navigateToDirectory(struct Directory* currentDir, const char* name);   // Navigate to directory function prototype
void deleteFile(struct Directory* dir, const char* name);   // Delete file function prototype
void deleteDirectory(struct Directory* parent, const char* name);   // Delete directory function prototype
struct FileInfo* searchFile(struct Directory* dir, const char* name);   // Search file function prototype

#endif /* FILE_SYSTEM_H */   // End of header guard
