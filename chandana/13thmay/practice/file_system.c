#include "file_system.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>

#define EVENT_SIZE  (sizeof(struct inotify_event))
#define BUF_LEN     (1024 * (EVENT_SIZE + 16))

static int fd;
static int wd;

int init_fs_notifier(const char *directory) {
    fd = inotify_init();
    if (fd < 0) {
        perror("inotify_init");
        return -1;
    }

    wd = inotify_add_watch(fd, directory, IN_MODIFY | IN_CREATE | IN_DELETE);
    if (wd < 0) {
        perror("inotify_add_watch");
        return -1;
    }

    printf("Watching directory: %s\n", directory);
    return 0;
}

void start_fs_monitoring() {
    char buffer[BUF_LEN];
    int length;

    while (1) {
        length = read(fd, buffer, BUF_LEN);
        if (length < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        struct inotify_event *event = (struct inotify_event *) &buffer;
        if (event->len) {
            if (event->mask & IN_CREATE) {
                printf("New file or directory created: %s\n", event->name);
            } else if (event->mask & IN_DELETE) {
                printf("File or directory deleted: %s\n", event->name);
            } else if (event->mask & IN_MODIFY) {
                printf("File or directory modified: %s\n", event->name);
            }
        }
    }
}

void stop_fs_monitoring() {
    if (fd >= 0) {
        close(fd);
    }
}
