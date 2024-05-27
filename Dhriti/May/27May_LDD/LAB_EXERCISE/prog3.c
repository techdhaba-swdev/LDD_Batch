#include <stdio.h>

#define BUFFER_SIZE 100

int main() {
    char buffer[BUFFER_SIZE];

    // Read from standard input (keyboard) and display on standard output (console)
    while (fgets(buffer, BUFFER_SIZE, stdin)) {
   // fgets() read lines of text from the standard input (stdin) into the buffer. Then, it prints each line to the standard output (stdout) using printf().
    	    printf("%s", buffer) ; 
    }

    return 0;
}


