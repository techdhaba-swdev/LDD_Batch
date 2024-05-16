#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void student_records(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    fprintf(file, "chandu,1,Maths\n");
    fprintf(file, "ram,2,Science\n");
    fprintf(file, "radha,3,History\n");
    fclose(file);
}

void parse(const char *filename, char **names, int *ids, char **subjects, size_t *num_students) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[256];
    size_t count = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        char *name = strtok(buffer, ",");
        char *id_str = strtok(NULL, ",");
        char *subject = strtok(NULL, "\n");

        if (name && id_str && subject) {
            names[count] = strdup(name);
            ids[count] = atoi(id_str);
            subjects[count] = strdup(subject);
            count++;
        } else {
            fprintf(stderr, "Error parsing line: %s\n", buffer);
        }
    }
    *num_students = count;

    fclose(file);
}

int main() {
    const char *filename = "student_records.txt";
    student_records(filename);

    char *names[100];
    int ids[100];
    char *subjects[100];
    size_t num_students = 0;

    parse(filename, names, ids, subjects, &num_students);

    for (size_t i = 0; i < num_students; i++) {
        printf("Student %u:\n", i + 1);
        printf("  Name: %s\n", names[i]);
        printf("  ID: %d\n", ids[i]);
        printf("  Subject: %s\n", subjects[i]);
        free(names[i]);
        free(subjects[i]);
    }

    return 0;
}
