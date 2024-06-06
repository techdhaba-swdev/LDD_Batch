
#include <stdio.h>
#include <dlfcn.h>

int main() {
    
    void *lib_handle = dlopen("./libexample.so", RTLD_LAZY);
    if (!lib_handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    
     int (*add)(int,int) = dlsym(lib_handle, "add");
     int (*sub)(int,int) = dlsym(lib_handle, "sub");
     float (*mul)(float,float) = dlsym(lib_handle, "mul");
      float (*div)(float,float) = dlsym(lib_handle, "divide");

      int a = 20, b = 4;

      printf("Addition: %d\n", add(a,b));
      printf("Subtraction: %d\n", sub(a,b));
      printf("Multiply: %2f\n", mul(a,b));
      printf("Divison: %.2f\n", div(a,b));




    
    dlclose(lib_handle);

    return 0;
}


