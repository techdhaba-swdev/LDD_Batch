#include<stdio.h>
#include<stlib.h>
#include<pthread.h>
#include<string.h>

typedef struct{
	const char* input;
	const char* output;
	int line;
}ThreadArgs;

pthread_mutex_t file=PTHREAD_MUTEX_INITIALIZER;

void* proceed(void* arg){
	Threadargs* args=(Threadargs*)arg;
	FILE* inputfile=fopen(args->input,"r");
	if(inputfile==NULL){
		perror("error");
		pthread_exit(NULL);
	}
	FILE* outputfile = fopen(args->output,"w");
	 if(outputfile==NULL){
                perror("error");
		fclose(inputfile);
                pthread_exit(NULL);
		
        }
	 char buffer[256];

	 int linenum = 1;
	 whillle(fgets(buffer,sizeof(buffer),inputfile)){
		 pthread_mutex_lock(&file);
		 if((linenum %2 == 0 && args-.line ==0) || (linenum % 2 != && args->line ==1)){
			 fputs(buffer,outputfile);
		 }
		 linenum++;
		 pthread_mutex_unlock(&file);
	 }
	 fclose(inputfile);
	 fclose(outputfile);
	 pthread_exit(NULL);
}
void readwrite(void* arg){
	const char* output = (const char*)arg;
       FILE* outputfile = fopen(outputfile == NULL){
	      perror("error");

	     pthread_exit(NULL);
       }
      char buffer[256];
     while(fgets(buffer,sizeof(buffer),outputfile)){
	     printf("%s",buffer);
     }
     fclose(outputfile);
     pthread_exit(NULL);
}
int main(int argc,char* argv[]){
	if(args != 4){
		fprintf(stderr,"%s"argv[0]);
		return EXIT_FAILURE;
	}
	const char* input=argv[1];
	const char* evenoutput=args[2];
	const char* oddoutput=argv[3];
	
