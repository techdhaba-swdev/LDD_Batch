#include <stdio.h>
#include <string.h>

struct Report {
    char content[256];
};

void createReport(struct Report* report) {
    strcpy(report->content, "This is the report content.");
}

void printReport(const struct Report* report) {
    printf("Report: %s\n", report->content);
}

int main() {
    struct Report report;
    createReport(&report);
    printReport(&report);
    return 0;
}
