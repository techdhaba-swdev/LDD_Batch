#include <stdio.h>          // Include standard input-output library
#include "file_system.h"    // Include the header file containing function prototypes
#include <time.h>
int main() {                // Main function where the program starts execution
 clock_t start = clock();
    struct Directory* rootDir = createDirectory(NULL, "root");  // Create the root directory

    if (!rootDir) {         // Check if root directory creation failed
        printf("Error: Failed to create root directory.\n");   // Print error message
        return 1;            // Return with error code
    }

    // Create subdirectories and files
    struct Directory* subDir1 = createDirectory(rootDir, "subdir1");  // Create subdirectory 1
    struct Directory* subDir2 = createDirectory(rootDir, "subdir2");  // Create subdirectory 2

    createFile(rootDir, "file1.txt");   // Create file1.txt in the root directory
    createFile(rootDir, "file2.txt");   // Create file2.txt in the root directory
    createFile(subDir1, "file3.txt");   // Create file3.txt in subdirectory 1
    createFile(subDir2, "file4.txt");   // Create file4.txt in subdirectory 2

    // View contents of root directory
    viewDirectoryContents(rootDir);

    // Navigate to subdirectory and view contents
    struct Directory* currentDir = navigateToDirectory(rootDir, "subdir1");  // Navigate to subdir1
    if (currentDir != NULL) {         // Check if navigation was successful
        viewDirectoryContents(currentDir);  // View contents of subdir1
    }
    

    // Search for a file
    searchFile(rootDir, "file6.txt");  // Search for file6.txt
 //struct FileInfo* foundFile = searchFile(rootDir, "file2.txt");
 
    // Delete a file
    deleteFile(rootDir, "file1.txt");  // Delete file1.txt from root directory

    // Delete a directory
    deleteDirectory(rootDir, "subdir2");  // Delete subdir2
    
   
  //  }
    

 viewDirectoryContents(rootDir);
  // End timing
    clock_t end = clock();

    // Calculate the elapsed time in milliseconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("time take is %f\n", time_taken);
    return 0;   // Return with success code
}
