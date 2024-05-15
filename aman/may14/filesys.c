#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>

#define EVENT_SIZE  (sizeof(struct inotify_event))
#define BUF_LEN     (1024 * (EVENT_SIZE + 16))

void handle_event(int fd) {
    char buffer[BUF_LEN];
    ssize_t len = read(fd, buffer, BUF_LEN);
    if (len == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("Change detected:\n");
    struct inotify_event *event;
    for (char *ptr = buffer; ptr < buffer + len; ptr += sizeof(struct inotify_event) + event->len) {
        event = (struct inotify_event *)ptr;
        printf("    File: %s\n", event->name);
        if (event->mask & IN_CREATE)
            printf("        File created\n");
        if (event->mask & IN_DELETE)
            printf("        File deleted\n");
        if (event->mask & IN_MODIFY)
            printf("        File modified\n");
    }
}

int main() {
    int fd = inotify_init();
    if (fd == -1) {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    int wd = inotify_add_watch(fd, "/path/to/watch", IN_CREATE | IN_DELETE | IN_MODIFY);
    if (wd == -1) {
        perror("inotify_add_watch");
        exit(EXIT_FAILURE);
    }

    printf("Watching for changes...\n");

    while (1) {
        handle_event(fd);
    }

    close(fd);
    return 0;
}
