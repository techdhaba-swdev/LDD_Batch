#include "CreateNode.h"
#include "AddChildNode.h"
#include "ListDirectoryContents.h"
#include "NavigateToSubdirectory.h"
#include "DeleteNode.h"
#include "SearchFile.h"
#include <stdio.h>
#include <time.h>
int main() {
    clock_t start = clock();
    // Create the root of the file system
    Node* root = createNode("/");

    // Add directories and files to the root
    addChildNode(root, createNode("dir1"));
    addChildNode(root, createNode("file1.txt"));
    addChildNode(root, createNode("dir2"));

    // Add files to dir1
    Node* dir1 = navigateToSubdirectory(root, "dir1");
    addChildNode(dir1, createNode("file2.txt"));
    addChildNode(dir1, createNode("file3.txt"));

    // Add files to dir2
    Node* dir2 = navigateToSubdirectory(root, "dir2");
    addChildNode(dir2, createNode("file4.txt"));
    addChildNode(dir2, createNode("file5.txt"));

    // List contents of the root directory
    printf("Contents of root directory:\n");
    listDirectoryContents(root);

    // List contents of dir1
    printf("\nContents of dir1:\n");
    listDirectoryContents(dir1);

    // List contents of dir2
    printf("\nContents of dir2:\n");
    listDirectoryContents(dir2);

    // Search for file 
    searchFile(root, "file5.txt");
   // Node* file =  searchFile(root, "file5.txt");

    clock_t end = clock();

    // Calculate the elapsed time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time_taken);

  //  if (file) {
      //  printf("\nFile '%s' found.\n", file->name);
   // } else {
     //   printf("\nFile not found.\n");
   // }

    // Clean up memory by deleting all nodes
    deleteNode(root);

    return 0;
}
