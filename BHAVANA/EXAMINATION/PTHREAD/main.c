#include <stdio.h>
#include <pthread.h>
#include "file.h" // Include the header file containing function declarations

int main() {
pthread_t even_thread, odd_thread;
pthread_create(&even_thread, NULL, process_even_lines, NULL); // Create thread for processing even lines
pthread_create(&odd_thread, NULL, process_odd_lines, NULL); // Create thread for processing odd lines
pthread_join(even_thread, NULL); // Wait for even thread to finish
pthread_join(odd_thread, NULL); // Wait for odd thread to finish
pthread_t read_even_thread, read_odd_thread;
pthread_create(&read_even_thread, NULL, read_even_output, NULL); // Create thread for reading even output file
pthread_create(&read_odd_thread, NULL, read_odd_output, NULL); // Create thread for reading odd output file
pthread_join(read_even_thread, NULL); // Wait for read even thread to finish
pthread_join(read_odd_thread, NULL); // Wait for read odd thread to finish

    return 0;
}
