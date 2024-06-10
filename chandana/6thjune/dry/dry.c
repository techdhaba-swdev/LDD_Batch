#include <stdio.h>

// Function to calculate area of a rectangle
int calculate_area(int length, int width) {
    return length * width;
}

int main() {
    int length1 = 5, width1 = 3;
    int length2 = 7, width2 = 4;

    int area1 = calculate_area(length1, width1);
    int area2 = calculate_area(length2, width2);

    printf("Area of first rectangle: %d\n", area1);
    printf("Area of second rectangle: %d\n", area2);

    return 0;
}
