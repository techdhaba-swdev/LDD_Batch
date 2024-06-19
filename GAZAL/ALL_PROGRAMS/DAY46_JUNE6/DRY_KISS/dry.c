/*DRY(DONT'T REPEAT YOURSELF ) principlesays that reduce repetition of code by using functions . So to achieve this we are using function to get dimensions from user and another function to calculate area ,perimeter and print result*/
#include <stdio.h>

// Function prototypes
int getInput();
int calculateArea(int length, int width);
int calculatePerimeter(int length, int width);
void printResult(const char* label, int value);

int main() {
    int length, width, area, perimeter;

    // Get inputs using the getInput function
    length = getInput();
    width = getInput();

    // Calculate area and perimeter using functions
    area = calculateArea(length, width);
    perimeter = calculatePerimeter(length, width);

    // Print results using the printResult function
    printResult("Area", area);
    printResult("Perimeter", perimeter);

    return 0;
}

// Function to get input
int getInput() {
    int num;
    printf("Enter a value: ");
    scanf("%d", &num);
    return num;
}

// Function to calculate the area of a rectangle
int calculateArea(int length, int width) {
    return length * width;
}

// Function to calculate the perimeter of a rectangle
int calculatePerimeter(int length, int width) {
    return 2 * (length + width);
}

// Function to print the result
void printResult(const char* label, int value) {
    printf("%s: %d\n", label, value);
}
