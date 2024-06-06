#include <stdio.h>

int main() {
    struct {
        char name[50];
        int age;
    } person1 = {"Doremon", 15}, person2 = {"nobita", 10};

    
    person1.age += 1;
    printf("%s is now %d years old.\n", person1.name, person1.age);

   
    person2.age += 1;
    printf("%s is now %d years old\n", person2.name, person2.age);

    return 0;
}
