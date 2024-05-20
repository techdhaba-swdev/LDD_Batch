#include <stdio.h> // Including standard input/output library for printf
#include <stdlib.h> // Including standard library for exit, NULL
#include <unistd.h> // Including POSIX API for system calls like read, close
#include <sys/inotify.h> // Including inotify API for monitoring file system events

#define EVENT_SIZE  (sizeof(struct inotify_event)) // Defining size of inotify_event structure
#define BUF_LEN     (1024 * (EVENT_SIZE + 16)) // Defining buffer length for reading events

// Function to handle inotify events
void handle_event(int fd, int watch_fd) {
    char buffer[BUF_LEN]; // Buffer to read events
    ssize_t len; // Length of read data
    struct inotify_event *event; // Pointer to inotify_event structure

    len = read(fd, buffer, BUF_LEN); // Reading events into buffer
    if (len == -1) { // Checking for read errors
        perror("read"); // Printing error message
        exit(EXIT_FAILURE); // Exiting with failure status
    }

    event = (struct inotify_event *)buffer; // Casting buffer to inotify_event
    while ((char *)event < buffer + len) { // Loop through all events in buffer
        if (event->wd == watch_fd) { // Checking if event is for watched directory/file
            // Display the type of event and the name of the file
            printf("Event Type: %s, File Name: %s\n",
                (event->mask & IN_CREATE) ? "CREATE" :
                (event->mask & IN_DELETE) ? "DELETE" :
                (event->mask & IN_MODIFY) ? "MODIFY" : "UNKNOWN",
                event->name); // Printing event type and file name
        }
        event = (struct inotify_event *)((char *)event + EVENT_SIZE + event->len); // Moving to next event
    }
}

int main(int argc, char *argv[]) {
    int fd, watch_fd; // File descriptors for inotify and watch

    // Initialize inotify
    fd = inotify_init(); // Creating inotify instance
    if (fd == -1) { // Checking for initialization errors
        perror("inotify_init"); // Printing error message
        exit(EXIT_FAILURE); // Exiting with failure status
    }

    // Add watch for specified directory/file changes
    watch_fd = inotify_add_watch(fd, argv[1], IN_MODIFY | IN_CREATE | IN_DELETE); // Adding watch
    if (watch_fd == -1) { // Checking for watch addition errors
        perror("inotify_add_watch"); // Printing error message
        exit(EXIT_FAILURE); // Exiting with failure status
    }

    printf("Watching directory: %s\n", argv[1]); // Printing watched directory/file

    // Main loop to handle events
    while (1) {
        handle_event(fd, watch_fd); // Calling event handler
    }

    // Close inotify file descriptor
    close(fd); // Closing inotify instance
    return 0; // Exiting with success status
}


