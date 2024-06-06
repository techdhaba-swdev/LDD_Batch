#include <stdio.h>

int main() {
    int scores[100], num_students, i;
    int total = 0, above_avg_count = 0;
    double average;

    // Input number of students
    printf("Enter number of students: ");
    scanf("%d", &num_students);

    // Input scores
    printf("Enter the scores:\n");
    for (i = 0; i < num_students; i++) {
        scanf("%d", &scores[i]);
        total += scores[i]; // Sum up scores for average calculation
    }

    // Calculate average
    average = total / (double)num_students;

    // Count students scoring above average
    for (i = 0; i < num_students; i++) {
        if (scores[i] > average) {
            above_avg_count++;
        }
    }

    // Output results
    printf("Average score: %.2f\n", average);
    printf("Number of students scoring above average: %d\n", above_avg_count);

    return 0;
}
