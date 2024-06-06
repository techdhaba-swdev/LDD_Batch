#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

void printPerson(struct Person p) {
    printf("%s is %d years old.\n", p.name, p.age);
}

int main() {
    struct Person person1 = {"Alice", 30};
    printPerson(person1);
    return 0;
}


