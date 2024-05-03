#include <stdio.h> // Include standard input/output library.
#include <stdlib.h> // Include standard library for memory allocation and other functions.
#include <string.h> // Include string manipulation functions.
#include"file.h" // Include the custom header file "file.h" which contains declarations related to file management.
#include<time.h> // Include time-related functions for measuring program execution time.

int main() // Define the main function.
{   
    clock_t start = clock(); // Record the starting time of program execution.

    // Initialize the root directory
    struct Directory* root = createDirectory("/"); // Create the root directory with name "/".

    // Example usage:
    struct Directory* userDir = createDirectory("user"); // Create a subdirectory named "user".
    root->subdirectories = userDir; // Assign the "user" subdirectory to the root directory.

    struct File* reportFile = createFile("report.txt"); // Create a file named "report.txt".
    userDir->files = reportFile; // Assign the "report.txt" file to the "user" directory.

    // Call navigateToSubdirectory
    struct Directory* subDir = navigateToSubdirectory(root, "user"); // Navigate to the "user" subdirectory.
    if (subDir) {
        printf("Navigated to subdirectory: %s\n", subDir->name); // Print a message if navigation is successful.
    }

    // Call listDirectoryContents
    listDirectoryContents(root); // List the contents of the root directory.

    // Call searchFilesByName
    searchFilesByName(userDir, "report.txt"); // Search for the "report.txt" file in the "user" directory.

     // Call delete
    delete(userDir, "report.txt"); // Delete the "report.txt" file from the "user" directory.

    // List contents after deletion
    listDirectoryContents(userDir); // List the contents of the "user" directory after deletion.

    clock_t end = clock(); // Record the ending time of program execution.
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate the time taken for program execution.
    printf("Time taken: %f seconds\n", time_taken); // Print the total time taken for program execution.

    return 0; // Return 0 to indicate successful program execution.
}
