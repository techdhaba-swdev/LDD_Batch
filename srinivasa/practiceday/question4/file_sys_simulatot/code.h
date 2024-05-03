#ifndef CODE_H_
#define CODE_H_
#define MAX_NAME_LENGTH 50
typedef struct File {
    char name[MAX_NAME_LENGTH];
    struct File *next;
} File;
typedef struct Directory {
    char name[MAX_NAME_LENGTH];
    struct Directory *parent;
    struct Directory *subdirectories;
    File *files;
} Directory;
Directory* createDirectory(Directory *parent, char *name);
void createFile(Directory *dir, char *name);
void deleteFile(Directory *dir, char *name);
void deleteDirectory(Directory *dir);
void viewContents(Directory *dir);
Directory* navigate(Directory *currentDir, char *name);
File* searchFile(Directory *dir, char *name);
#endif
