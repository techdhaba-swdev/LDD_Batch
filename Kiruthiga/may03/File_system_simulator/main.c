#include<stdio.h>
#include <stdbool.h>
#include"file_system.h"
int main() {
    // Create root directory
    struct DirNode* root = createDirNode("root_node", NULL);

    // Create subdirectories
    createDirectory(root, "docs1.txt");
    createDirectory(root, "code1.c");
    createDirectory(root->subdirs, "pictures");

    // Create files
    createFile(root, "kiruthiga.txt", false);
    createFile(root->subdirs, "kiruthiga.jpg", false);

    // Print directory contents
    printDirContents(root);

    // Search for file
    printf("\nSearch for file: kiruthiga.jpg\n");
    searchFile(root, "kiruthiga.jpg");

    // Delete file
    deleteFile(root, "kiruthiga.txt");

    // Print directory contents after deletion
    printf("\nAfter file deletion:\n");
    printDirContents(root);

    // Delete directories
    deleteDirectory(root);

    return 0;
}



