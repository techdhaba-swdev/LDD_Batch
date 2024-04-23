#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
typedef void(*RegisterFunc)(void);
typedef struct{
        RegisterFunc register_func;
        void(*callback_func)(int);
}Module;

void register_module(){
        printf("Module registered successfully!\n");
}       
void callback_function(int value){
        printf("Callback: Received value: %d\n", value);
}
