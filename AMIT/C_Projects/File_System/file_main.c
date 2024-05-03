#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"file.h"
#include<time.h>

int main()
{   
    clock_t start = clock();
    // Initialize the root directory
    struct Directory* root = createDirectory("/");

    // Example usage:
    struct Directory* userDir = createDirectory("user");
    root->subdirectories = userDir;

    struct File* reportFile = createFile("report.txt");
    userDir->files = reportFile;

    // Call navigateToSubdirectory
    struct Directory* subDir = navigateToSubdirectory(root, "user");
    if (subDir) {
        printf("Navigated to subdirectory: %s\n", subDir->name);
    }

    // Call listDirectoryContents
    listDirectoryContents(root);

    // Call searchFilesByName
    searchFilesByName(userDir, "report.txt");

     // Call delete
    delete(userDir, "report.txt");

    // List contents after deletion
    listDirectoryContents(userDir);

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
      printf("Time taken: %f seconds\n", time_taken);



    return 0;
}
              

