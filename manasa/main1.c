#include<stdio.h>
#include<dlfcn.h>
void main() {
	void* lib=dlopen("./example.so",RTLD_LAZY);
	if(!lib) {
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
	printf("addition: 10+12=%d\n",add(10,12));
	printf("subtract: 10-12=%d\n",sub(10,12));
	printf("multiply: 10*12=%d\n",mul(10,12));
	printf("division: 10/12=%.2f\n",div(10,12));
}



