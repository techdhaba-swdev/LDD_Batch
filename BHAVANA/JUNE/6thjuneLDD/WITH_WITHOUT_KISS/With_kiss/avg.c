#include <stdio.h>

// Function to calculate the total of an array
int calculateTotal(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Function to calculate the average of an array
double calculateAverage(int arr[], int size) {
    int total = calculateTotal(arr, size);
    return total / (double)size;
}

// Function to count elements above a certain threshold
int countAboveThreshold(int arr[], int size, double threshold) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > threshold) {
            count++;
        }
    }
    return count;
}

int main() {
    int scores[100], num_students;
    
    // Input number of students
    printf("Enter number of students: ");
    scanf("%d", &num_students);

    // Input scores
    printf("Enter the scores:\n");
    for (int i = 0; i < num_students; i++) {
        scanf("%d", &scores[i]);
    }

    // Calculate average
    double average = calculateAverage(scores, num_students);

    // Count students scoring above average
    int above_avg_count = countAboveThreshold(scores, num_students, average);

    // Output results
    printf("Average score: %.2f\n", average);
    printf("Number of students scoring above average: %d\n", above_avg_count);

    return 0;
}


