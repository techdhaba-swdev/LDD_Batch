#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>
#include <limits.h> // for PATH_MAX

#define EVENT_SIZE  (sizeof(struct inotify_event)) // Size of each inotify event
#define BUF_LEN     (1024 * (EVENT_SIZE + 16))    // Buffer length for reading events

// Function to handle inotify events
void handle_event(int fd, int watch_fd) {
    char buffer[BUF_LEN];               // Buffer to store incoming events
    ssize_t len;                        // Number of bytes read
    struct inotify_event *event;        // Pointer to the current event

    // Read events from the inotify file descriptor
    len = read(fd, buffer, BUF_LEN);
    if (len == -1) {
        perror("read");                 // Print error message if read fails
        exit(EXIT_FAILURE);             // Exit the program on error
    }

    // Process each event
    event = (struct inotify_event *)buffer;   // Pointer to the first event in the buffer
    while ((char *)event < buffer + len) {    // Loop through all events in the buffer
        // Ensure that the event corresponds to the watched directory
        if (event->wd == watch_fd) {
            // Check for specific event types and print messages accordingly
            if (event->mask & IN_MODIFY) {
                printf("File modified: %s\n", event->name);
            }
            if (event->mask & IN_DELETE) {
                printf("File deleted: %s\n", event->name);
            }
            if (event->mask & IN_CREATE) {
                printf("File created: %s\n", event->name);
            }
            // Add more conditions for other event types if needed
        }
        // Move to the next event in the buffer
        event = (struct inotify_event *)((char *)event + EVENT_SIZE + event->len);
    }
}

// Main function
int main(int argc, char *argv[]) {
    int fd, watch_fd;  // File descriptors for inotify instance and watched directory

    // Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);  // Print usage message to stderr
        exit(EXIT_FAILURE);                                   // Exit the program with failure status
    }

    // Initialize the inotify instance
    fd = inotify_init();
    if (fd == -1) {
        perror("inotify_init");  // Print error message if initialization fails
        exit(EXIT_FAILURE);      // Exit the program on error
    }

    // Watch for file/directory changes in the specified path
    watch_fd = inotify_add_watch(fd, argv[1], IN_MODIFY | IN_CREATE | IN_DELETE);
    if (watch_fd == -1) {
        perror("inotify_add_watch");  // Print error message if adding watch fails
        exit(EXIT_FAILURE);           // Exit the program on error
    }

    // Print a message indicating the watched directory
    printf("Watching directory: %s\n", argv[1]);

    // Main loop to handle events
    while (1) {
        handle_event(fd, watch_fd);  // Call function to handle events
    }

    // Close the inotify file descriptor (this part of the code will never be reached)
    close(fd);

    return 0;
}