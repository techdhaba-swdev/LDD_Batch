#include <stdio.h>
int main() {
    char username[] = "admin";
    char password[] = "admin123";
    char input_username[50];
    char input_password[50];

    printf("Enter username: ");
    scanf("%s", input_username);
    printf("Enter password: ");
    scanf("%s", input_password);

    if (strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0) {
        printf("Login successful!\n");
    } else {
        printf("Login failed!\n");
    }

    return 0;
}
