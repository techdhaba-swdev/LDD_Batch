#include<stdio.h>
#include<dlfcn.h>

void main()
{
	void *lib_handle= dlopen("./calculation.so",RTLD_LAZY);
	if(!lib_handle)
	{
		fprintf(stderr,"%s",dlerror());
	}

	int (*add)(int, int)= dlsym(lib_handle,"add");
	if(!add)
        {
                fprintf(stderr,"%s",dlerror());
        }

	 int (*sub)(int, int)= dlsym(lib_handle,"sub");
        if(!sub)
        {
                fprintf(stderr,"%s",dlerror());
        }

	 int (*mul)(int, int)= dlsym(lib_handle,"mul");
        if(!mul)
        {
                fprintf(stderr,"%s",dlerror());
        }

	 float (*div)(int, int)= dlsym(lib_handle,"div");
        if(!add)
        {
                fprintf(stderr,"%s",dlerror());
        }

	printf("\tAddition:%d\n",add(12,6));
	printf("\tSubstarction:%d\n",sub(12,6));
	printf("\tMultiplication:%d\n",mul(12,6));
	printf("\tDivision:%.2f\n",div(43,3));
}


             

