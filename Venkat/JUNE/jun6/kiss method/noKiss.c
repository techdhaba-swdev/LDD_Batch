#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

void initPerson(Person *p, const char *name, int age) {
    strncpy(p->name, name, sizeof(p->name) - 1);
    p->name[sizeof(p->name) - 1] = '\0';
    p->age = age;
}

void printPerson(const Person *p) {
    printf("Person Details:\n");
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
   
}

int main() {
    Person person1;
    initPerson(&person1, "thorfin", 18);
    printPerson(&person1);
    return 0;
}
