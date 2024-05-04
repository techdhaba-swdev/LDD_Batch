#include"file.h"

int main() {
   
   
clock_t start=clock();
   
// Create root directory
DirectoryNode* root = createDirectory("root", NULL);

// Create some files in root directory
createFile(root, "file1.txt");
createFile(root, "file2.txt");
createFile(root, "file3.txt");

// List contents of root directory
listDirectoryContents(root);

// Create a subdirectory
DirectoryNode* Dhriti = createDirectory("Dhriti", root);
root->child = Dhriti;

// Navigate into subdirectory
printf("\nNavigating into dhriti...\n");
listDirectoryContents(Dhriti);

// Search for a file in subdir
printf("\nSearching for file 'file2.txt' in dhriti...\n");
searchFile(Dhriti, "file2.txt");

// Delete a file from subdir
printf("\nDeleting file 'file2.txt' from dhriti...\n");
deleteFile(Dhriti, "file2.txt");
listDirectoryContents(Dhriti);

// Delete subdir and root directories
deleteDirectory(root);
   
clock_t end=clock();
double time_taken=((double)(end-start));
printf("time taken is %f\n",time_taken);


return 0;
}
