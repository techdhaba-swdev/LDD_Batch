// including all the required headerfile 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code.h"
// this function is used to create a directory 
 Directory* createDirectory(Directory *parent, char *name) {
 // creating a newdir by dinamically 
     Directory* newDir = (Directory*)malloc(sizeof(Directory));
    if (newDir == NULL) {
    // if the creating a directory fails this will print
        printf("Memory allocation failed.\n");
        exit(1);
    }
    //giving the name of directory to newdir->name 
    strcpy(newDir->name, name);
    newDir->parent = parent;
    newDir->subdirectories = NULL;
    newDir->files = NULL;
    return newDir;
}
//this function is used to create files in side the directory
void createFile(Directory *dir, char *name) {
    File* newFile = (File*)malloc(sizeof(File));
    if (newFile == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newFile->name, name);
    newFile->next = dir->files;
    dir->files = newFile;
}
//this function is used to delete the files inside the directory
void deleteFile(Directory *dir, char *name) {
    File *current = dir->files;
    File *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                dir->files = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("File '%s' not found.\n", name);
}
// this function is used to delete the directory
void deleteDirectory(Directory *dir) {
    if (dir == NULL) return;
    File *file = dir->files;
    while (file != NULL) {
        File *temp = file;
        file = file->next;
        free(temp);
    }
    Directory *subdir = dir->subdirectories;
    while (subdir != NULL) {
        Directory *temp = subdir;
        subdir = subdir->subdirectories;
        deleteDirectory(temp);
        free(temp);
    }
}
// this function used to show the contents of the directory
void viewContents(Directory *dir) {
    printf("Contents of directory '%s':\n", dir->name);
    File *file = dir->files;
    while (file != NULL) {
        printf("File: %s\n", file->name);
        file = file->next;
    }
    Directory *subdir = dir->subdirectories;
    while (subdir != NULL) {
        printf("Directory: %s\n", subdir->name);
        subdir = subdir->subdirectories;
    }
}
//this function is used to navigate the one dirctory into another
Directory* navigate(Directory *currentDir, char *name) {
    Directory *subdir = currentDir->subdirectories;
    while (subdir != NULL) {
        if (strcmp(subdir->name, name) == 0) {
            return subdir;
        }
        subdir = subdir->subdirectories;
    }
    printf("Subdirectory '%s' not found.\n", name);
    return NULL;
}
// this function is used to search the files inside the directory
File* searchFile(Directory *dir, char *name) {
    File *file = dir->files;
    while (file != NULL) {
        if (strcmp(file->name, name) == 0) {
            return file;
        }
        file = file->next;
    }
    printf("File '%s' not found.\n", name);
    return NULL;
}

