#include "file.h" // Include the header file for function declarations

int main() {
    FILE *input_file = fopen("input.txt", "r"); // Open input file to read 
    FILE *file_even = fopen("even.txt", "w"); // output file for even lines to write
    FILE *file_odd = fopen("odd.txt", "w"); // output file for odd lines in write mode


    // Initialize a mutex (mutual exclusion) object
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;



    // Declare pthread variables for threads
    pthread_t thread1, thread2, thread3, thread4;




    // Check if any of the files failed to open
    if (input_file == NULL || file_even == NULL || file_odd == NULL) {
        perror("Error opening file"); // Print an error message if file opening failed
        exit(EXIT_FAILURE); // Exit the program with a failure 
    }

    //  thread arguments for even and odd line processing
ThreadArgs args1 = {input_file, file_even, &mutex}; //  thread for even lines
    ThreadArgs args2 = {input_file, file_odd, &mutex};  //thread for odd lines
							       //
							       //

    // Create threads for even and odd line processing
    pthread_create(&thread1, NULL, even_lines, (void *)&args1); // thread for even lines 
    pthread_create(&thread2, NULL, odd_lines, (void *)&args2);  // thread for odd lines




    // Wait for the even and odd line processing threads to finish
    pthread_join(thread1, NULL); // thread1 to finish
    pthread_join(thread2, NULL); // thread2 to finish




    // Create threads for reading and printing output files
pthread_create(&thread3, NULL, read_and_print, "even.txt"); // to read and print even lines output
pthread_create(&thread4, NULL, read_and_print, "odd.txt");  //to read and print odd lines output




    // Wait for the reading and printing threads to finish
    pthread_join(thread3, NULL); // Wait for thread3 to finish
    pthread_join(thread4, NULL); // Wait for thread4 to finish




    // Cleanup: Close files and destroy mutex
    fclose(input_file); // Close input file
    fclose(file_even); // Close output file for even lines
    fclose(file_odd);  // Close output file for odd lines
    pthread_mutex_destroy(&mutex); // Destroy the mutex object

    return 0; // Return 0 to indicate successful completion of the program
}
