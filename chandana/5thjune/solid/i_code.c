#include <stdio.h>

typedef struct {
    void (*printDocument)(void);
} Printer;

typedef struct {
    void (*scanDocument)(void);
} Scanner;

void printDocument() {
    printf("Printing document\n");
}

void scanDocument() {
    printf("Scanning document\n");
}

int main() {
    Printer printer = { printDocument };
    Scanner scanner = { scanDocument };

    printer.printDocument();
    scanner.scanDocument();

    return 0;

}
