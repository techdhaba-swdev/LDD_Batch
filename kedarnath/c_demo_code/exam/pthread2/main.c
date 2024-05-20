#include <thread.h> //created a header file named thread.h
int main() 
{
    pthread_t write_even,write_odd,read_even,read_odd; //created threads with names as shown

    // Create threads for writing even and odd lines
    if (pthread_create(&write_even, NULL, write_even_lines, "data.txt") != 0 || pthread_create(&write_odd, NULL, write_odd_lines, "data.txt") != 0) {
        perror("Error creating threads for writing");
        exit(EXIT_FAILURE);
    }

    // Wait for writing threads to finish using pthread_join
    pthread_join(write_even, NULL);
    pthread_join(write_odd, NULL);

    // Creating threads for reading and printing even and odd output files
    if (pthread_create(&read_even, NULL, read_file, "even_lines.txt") != 0 || pthread_create(&read_odd, NULL, read_file, "odd_lines.txt") != 0) {
        perror("Error creating threads for reading");
        exit(EXIT_FAILURE);
    }
    // Wait for reading threads to finish using pthread_join
    pthread_join(read_even, NULL);
    pthread_join(read_odd, NULL);

    return 0;
}



