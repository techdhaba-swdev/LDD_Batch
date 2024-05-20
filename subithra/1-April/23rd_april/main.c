#include <stdio.h>
#include <dlfcn.h>

int main() {
int num1=10;
int num2=5;
    void *lib_handle = dlopen("./example.so", RTLD_NOW;
    if (!lib_handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    int (*add)(int, int) = dlsym(lib_handle, "add");
    int (*sub)(int, int) = dlsym(lib_handle, "sub");
    int (*mul)(int, int) = dlsym(lib_handle, "mul");
    float (*div)(int, int) = dlsym(lib_handle, "div");

    
    if (!add || !sub || !mul || !div) {
        fprintf(stderr, "Error: %s\n", dlerror());
        
        return 1;
    }

    int result_add = add(num1,num2);
    int result_sub = sub(num1,num2);
    int result_multiply = mul(num1,num2);
    float result_division = div(num1,num2);
    printf("Addition result: %d\n", result_add);
    printf("Subtraction result: %d\n", result_sub);
    printf("Multiplication result: %d\n", result_multiply);
    printf("Division result: %.2f\n", result_division);

   }
