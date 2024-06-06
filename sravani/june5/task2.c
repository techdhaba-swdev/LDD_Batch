#include <stdio.h>
#define PI 3.14159

// Function to calculate the area of a square
float calculateSquareArea(float side) {
    return side * side;
}

// Function to calculate the area of a rectangle
float calculateRectangleArea(float length, float width) {
    return length * width;
}

// Function to calculate the area of a circle
float calculateCircleArea(float radius) {
    return PI * radius * radius;
}

int main() {
    float side = 5.0;
    float length = 6.0;
    float width = 4.0;
    float radius = 3.0;

    printf("Area of square with side %.2f: %.2f\n", side, calculateSquareArea(side));
    printf("Area of rectangle with length %.2f and width %.2f: %.2f\n", length, width, calculateRectangleArea(length, width));
    printf("Area of circle with radius %.2f: %.2f\n", radius, calculateCircleArea(radius));

    return 0;
}
