#include <stdio.h>

#define PI 3.14159

int main() {
    double radius = 5.0;
    double area = PI * radius * radius;
    
    printf("The area of a circle with radius %.2f is %.2f\n", radius, area);
    
    return 0;
}
