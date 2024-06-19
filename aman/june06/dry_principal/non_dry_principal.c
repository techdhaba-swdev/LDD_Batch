#include <stdio.h>

#define PI 3.14159  // Define a constant for the value of PI

int main() {
    double width, height, radius;  // Declare variables for the dimensions of the rectangle and the radius of the circle

    // Input for rectangle
    printf("Enter the width of the rectangle: ");  // Prompt the user to enter the width of the rectangle
    scanf("%lf", &width);  // Read the width from the user and store it in the 'width' variable
    printf("Enter the height of the rectangle: ");  // Prompt the user to enter the height of the rectangle
    scanf("%lf", &height);  // Read the height from the user and store it in the 'height' variable

    // Calculate and print area of the rectangle
    double rectangleArea = width * height;  // Calculate the area of the rectangle
    printf("The area of the Rectangle is: %.2lf\n", rectangleArea);  // Print the area of the rectangle

    // Input for circle
    printf("Enter the radius of the circle: ");  // Prompt the user to enter the radius of the circle
    scanf("%lf", &radius);  // Read the radius from the user and store it in the 'radius' variable

    // Calculate and print area of the circle
    double circleArea = PI * radius * radius;  // Calculate the area of the circle
    printf("The area of the Circle is: %.2lf\n", circleArea);  // Print the area of the circle

    return 0;  // Return 0 to indicate successful completion of the program
}
