#include <stdio.h>
#include <dlfcn.h>

int main() {
void* handle = dlopen("./dynamic.so", RTLD_NOW);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }
   
void (*hello_func)();
    *(void **) (&hello_func) = dlsym(handle, "hello_dynamic");
    if (!hello_func) {
        fprintf(stderr, "%s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    
    int (*add)(int,int) = dlsym(handle, "add");
    int (*sub)(int,int) = dlsym(handle, "sub");
    float (*mul)(float,float) = dlsym(handle, "mul");
    float (*div)(float,float) = dlsym(handle, "divide");

    int a= 20, b=5;

    printf("Addition: %d\n", add(a,b));
     printf("Subtraction: %d\n", sub(a,b));
      printf("Multiply: %d\n", mul(a,b));
       printf("Division: %d\n", div(a,b));

    dlclose(handle);

    return 0;
}
