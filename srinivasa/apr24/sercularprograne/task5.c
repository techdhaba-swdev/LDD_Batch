#include <stdio.h>

int main() {
    FILE *file;
    char filename[20];
    printf("Enter filename: ");
    gets(filename);
    file = fopen(filename, "r"); // Doesn't check if file exists or permissions
    // Further file operations...
    return 0;
}
