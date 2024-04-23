#include<stdio.h>
#include<dlfcn.h>
void main(){

//gcc -shared -fPIC -o exmaple.so div.c add.c 
void* lib= dlopen("./example.so",RTLD_LAZY);
if (!lib){
fprintf(stderr,"%s",dlerror());

}

int (*add)(int,int)=dlsym(lib,"add");
if (!add)
{
fprintf(stderr,"%s",dlerror());

}

int (*sub)(int,int)=dlsym(lib,"sub");
if (!add)
{
fprintf(stderr,"%s",dlerror());

}


int (*mul)(int,int)=dlsym(lib,"mul");
if (!add)
{
fprintf(stderr,"%s",dlerror());

}

float (*div)(int,int)=dlsym(lib,"div");
if (!add)
{
fprintf(stderr,"%s",dlerror());

}


printf("addition: 10+10=%d\n",add(10,10));

printf("substraction: 10-10=%d\n",sub(10,10));
printf("multiple: 10*10=%d\n",mul(10,10));
printf("division: 10/10=%.2f\n",div(10,10));

}
