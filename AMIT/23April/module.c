#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

// Define the function signature for registration functions
typedef void (*RegisterFunc)(void);

// Define a structure to hold function pointers
typedef struct {
    RegisterFunc register_func;
    void (*callback_func)(int);
} Module;

// Registration function
void register_module() {
    printf("Module registered successfully!\n");
}

// Callback function
void callback_function(int value) {
    printf("Callback: Received value: %d\n", value);
}

