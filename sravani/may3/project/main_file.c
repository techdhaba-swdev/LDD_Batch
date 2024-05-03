#include"file.h"

int main() {
   
   
clock_t start=clock();
   
// Create root directory
DirectoryNode* root = createDir("root", NULL);

// Create some files in root directory
createFiles(root, "exp1.txt");
createFiles(root, "exp2.txt");
createFiles(root, "exp3.txt");

// List contents of root directory
listDir(root);

// Create a subdirectory
DirectoryNode* subDir = createDir("subdir",root);
root->sub=subDir;

// Navigate into subdirectory
printf("\nNavigating into subdir...\n");
listDir(subDir);

// Search for a file in subdir
printf("\nSearching for  'exp2.txt' in subdir\n");
searchFile(subDir, "exp2.txt");

// Delete a file from subdir
printf("\nDeleting file 'exp2.txt' from subdir\n");
deleteFile(subDir, "exp2.txt");
listDir(subDir);

// Delete subdir and root directories
deleteDir(root);
   
clock_t end=clock();
double time_taken=((double)(end-start));
printf("time taken is %f\n",time_taken);


return 0;
}
