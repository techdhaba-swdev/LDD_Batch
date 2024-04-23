#include<stdio.h>
#include<dlfcn.h>
#include<unistd.h>
//int main(){
/*        //load the shared library
       // void *lib_handle=dlopen("./dynamicaddsub.so",RTLD_LAZY);
       // if(!lib_handle){
           //     fprintf(stderr,"Error:%s\n",dlerror());
         //       return 1;
       // }
        //get a pointer to thefunction 
       // void(*hello_dynamic)()=dlsym(lib_handle,"hello_dynamic");
                //if(!hello_dynamic){
                      //  fprintf(stderr,"Error:%s\n",dlerror());
                    //    dlclose(lib_handle);
                  //      return 1;
                //}
                //call the function hello_dynamic();
              //  hello_dynamic();

                //close the library dlclose(lib_handle);
            //    dlclose(lib_handle);
          //      return 0;
}*/
int main(){
	void *lib_handle = dlopen("./dynamicaddsub.so",RTLD_LAZY);
	if(!lib_handle){
		fprintf(stderr,"Error: %s\n",dlerror());
		return 1;
	}
	int (*add)(int a,int b)=dlsym(lib_handle,"add");
	int (*sub)(int a,int b)=dlsym(lib_handle,"sub");
	int (*mul)(int a,int b)=dlsym(lib_handle,"mul");
        float (*div)(float a,float b)=dlsym(lib_handle,"div");

	int a=20,b=30;

	printf("addition: %d\n",libhandle.add(a,b));
        printf("subtractionn: %d\n",libhandle.sub(a,b));
        printf("multiplication: %d\n",libhandle.mul(a,b));
        printf("division: %.2f\n",libhandle.div(a,b));

	dlclose(lib_handle);
	return 0;
}



