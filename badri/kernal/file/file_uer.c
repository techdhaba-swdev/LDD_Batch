#include <stdio.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];

    // Read input from standard input and display on standard output
    if(fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        printf("%s", buffer);
        
    }
   fclose(stdin);

    return 0;
}
