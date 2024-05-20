// main.c
#include <stdio.h>
#include <dlfcn.h>

int main() {
int num1=10;
int num2=5;
    void *lib_handle = dlopen("./libexample1.so", RTLD_LAZY);
    if (!lib_handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    
    void (*hello_dynamic)() = dlsym(lib_handle, "hello_dynamic");
    int (*add)(int, int) = dlsym(lib_handle, "add");
    int (*sub)(int, int) = dlsym(lib_handle, "sub");
    int (*multiply)(int, int) = dlsym(lib_handle, "multiply");
    float (*division)(int, int) = dlsym(lib_handle, "division");

    
    if (!hello_dynamic || !add || !sub || !multiply || !division) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(lib_handle);
        return 1;
    }

   
    hello_dynamic();
    int result_add = add(num1,num2);
    int result_sub = sub(num1,num2);
    int result_multiply = multiply(num1,num2);
    float result_division = division(num1,num2);
    printf("Addition result: %d\n", result_add);
    printf("Subtraction result: %d\n", result_sub);
    printf("Multiplication result: %d\n", result_multiply);
    printf("Division result: %.2f\n", result_division);

    
    dlclose(lib_handle);

    return 0;
}
