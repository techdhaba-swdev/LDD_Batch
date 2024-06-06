#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

void celebrateBirthday(struct Person *p) {
    p->age += 1;
}

void printPerson(struct Person p) {
    printf("%s is now %d years old\n", p.name, p.age);
}

int main() {
    struct Person person1 = {"gojo", 25};
    celebrateBirthday(&person1); 
    printPerson(person1);
    return 0;
}
