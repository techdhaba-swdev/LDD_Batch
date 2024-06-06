/*The DRY principle emphasizes the avoidance of duplication of code within a software system. It encourages modularization and reusability of code to reduce redundancy. DRY aims to improve maintainability and readability by ensuring that any given piece of functionality is implemented in exactly one place in the codebase.*/

 #include <stdio.h>
#define PI 3.14

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
    float side = 2;
    float length = 3;
    float width = 4;
    float radius = 3;

    printf("Area of square : %.2f\n",  calculateSquareArea(side));
    printf("Area of rectangle: %.2f\n",  calculateRectangleArea(length, width));
    printf("Area of circle: %.2f\n",  calculateCircleArea(radius));

    return 0;
}
