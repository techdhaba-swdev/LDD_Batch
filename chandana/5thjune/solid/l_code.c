#include <stdio.h>

typedef struct {
    void (*fly)(void);
} Bird;

void flyBird() {
    printf("Bird is flying\n");
}

void flySparrow() {
    printf("Sparrow is flying\n");
}

void flyOstrich() {
    printf("Ostrich cannot fly, it is walking\n");
}

void makeBirdFly(const Bird* bird) {
    bird->fly();
}

int main() {
    Bird sparrow = { flySparrow };
    Bird ostrich = { flyOstrich };

    makeBirdFly(&sparrow);
    makeBirdFly(&ostrich);

    return 0;
}
