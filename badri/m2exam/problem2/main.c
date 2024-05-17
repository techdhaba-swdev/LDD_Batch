#include "pthread.c"
int main() {
    // Open the input file
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    // Open the output files for even and odd lines
    FILE *even_file = fopen("even.txt", "w");
    FILE *odd_file = fopen("odd.txt", "w");
    if (even_file == NULL || odd_file == NULL) {
        perror("Failed to open output file");
        fclose(input_file); // Close the input file before exiting
        return EXIT_FAILURE;
    }

    // Initialize the mutex for synchronizing access to the input file
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    // Create thread data structures for even and odd lines
    ThreadData odd_data = {input_file, odd_file, &mutex, 1};
    ThreadData even_data = {input_file, even_file, &mutex, 0};

    // Create writer threads for even and odd lines
    pthread_t writer_threads[2];
    pthread_create(&writer_threads[1], NULL, write_lines, &odd_data);
    pthread_create(&writer_threads[0], NULL, write_lines, &even_data);
   

    // Wait for the writer threads to complete
    pthread_join(writer_threads[0], NULL);
    pthread_join(writer_threads[1], NULL);

    // Close the input and output files after writing
    fclose(input_file);
    fclose(even_file);
    fclose(odd_file);

    // Reopen the output files for reading
    even_file = fopen("even.txt", "r");
    odd_file = fopen("odd.txt", "r");
    if (even_file == NULL || odd_file == NULL) {
        perror("Failed to reopen output file");
        if (even_file) fclose(even_file);
        if (odd_file) fclose(odd_file);
        return EXIT_FAILURE;
    }

    // Create reader threads for reading and printing the content of the output files
    pthread_t reader_threads[2];
    pthread_create(&reader_threads[0], NULL, read_and_print, even_file);
    pthread_create(&reader_threads[1], NULL, read_and_print, odd_file);

    // Wait for the reader threads to complete
    pthread_join(reader_threads[0], NULL);
    pthread_join(reader_threads[1], NULL);

    // Close the output files after reading
    fclose(even_file);
    fclose(odd_file);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return EXIT_SUCCESS;
}
