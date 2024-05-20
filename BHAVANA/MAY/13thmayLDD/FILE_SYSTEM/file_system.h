#ifndef FS_NOTIFIER_H
#define FS_NOTIFIER_H

// Function to initialize the file system notifier
int init_fs_notifier(const char *directory);

// Function to start monitoring the directory
void start_fs_monitoring();

// Function to stop monitoring and clean up resources
void stop_fs_monitoring();

#endif
