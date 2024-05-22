#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>

#define EVENT_SIZE  (sizeof(struct EventInfo))  // Calculate size of custom event struct
#define BUF_LEN     (1024 * (EVENT_SIZE + 16))  // Buffer length for reading events

// Define a custom struct to hold inotify event information
struct EventInfo {
    int wd;             // Watch descriptor
    uint32_t len;       // Length (including nulls) of name field
    char name[];        // Optional null-terminated name
};

// Function to handle inotify events securely
void handle_event(int fd, int watch_fd) {
    char buffer[BUF_LEN];       // Buffer to read events
    ssize_t len;                // Length of read data
    struct EventInfo *event;    // Pointer to custom event struct

    // Read events from the inotify file descriptor
    len = read(fd, buffer, BUF_LEN);
    if (len == -1) {
        perror("read");         // Print error if read fails
        exit(EXIT_FAILURE);     // Exit with failure status
    }

    // Process each event in the buffer
    event = (struct EventInfo *)buffer;
    while ((char *)event < buffer + len) {
        if (event->wd == watch_fd) {
            // Ensure the event name is null-terminated
            char event_name[event->len + 1];
            strncpy(event_name, event->name, event->len);
            event_name[event->len] = '\0';

            // Display the file name
            printf("File Name: %s\n", event_name);
        }
        event = (struct EventInfo *)((char *)event + EVENT_SIZE + event->len);
    }
}

int main(int argc, char *argv[]) {
    int fd, watch_fd;

    // Check for correct usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s directory_path\n", argv[0]);  // Print usage message to stderr
        exit(EXIT_FAILURE);                                       // Exit with failure status
    }

    // Initialize inotify securely
    fd = inotify_init();           // Create inotify instance
    if (fd == -1) {
        perror("inotify_init");    // Print error if initialization fails
        exit(EXIT_FAILURE);        // Exit with failure status
    }

    // Add watch for specified directory/file changes securely
    watch_fd = inotify_add_watch(fd, argv[1], IN_MODIFY | IN_CREATE | IN_DELETE);
    if (watch_fd == -1) {
        perror("inotify_add_watch");  // Print error if watch addition fails
        exit(EXIT_FAILURE);           // Exit with failure status
    }

    printf("Watching directory: %s\n", argv[1]);  // Print message indicating directory being watched

    // Main loop to handle events securely
    while (1) {
        handle_event(fd, watch_fd);  // Call function to handle events
    }

    // Close inotify file descriptor
    close(fd);  // Close inotify instance
    return 0;   // Exit with success status
}
