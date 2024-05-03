#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lltree.h"

int main() {
    clock_t start, end;
    double cpu_time_used;

    Directory* root = createDirectory("root");

    // Creating directories and files
    addDirectory(&root, "folder1");
    addFile(root, "file1.txt");

    // Viewing directory contents
    viewDirectoryContents(root);

    // Navigating to subdirectory
    Directory* subdirectory = navigateToSubdirectory(root, "folder1");
    if (subdirectory != NULL)
        printf("Navigated to subdirectory: %s\n", subdirectory->name);

    // Deleting file
    deleteFile(root, "file1.txt");

    // Deleting directory
    deleteDirectory(&root, "folder1");

    // Measure time taken
    start = clock();
    // Perform operations here...
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
