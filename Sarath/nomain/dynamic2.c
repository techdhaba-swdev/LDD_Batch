#include<stdio.h>
#include<dlfcn.h>
int main()
{
        void *lib_handle=dlopen("./add_sub.so",RTLD_LAZY);
        if(!lib_handle)
        {
                fprintf(stderr,"Error: %s\n",dlerror());
                return 1;
        }

        void (*add)()=dlsym(lib_handle,"add");
        if(!add){
                fprintf(stderr,"error : %s\n",dlerror());
                dlclose(lib_handle);
                return 1;
        }
	void (*sub)()=dlsym(lib_handle,"sub");
        if(!sub){
                fprintf(stderr,"error : %s\n",dlerror());
                dlclose(lib_handle);
                return 1;
        }
	void (*mul)()=dlsym(lib_handle,"mul");
	if(!mul){
		fprintf(stderr,"error: %s\n",dlerror());
		dlclose(lib_handle);
		return 1;
	}
	void (*Div)()=dlsym(lib_handle,"Div");
        if(!Div){
                fprintf(stderr,"error: %s\n",dlerror());
                dlclose(lib_handle);
                return 1;
        }

        add();
	sub();
	mul();
	Div();
        dlclose(lib_handle);
        return 0;
}

