#include <stdio.h>  // Include the standard input-output library for printf and scanf

#define PI 3.14159  // Define a constant for the value of PI

// Function declarations
double calculateRectangleArea(double width, double height);  // Declare a function to calculate the area of a rectangle
double calculateCircleArea(double radius);  // Declare a function to calculate the area of a circle
void printArea(const char* shape, double area);  // Declare a function to print the area of a shape

int main() {
    double width, height, radius;  // Declare variables for the dimensions of the rectangle and the radius of the circle

    // Input for rectangle
    printf("Enter the width of the rectangle: ");  // Prompt the user to enter the width of the rectangle
    scanf("%lf", &width);  // Read the width from the user and store it in the 'width' variable
    printf("Enter the height of the rectangle: ");  // Prompt the user to enter the height of the rectangle
    scanf("%lf", &height);  // Read the height from the user and store it in the 'height' variable

    // Calculate and print area of the rectangle
    double rectangleArea = calculateRectangleArea(width, height);  // Call the function to calculate the rectangle's area and store the result
    printArea("Rectangle", rectangleArea);  // Call the function to print the area of the rectangle

    // Input for circle
    printf("Enter the radius of the circle: ");  // Prompt the user to enter the radius of the circle
    scanf("%lf", &radius);  // Read the radius from the user and store it in the 'radius' variable

    // Calculate and print area of the circle
    double circleArea = calculateCircleArea(radius);  // Call the function to calculate the circle's area and store the result
    printArea("Circle", circleArea);  // Call the function to print the area of the circle

    return 0;  // Return 0 to indicate successful completion of the program
}

// Function definitions
double calculateRectangleArea(double width, double height) {
    return width * height;  // Calculate and return the area of the rectangle
}

double calculateCircleArea(double radius) {
    return PI * radius * radius;  // Calculate and return the area of the circle using the formula PI * r^2
}

void printArea(const char* shape, double area) {
    printf("The area of the %s is: %.2lf\n", shape, area);  // Print the area of the given shape with two decimal places
}
