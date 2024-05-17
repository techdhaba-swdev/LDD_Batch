#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/inotify.h>

#define EVENT_SIZE  (sizeof(struct inotify_event))
#define BUF_LEN     (1024 * (EVENT_SIZE + 16))

void handle_event(int fd) {
    char buffer[BUF_LEN];
    int length, i = 0;

    length = read(fd, buffer, BUF_LEN);

    while (i < length) {
        struct inotify_event *event = (struct inotify_event *) &buffer[i];
        if (event->mask & IN_MODIFY) {
            printf("File modified: %s\n", event->name);
        }
        if (event->mask & IN_CREATE) {
            printf("File created: %s\n", event->name);
        }
        if (event->mask & IN_DELETE) {
            printf("File deleted: %s\n", event->name);
        }
        i += EVENT_SIZE + event->len;
    }
}

int main() {
    int fd = inotify_init();
    if (fd < 0) {
        perror("inotify_init");
        return 1;
    }

    int wd = inotify_add_watch(fd, "/path/to/directory", IN_MODIFY | IN_CREATE | IN_DELETE);
    if (wd < 0) {
        perror("inotify_add_watch");
        return 1;
    }

    while (1) {
        handle_event(fd);
    }

    close(fd);
    return 0;
}
