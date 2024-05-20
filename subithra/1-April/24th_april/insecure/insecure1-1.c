#include <stdio.h>
#include<stdlib.h>
 int main() {
     FILE *file = fopen("important_data.txt", "r"); // Attempt to open a file
     if (file == NULL) {
         perror("Error opening file"); // Print error message
         return 1; // Exit the program with error status
     }
    
     char buffer[128];
    size_t bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file); 
     if (bytes_read == 0) {
         perror("Error reading from file"); // Print error message
         fclose(file); // Close the file
         return 1; // Exit the program with error status
     }
    
     printf("Data read from file: %s\n", buffer);
    
     fclose(file); // Close the file
     return 0;
 }


