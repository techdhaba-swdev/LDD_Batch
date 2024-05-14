
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>

#define EVENT_SIZE  (sizeof(struct inotify_event))
#define BUF_LEN     (1024 * (EVENT_SIZE + 16))

// Function to handle inotify events
void handle_event(int fd, int watch_fd) {
    char buffer[BUF_LEN];
    ssize_t len;
    struct inotify_event *event;

    len = read(fd, buffer, BUF_LEN);
    if (len == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    event = (struct inotify_event *)buffer;
    while ((char *)event < buffer + len) {
        if (event->wd == watch_fd) {
            // Display the type of event and the name of the file
            printf("Event Type: %s, File Name: %s\n",
                (event->mask & IN_CREATE) ? "CREATE" :
                (event->mask & IN_DELETE) ? "DELETE" :
                (event->mask & IN_MODIFY) ? "MODIFY" : "UNKNOWN",
                event->name);
        }
        event = (struct inotify_event *)((char *)event + EVENT_SIZE + event->len);
    }
}

int main(int argc, char *argv[]) {
    int fd, watch_fd;

    // Initialize inotify
    fd = inotify_init();
    if (fd == -1) {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    // Add watch for specified directory/file changes
    watch_fd = inotify_add_watch(fd, argv[1], IN_MODIFY | IN_CREATE | IN_DELETE);
    if (watch_fd == -1) {
        perror("inotify_add_watch");
        exit(EXIT_FAILURE);
    }

    printf("Watching directory: %s\n", argv[1]);

    // Main loop to handle events
    while (1) {
        handle_event(fd, watch_fd);
    }

    // Close inotify file descriptor
    close(fd);
    return 0;
}


