//including all the required headerfiles
#include <stdio.h>
#include "code.h"
// main function 
int main() {
    // creating a root directory and named as root
    Directory *root = createDirectory(NULL, "root");
    // creating files by calling the createfile function
    createFile(root, "file1.txt"); // creating the file1.txt file 
    createFile(root, "file2.txt"); //creating the file2.txt file 
    // creating a subdirectory to the root and name as subdir
    Directory *subdir = createDirectory(root, "subdir");
    //creating a file in the subdirectory of name subdir
    createFile(subdir, "subfile1.txt"); // creating a file name subfile.txt in subdir
    // this function is used to show the content inside the root
    viewContents(root);
    printf("\n");
    // creating a founddir and calling the navigate function
    // this navigate function is  used to navigate the subdir to the founddir
    Directory *foundDir = navigate(root, "subdir");
    //printing the navigation succesfull or not
    if (foundDir != NULL) {
        printf("Navigated to directory '%s'.\n", foundDir->name);
    }
    printf("\n");
    // this function is used to search a file in the root directory
    File *foundFile = searchFile(root, "file2.txt");
    // printing the results of the search function
    if (foundFile != NULL) {
        printf("Found file '%s'.\n", foundFile->name);
    }
    printf("\n");
    // deleting the files in the root of the file name file1.txt
 deleteFile(root, "file1.txt");
    //printing the files present in the root after deleting file1.txt
    viewContents(root);
    // deleting the root directory
    deleteDirectory(root);
    // executing the programe without errors
    return 0;
}
