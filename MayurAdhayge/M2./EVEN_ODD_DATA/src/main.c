
#include "main.h" // Created a header file named main.h

int main() 
{
    pthread_t writeEvenThread, writeOddThread, readEvenThread, readOddThread; // Created threads with descriptive names

    // Create threads for writing even and odd lines
    if (pthread_create(&writeEvenThread, NULL, writeEvenLines, "sample.txt") != 0 || pthread_create(&writeOddThread, NULL, writeOddLines, "sample.txt") != 0) {
        perror("Error creating threads for writing");
        exit(EXIT_FAILURE);
    }

    // Wait for writing threads to finish using pthread_join
    pthread_join(writeEvenThread, NULL);
    pthread_join(writeOddThread, NULL);

    // Creating threads for reading and printing even and odd output files
    if (pthread_create(&readEvenThread, NULL, readFile, "even_lines.txt") != 0 || pthread_create(&readOddThread, NULL, readFile, "odd_lines.txt") != 0) {
        perror("Error creating threads for reading");
        exit(EXIT_FAILURE);
    }
    
    // Wait for reading threads to finish using pthread_join
    pthread_join(readEvenThread, NULL);
    pthread_join(readOddThread, NULL);

    return 0;
}
