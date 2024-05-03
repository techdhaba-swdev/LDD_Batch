#include <stdio.h>
#include "filesystem.h"

int main() {
    // Create root directory
    struct Node* root = createDirectory("Root");

    // Create subdirectories and files
    struct Node* docs = createDirectory("Documents");
    struct Node* pics = createDirectory("Pictures");
    struct Node* file1 = createFile("Document1.txt");
    struct Node* file2 = createFile("Image1.jpg");

    // Add subdirectories and files to root
    addNode(root, docs);
    addNode(root, pics);
    addNode(docs, file1);
    addNode(pics, file2);

    // View contents of root directory
    viewContents(root);

    // Navigate to subdirectory
    struct Node* current = navigate(root, "Documents");

    // View contents of current directory
    viewContents(current);

    // Search for a file
    searchFile(root, "Image1.jpg");

    // Delete a file
    deleteNode(pics, "Image1.jpg");

    // View contents after deletion
    viewContents(pics);

    return 0;
   }
