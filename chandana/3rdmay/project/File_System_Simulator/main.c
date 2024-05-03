#include <stdio.h>
#include "file_system.h"
#include <time.h>//Include the time.h header for clock function

//Declare currentDirectory as an extern variable
extern Directory* currentDirectory;

int main() {
    // Initialize the file system
    initializeFileSystem();

    //start time calculation
    clock_t startTime=clock();

    // Create some directories and files
    createDirectory("documents");
    createDirectory("images");
    createFile("document1.txt", 100);
    createFile("image1.jpg", 500);

    // Print the current directory contents
    printf("Current directory contents:\n");
    viewDirectoryContents(currentDirectory->name);

    // Navigate into 'documents' directory and create a file
    printf("\nNavigating into 'documents' directory...\n");
    navigateIntoDirectory("documents");
    createFile("document2.txt", 200);

    // Print the current directory contents again
    printf("\nCurrent directory contents:\n");
    viewDirectoryContents(currentDirectory->name);

    // Search for a file
    printf("\nSearching for 'image1.jpg'...\n");
    searchFile("image1.jpg");

    // Delete a file
    printf("\nDeleting 'document1.txt'...\n");
    deleteFile("document1.txt");

    // Print the current directory contents one more time
    printf("\nCurrent directory contents:\n");
    viewDirectoryContents(currentDirectory->name);

    //claculate total time taken
    clock_t endTime=clock();
    double totalTime = (double)(endTime - startTime)/CLOCKS_PER_SEC;
    printf("\nTotal time taken %f seconds\n",totalTime);

    return 0;
}
