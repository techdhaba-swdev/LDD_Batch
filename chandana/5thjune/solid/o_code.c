#include <stdio.h>

typedef struct {
    void (*draw)(void);
} Shape;

void drawCircle() {
    printf("Drawing Circle\n");
}

void drawSquare() {
    printf("Drawing Square\n");
}

int main() {
    Shape circle = { drawCircle };
    Shape square = { drawSquare };

    Shape shapes[] = { circle, square };
    for (int i = 0; i < 2; ++i) {
        shapes[i].draw();
    }

    return 0;
}

