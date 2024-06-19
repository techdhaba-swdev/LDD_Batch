/*KISS(KEEP IT SIMPLE,STUPID) STATES KEEP IT SIMPLE TO AVOID UNECCASRYCOMPLEXITY*/
#include <stdio.h>

int main() {
    int length, width, area, perimeter;

    // Prompt the user to enter the length and width of the rectangle
    printf("Enter the length of the rectangle: ");
    scanf("%d", &length);

    printf("Enter the width of the rectangle: ");
    scanf("%d", &width);

    // Calculate the area and perimeter
    area = length * width;
    perimeter = 2 * (length + width);

    // Print the results
    printf("Area: %d\n", area);
    printf("Perimeter: %d\n", perimeter);

    return 0;
}
