#include "file_system.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (init_fs_notifier(argv[1]) != 0) {
        fprintf(stderr, "Failed to initialize file system notifier\n");
        exit(EXIT_FAILURE);
    }

    start_fs_monitoring();

    stop_fs_monitoring();
    return 0;
}
